#!/bin/bash

resetup() {
	rm -rf f*
	touch fx fy fz
	touch f000-1; chmod 000 f000-1
	touch f000-2; chmod 000 f000-2
	touch f000-3; chmod 000 f000-3
	touch f222-1; chmod 222 f222-1
	touch f222-2; chmod 222 f222-2
	touch f222-3; chmod 222 f222-3
	touch f444-1; chmod 444 f444-1
	touch f444-2; chmod 444 f444-2
	touch f444-3; chmod 444 f444-3
	touch f644-1; chmod 644 f644-1
	touch f644-2; chmod 644 f644-2
	touch f644-3; chmod 644 f644-3
}

asu() {
	out=$(cat fx)
	echo -e "\033[31m\033[2m$out\033[0m"
	echo -e "[\033[32mSUCCESS\033[0m] $1"
	# echo -e "[\033[31m ERROR \033[0m] $1"
}

msgbox() {
	local msg=$1
	local len=$((${#msg} + 2))
	if [[ "$2" == "KEY" ]]; then
		# To read into variables, in bash
		echo -e "\033[35mPress any key to continue\033[0m"
		read -n 1 -s -r -p ""
		clear
		read -r rows cols < <(stty size)
	fi
	echo
	for ((i = 0; i < $len; i++)); do
		echo -n "="
	done
	echo -e "\n $msg"
	for ((i = 0; i < $len; i++)); do
		echo -n "="
	done
	echo
}

same() {
	## TEST OFF
	if [[ "$4" == "OFF" ]]; then
		echo -e "[\033[33mDISABLE\033[0m] $1"
		echo "================="
		return
	fi
	## STDERROR
	out=$(cat fx)
	out2=$(cat fy)
	out3=$(cat fz)
	if notemptyfile fx; then
		echo -e "\033[31m\033[2m$out\033[0m"
	fi
	if notemptyfile fy; then
		echo -e "\033[2m$out2\033[0m"
	fi
	if notemptyfile fz; then
		echo -e "\033[2m$out3\033[0m"
	fi
	rm fx fy fz
	## DIFF
	DIFF=$(diff $2 $3) 
	if [ "$DIFF" != "" ]; then
		echo -e "[\033[31m ERROR \033[0m] $1"
		diff $2 $3
	else
		echo -e "[\033[32mSUCCESS\033[0m] $1"
	fi
	echo
	## RESET FILES TEST
	resetup
}

notemptyfile() {
	if [[ 0 -ne $(wc -c "${1}" | awk '{print $1}') ]]; then
		return 0
	else
		return 1
	fi
}

emptyfile() {
	if [[ 0 -eq $(wc -c "${1}" | awk '{print $1}') ]]; then
		echo -e "=== ${d}:${ds} \033[32mOK\033[0m === ${msg}"
	else
		echo "not empty"
	fi
}

log() {
	local msg=$1
	local d=$(date +%T)
	local ds=$(date +%2N)
	if [[ "$rcode" == "0" ]]; then
		echo -e "=== ${d}:${ds} \033[32m$rcode\033[0m === ${msg}"
	else
		echo -e "=== ${d}:${ds} \033[31m$rcode\033[0m === ${msg}"
	fi
}


#
msgbox "TEST SETUP" KEY
make -C ../; rcode=$?; log "make -C ../"
cp ../pipex .; rcode=$?; log "clone pipex"
touch f000-1; chmod 000 f000-1; rcode=$?; log "create file:'f000-1' no perm"
touch f000-2; chmod 000 f000-2; rcode=$?; log "create file:'f000-2' no perm"
touch f000-3; chmod 000 f000-3; rcode=$?; log "create file:'f000-3' no perm"
touch f222-1; chmod 222 f222-1; rcode=$?; log "create file:'f222-1' wr perm"
touch f222-2; chmod 222 f222-2; rcode=$?; log "create file:'f222-2' wr perm"
touch f222-3; chmod 222 f222-3; rcode=$?; log "create file:'f222-3' wr perm"
touch f444-1; chmod 444 f444-1; rcode=$?; log "create file:'f444-1' rd perm"
touch f444-2; chmod 444 f444-2; rcode=$?; log "create file:'f444-2' rd perm"
touch f444-3; chmod 444 f444-3; rcode=$?; log "create file:'f444-3' rd perm"
touch f644-1; chmod 644 f644-1; rcode=$?; log "create file:'f644-1' df perm"
touch f644-2; chmod 644 f644-2; rcode=$?; log "create file:'f644-2' std perm"
touch f644-3; chmod 644 f644-3; rcode=$?; log "create file:'f644-3' std perm"
echo > f000; rcode=$?; log "echo > f000 without perm"
echo > f444; rcode=$?; log "echo > f444 read only perm"
echo > f222; rcode=$?; log "echo > f222 write only perm"
echo > f644-1; rcode=$?; log "echo > f644-1 default perm"
nonexistant-command; rcode=$?; log "nonexistant-command"
echo -e "[\033[32m   OK   \033[0m] $1"
./nonexistant-program; rcode=$?; log "./nonexistant-program"
echo -e "[\033[32m   OK   \033[0m] $1"

msgbox "VALID TESTS"
#TEST 1
./pipex f644-1 cat uname f644-2 2> fx; rcode=$?
log "./pipex f644-1 cat uname f644-2"
< f644-1 cat 2> fy | uname > f644-3 2> fz; rcode=$?
log " < f644-1 cat | uname > f644-3"
same 1 f644-2 f644-3
#TEST 2
./pipex f644-1 date cat f644-2 2> fx; rcode=$?
log "./pipex f644-1 date cat f644-2"
< f644-1 date 2> fy | cat > f644-3 2> fz; rcode=$?
log " < f644-1 date | cat > f644-3"
same 2 f644-2 f644-3
#TEST 3
./pipex f644-1 "date +%T" cat f644-2 2> fx; rcode=$?
log './pipex f644-1 "date +%T" cat f644-2'
< f644-1 date +%T 2> fy | cat > f644-3 2> fz; rcode=$?
log " < f644-1 date +%T | cat > f644-3"
same 3 f644-2 f644-3
#TEST 4
echo hello > f644-1
./pipex f644-1 cat cat f644-2 2> fx; rcode=$?
log './pipex f644-1 cat cat f644-2'
< f644-1 cat 2>fy | cat > f644-3 2> fz; rcode=$?
log " < f644-1 cat | cat > f644-3"
same 4 f644-2 f644-3
#TEST 5
echo hello > f644-1
./pipex f644-1 cat wc f644-2 2> fx; rcode=$?
log './pipex f644-1 cat wc f644-2'
< f644-1 cat 2> fy | wc > f644-3 2> fz; rcode=$?
log " < f644-1 cat | wc > f644-3"
same 5 f644-2 f644-3
#TEST 6
echo hello > f644-1
./pipex f644-1 cat wc f644-4 2> fx; rcode=$?
log './pipex f644-1 cat wc f644-4'
< f644-1 cat 2> fy | wc > f644-5 2> fz; rcode=$?
log " < f644-1 cat | wc > f644-5"
same 6 f644-4 f644-5

msgbox "EMPTY PATH TESTS" KEY
#TEST 10
TMP=$PATH;
PATH=0; ./pipex f644-1 cat wc f644-4 2> fx; rcode=$?
PATH=$TMP; log 'PATH=0; ./pipex f644-1 cat wc f644-4'
PATH=0; < f644-1 cat 2> fy | wc > f644-5 2> fz; rcode=$?;
PATH=$TMP; log "PATH=0; < f644-1 cat | wc > f644-5"
same 10 f644-4 f644-5
#TEST 11
TMP=$PATH;
env -i ./pipex f644-1 cat wc f644-4 2> fx; rcode=$?
log 'env -i ./pipex f644-1 cat wc f644-4'
PATH=; < f644-1 cat 2> fy | wc > f644-5 2> fz; rcode=$?;
PATH=$TMP; log "PATH=; < f644-1 cat | wc > f644-5"
same 11 f644-4 f644-5
#TEST 12
TMP=$PATH;
env --unset=PATH ./pipex f644-1 cat wc f644-4 2> fx; rcode=$?
log 'env --unset=PATH ./pipex f644-1 cat wc f644-4'
PATH=; < f644-1 cat 2> fy | wc > f644-5 2> fz; rcode=$?;
PATH=$TMP; log "PATH=; < f644-1 cat | wc > f644-5"
same 12 f644-4 f644-5
#TEST 13
TMP=$PATH;
unset PATH; ./pipex f644-1 cat wc f644-4 2> fx; rcode=$?
PATH=$TMP; log 'unset PATH; ./pipex f644-1 cat wc f644-4'
unset PATH; < f644-1 cat 2> fy | wc > f644-5 2> fz; rcode=$?;
PATH=$TMP; log 'unset PATH; < f644-1 cat | wc > f644-5'
same 13 f644-4 f644-5
#TEST 14
TMP=$PATH;
PATH=; ./pipex f644-1 cat wc f644-4 2> fx; rcode=$?
PATH=$TMP; log 'PATH=; ./pipex f644-1 cat wc f644-4'
PATH=; < f644-1 cat 2> fy | wc > f644-5 2> fz; rcode=$?;
PATH=$TMP; log "PATH=; < f644-1 cat | wc > f644-5"
same 14 f644-4 f644-5

msgbox "INVALID ARG NUMBER TESTS" KEY
#TEST 20
./pipex 2> fx; rcode=$?; log "./pipex (no args)"
asu 20
#TEST 21
./pipex 1 2 3 2> fx; rcode=$?; log "./pipex 1 2 3"
asu 21
#TEST 22
./pipex f1 2 3 4 f5 2> fx; rcode=$?; log "./pipex f1 2 3 4 f5"
asu 22
#TEST 23
./pipex abc 2> fx; rcode=$?; log "./pipex abc"
asu 23

msgbox "COMMANDS'S PERMISSIONS TESTS"
#TEST 30
chmod -x prog_cow
./pipex f644-1 ls ./prog_cow f644-4 2> fx; rcode=$?
log './pipex f644-1 ls ./prog_cow f664-4'
< f644-1 ls 2> fy | ./prog_cow > f644-5 2> fz; rcode=$?
log '< f644-1 ls | ./prog_cow > f644-5'
same 30 f644-4 f644-5
chmod +x prog_cow
#TEST 31
chmod 644 prog_cow
./pipex f644-1 ls ./prog_cow f644-4 2> fx; rcode=$?
log './pipex f644-1 ls ./prog_cow f664-4'
< f644-1 ls 2> fy | ./prog_cow > f644-5 2> fz; rcode=$?
log '< f644-1 ls | ./prog_cow > f644-5'
same 31 f644-4 f644-5
chmod 755 prog_cow

msgbox "FILES'S PERMISSIONS TESTS"
#TEST 40
./pipex f000-1 cat uname f000-2 2> fx; rcode=$?
log "./pipex f000-1 cat uname f000-2"
< f000-1 cat 2> fy | uname > f000-3 2> fz; rcode=$?
log " < f000-1 cat | uname > f000-3"
chmod 777 f000-2 f000-3
same 40 f000-2 f000-3
#TEST 41
./pipex f000-1 cat uname f444-2 2> fx; rcode=$?
log "./pipex f000-1 cat uname f444-2"
< f000-1 cat 2> fy | uname > f444-3 2> fz; rcode=$?
log " < f000-1 cat | uname > f444-3"
same 41 f444-2 f444-3
#TEST 42
./pipex f222-1 cat uname f444-2 2> fx; rcode=$?
log "./pipex f222-1 cat uname f444-2"
< f222-1 cat 2> fy | uname > f444-3 2> fz; rcode=$?
log " < f222-1 cat | uname > f444-3"
same 42 f444-2 f444-3
#TEST 43
./pipex f444-1 cat uname f000-2 2> fx; rcode=$?
log "./pipex f444-1 cat uname f000-2"
< f444-1 cat 2> fy | uname > f000-3 2> fz; rcode=$?
log " < f444-1 cat | uname > f000-3"
chmod 777 f000-2 f000-3
same 43 f000-2 f000-3
#TEST 44
./pipex f444-1 cat uname f444-2 2> fx; rcode=$?
log "./pipex f444-1 cat uname f444-2"
< f444-1 cat 2> fy | uname > f444-3 2> fz; rcode=$?
log " < f444-1 cat | uname > f444-3"
same 44 f444-2 f444-3
<< 'TEST-ERROR-BKP'
#TEST 45
./pipex f444-1 "cat" "uname" f222-2 2> fx; rcode=$?
log "./pipex f444-1 cat uname f222-2"
< f444-1 cat 2> fy | uname > f222-3 2> fz; rcode=$?
log " < f444-1 cat | uname > f222-3"
chmod 777 f222-2 f222-3
same 45 f222-2 f222-3
#TEST 46
./pipex f000-1 cat uname f222-2 2> fx; rcode=$?
log "./pipex f000-1 cat uname f222-2"
< f000-1 cat 2> fy | uname > f222-3 2> fz; rcode=$?
log " < f000-1 cat | uname > f222-3"
chmod 777 f222-2 f222-3
same 46 f222-2 f222-3
#TEST 47
./pipex f000-1 cat uname f644-2 2> fx; rcode=$?
log "./pipex f000-1 cat uname f644-2"
< f000-1 cat 2> fy | uname > f644-3 2> fz; rcode=$?
log " < f000-1 cat | uname > f644-3"
same 47 f644-2 f644-3
#TEST 48
./pipex f222-1 cat uname f222-2 2> fx; rcode=$?
log "./pipex f222-1 cat uname f222-2"
< f222-1 cat 2> fy | uname > f222-3 2> fz; rcode=$?
log " < f222-1 cat | uname > f222-3"
chmod 777 f222-2 f222-3
same 48 f222-2 f222-3
#TEST 49
./pipex f222-1 cat uname f644-2 2> fx; rcode=$?
log "./pipex f222-1 cat uname f644-2"
< f222-1 cat 2> fy | uname > f644-3 2> fz; rcode=$?
log " < f222-1 cat | uname > f644-3"
same 49 f644-2 f644-3
TEST-ERROR-BKP

msgbox "CURRENT PATH CMD TESTS" KEY
#TEST 50
./pipex f644-1 "./pipex" cat f644-4 2> fx; rcode=$?
log './pipex f644-1 "./pipex" cat f664-4'
< f644-1 ./pipex 2> fy | cat > f644-5 2> fz; rcode=$?
log '< f644-1 ./pipex | cat > f644-5'
same 50 f644-4 f644-5
#TEST 51
./pipex f644-1 cat pipex f644-4 2> fx; rcode=$?
log './pipex f644-1 cat pipex f664-4'
< f644-1 cat 2> fy | pipex > f644-5 2> fz; rcode=$?
log '< f644-1 pipex | cat > f644-5'
same 51 f644-4 f644-5
#TEST 52
./pipex f644-1 ../bashtest/pipex cat f644-4 2> fx; rcode=$?
log './pipex f644-1 ../bashtest/pipex cat f664-4'
< f644-1 ../bashtest/pipex 2> fy | cat > f644-5 2> fz; rcode=$?
log '< f644-1 ../bashtest/pipex | cat > f644-5'
same 52 f644-4 f644-5
#TEST 53
./pipex f644-1 date pipex f644-4 2> fx; rcode=$?
log './pipex f644-1 date pipex f664-4'
< f644-1 date 2> fy | pipex > f644-5 2> fz; rcode=$?
log '< f644-1 date | pipex > f644-5'
same 53 f644-4 f644-5
#TEST 54
./pipex f644-1 date ./prog_cow f644-4 2> fx; rcode=$?
log './pipex f644-1 date ./prog_cow f664-4'
< f644-1 date 2> fy | ./prog_cow > f644-5 2> fz; rcode=$?
log '< f644-1 date | ./prog_cow > f644-5'
same 54 f644-4 f644-5
#TEST 55
./pipex f644-1 ./date ./pop f644-4 2> fx; rcode=$?
log './pipex f644-1 ./date ./pop f664-4'
< f644-1 ./date 2> fy | ./pop > f644-5 2> fz; rcode=$?
log '< f644-1 ./date | ./pop > f644-5'
same 55 f644-4 f644-5

msgbox "NO INPUT FILE TESTS"
#TEST 60
./pipex noinput "date +%T" wc f000-2 2> fx; rcode=$?
log './pipex noinput "date +%T" wc f000-2'
< noinput date +%T 2> fy | wc > f000-3 2> fz; rcode=$?
log " < noinput date +%T | wc > f000-3"
chmod 777 f000-2 f000-3
same 60 f000-2 f000-3
#TEST 61
./pipex noinput "date +%T" cat f644-4 2> fx; rcode=$?
log './pipex noinput "date +%T" cat f644-4'
< noinput date +%T 2> fy | cat > f644-5 2> fz; rcode=$?
log " < noinput date +%T | cat > f644-5"
same 61 f644-4 f644-5

###
msgbox "DELETING FILES - END OF PIPEX TESTS"
make fclean -C ../; rcode=$?; log "make -C fclean ../"
rm pipex; rcode=$?; log "rm pipex"
rm -rf f*; rcode=$?; log "rm -rf f*"
