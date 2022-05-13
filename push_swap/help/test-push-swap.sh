#!/bin/bash
cb="\e[1;34m   > \e[0;34m"
cy="\e[0;33m"
cy1="\e[1;33m"
cg="\e[0;32m"
cm="\e[0;35m"
cm1="\e[1;35m"
cw1="\e[1;37m"
r="\e[0m"
#
# --leak-check=full: "each individual leak will be shown in detail"
# --show-leak-kinds=all: Show all of "definite, indirect, possible, reachable" leak kinds in the "full" report.
# --track-origins=yes: Favor useful output over speed. This tracks the origins of uninitialized values, which could be very useful for memory errors. Consider turning off if Valgrind is unacceptably slow.
#

function pause(){
 echo -e "\e[1m${cm1}${1}"
 read -s -n 1 -p "Press any key to start..."
 echo -e "${r}"
}

test() {
	id=$(echo ${@} | tr ' ' '-')
	#fo=logs/log_${id}.log
	fo=logs/log_${id:0:10}.log
	echo -e "${cb} > push_swap ${@}${r}"
	valgrind	--leak-check=full \
         		--show-leak-kinds=all \
         		--track-origins=yes \
         		./push_swap "$@" 2>  $fo
	echo -ne ${cm}
	nl=$(cat $fo | wc -l)
	if (( ${nl} != 14 )); then
		echo -ne ${cy}
		cat $fo | grep "definitely lost"
		cat $fo | grep "indirectly lost"
		cat $fo | grep "possibly lost"
		cat $fo | grep "still reachable:"
		cat $fo | grep "supressed"
		echo $(cat $fo | grep "use at exit" | sed 's/.*use at //')
		echo $(cat $fo | grep " heap usage" | sed 's/.*total //')
		cat $fo | grep " ERROR SUMM" | sed 's/.*= //'
		echo -e ${r}
	else
		echo -e "${cg} LEAKS OK${r}" 
	fi
}

error() {
	pause "Error cases checking : invalid arg"
# errror invalid arg
	test a b c
	test 1 2 3 k
	test 1 - 2 4 5 6 3
	test 1 -59 2+ 4 5 6- 3
	test 1 + 2 4 5 6 3
	test 1 -2 4 5 6 - 3
	test 1 +2 4 5 6 "+ " 3
	test 1 +2 4 5 6 + 3
	test " 1" "2 " " 3 " "  4" "5  "
	test " 1" "-" "2 " " 3 " "  4" "5  "
	test " 1" "+" "2 " " 3 " "  4" "5  "
	test " 1" "-0" "2 " " 3 " "  4" "5  " "0"
	test " 1" "+ " "2 " " 3 " "  4" "5  " "+6"
	test 1a 2
	test 4 5 3b 6 7
	test 40 0jk 22
	test "\t" "\n" "                           "
	test "                      1                    "
	test 10 9787987979879798787987 11214748364s92147483649
	test 10 -898098908098 325 599 599 599 599 112147a
	pause "Error cases checking : no arg"
# eror malloc failed
	test
	pause "Error cases checking : no integer"
# error no integer
	test 2147483648 22
	test 11 12 13 -2147483649
	test -21474836480 10 
	test 10 12147483649
	test 10 34 893289 898 83 1214742083649 1
	pause "Error cases checking : no distinct"
# error no distinct
	test 0 -0
	test +0 -0
	test 1 -1 +1
	test 1 -1 2 4 0 4 
	test 34 33 31 30 32 34
	test 28 28
}

s1() {
	pause "1 arg checking"
	test -22
	test -0
	test +42
	test 420
}

s2() {
	pause "2 args checking"
	test 0 -1
	test 1 0
	test 1 2
	test 3 1
}

s3() {
	pause "3 args checking"
	test 1 2 3
	test 1 3 2
	test 2 1 3
	test 2 3 1
	test 3 1 2
	test 3 2 1
}

s4() {
	pause "4 args checking"
	test 1 2 3 4
	test 1 2 4 3
	test 1 3 2 4
	test 1 3 4 2
	test 1 4 2 3
	test 1 4 3 2
	#
	test 2 1 3 4
	test 2 1 4 3
	test 2 3 1 4
	test 2 3 4 1
	test 2 4 1 3
	test 2 4 3 1
	#
	test 3 1 2 4
	test 3 1 4 2
	test 3 2 1 4
	test 3 2 4 1
	test 3 4 1 2
	test 3 4 2 1
	#
	test 4 1 2 3
	test 4 1 3 2
	test 4 2 1 3
	test 4 2 3 1
	test 4 3 1 2
	test 4 3 2 1
}

s5() {
	pause "5 args checking"
	test 1 2 3 4 0
	test 1 2 4 3 0
	test 1 3 2 4 0
	test 1 3 4 2 0
	test 1 4 2 3 0
	test 1 4 3 2 0
	#
	test 2 1 3 4 0
	test 2 1 4 3 0
	test 2 3 1 4 0
	test 2 3 4 1 0
	test 2 4 1 3 0
	test 2 4 3 1 0
	#
	test 3 1 2 4 0
	test 3 1 4 2 0
	test 3 2 1 4 0
	test 3 2 4 1 0
	test 3 4 1 2 0
	test 3 4 2 1 0
	#
	test 4 1 2 3 0
	test 4 1 3 2 0
	test 4 2 1 3 0
	test 4 2 3 1 0
	test 4 3 1 2 0
	test 4 3 2 1 0
	#
	test 1 2 3 4 5
	test 1 2 4 3 5
	test 1 3 2 4 5
	test 1 3 4 2 5
	test 1 4 2 3 5
	test 1 4 3 2 5
	#
	test 2 1 3 4 5
	test 2 1 4 3 5
	test 2 3 1 4 5
	test 2 3 4 1 5
	test 2 4 1 3 5
	test 2 4 3 1 5
	#
	test 3 1 2 4 5
	test 3 1 4 2 5
	test 3 2 1 4 5
	test 3 2 4 1 5
	test 3 4 1 2 5
	test 3 4 2 1 5
	#
	test 4 1 2 3 5
	test 4 1 3 2 5
	test 4 2 1 3 5
	test 4 2 3 1 5
	test 4 3 1 2 5
	test 4 3 2 1 5
}
##############################

validone() {
	pause "valid check 1"
	test "1" "2" "3" "5" "4"
	test "1" "-1"
	test "1" +42 "-1"
	test "1" 2 "-1"
	test -2147483648 12 20
	test -2147483647 11
	test 42 2147483647 2345889
	test 41 2147483646
	test 21 62 12
	test 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
	test 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 0
	test 1 -2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 0
}

valid2() {
	pause "valid check 2"
	test -1 2
	test 34 2
	test 1 2
	test -21 12 20 5 67 3 -1 -12 0
	test 42 47 89 2 3 4
	test 41 -7 1 9 8 7 0 4 +34 -56
	test 21 62 12
	test 1 2 0 16 
	test 1 2 17 16 
	test 1 22 17 16 
	test -34 -33 -30 -1 0 1 2 34 35 300
	test 42
	test 100 1 2 3 4 5 6 7 8 9 -1 -2 -3 0 -8
	test 2 1
	test -34 -89
	test 12 -3
	test 3 1 2
	test 58 23 -78
}

valid3() {
	pause "valid check 3"
	test 2 1 3 4
	test 2 1 17 16 12 22
	test 0 2 1 17 16
	test 0 2 3 4 1 17 16 29 31
	test 0 2 16 8 
	test 4 3 2 -1 1 5
	test -21 12 20 5 67 3 -1 -12 0
	test 41 -7 1 9 8 7 0 4 +34 -56 78
	test 100 1 2 3 4 5 6 7 8 9 -1 -2 -3 0 -8
}

valid4() {
	pause "valid check 4"
	test 100 1 2 3 4 5 6 7 -22 8 9 -1 -2 -3 0 -8
	test 100 -42 1 2 3 4 5 6 7 -22 8 9 -1 -2 -3 0 -8
	test 100 42 1 2 3 4 5 6 7 -22 23 25 8 9 -2 -3 0 -8
	test 100 908 374 894 984 42 1 2 3 4 5 6 7 -22 23 25 898989 9 -2 -3 0 -8
	test 12 0 1 2 52 41 3 6 18 13
	test 2 1 17 16 12 22
	test 0 2 1 17 16
	test 0 2 3 4 1 17 16 29 31
	test 0 2 16 8 
	test 4 3 2 -1 1 5
	test -21 12 20 5 6 9 3 -1 -12 0
}

valid5(){
	pause "valid check 5"
	test 8 7 9 10 2 3 5 6 4 1
	test 10 3 2 8 4 5 1 6 9 7
	test 6 2 3 4 5 1
	test 3 9 7 5 8 2 6 10 4 1
	test 2 12 8 5 13 3 11 1 10 14 6 4 7 9
	test 6 5 2 8 10 9 1 7 3 4
	test 13 5 7 11 10 9 8 1 12 3 14 6 2 4
	test 3 4 7 13 8 5 11 10 14 12 6 2 9 1
}

randomtest(){
	pause "random test"
	ARG=`ruby -e "puts (1..10).to_a.shuffle.join(' ')"`;
	test $ARG
	ARG=`ruby -e "puts (1..9).to_a.shuffle.join(' ')"`;
	test $ARG
	ARG=`ruby -e "puts (-1..6).to_a.shuffle.join(' ')"`;
	test $ARG
	ARG=`ruby -e "puts (-1..19).to_a.shuffle.join(' ')"`;
	test $ARG
	ARG=`ruby -e "puts (-1..3).to_a.shuffle.join(' ')"`;
	test $ARG
	ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`;
	test $ARG
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`;
	test $ARG
	ARG=`ruby -e "puts (0..101).to_a.shuffle.join(' ')"`;
	test $ARG
	ARG=`ruby -e "puts (-34..-2).to_a.shuffle.join(' ')"`;
	test $ARG
	ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`;
	test $ARG
}
tc5(){
	echo
	echo -e "${cm1}push_swap count test with 5 random elements${r}"
	for (( i = 0; i < 20; i++ ))
	do
		ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`;
		NEL=$(echo -n $ARG | tr ' ' '\n' | wc -l)
		echo -ne "${cb}$NEL : ${r}"
		./push_swap $ARG | wc -l
	done
}

tc100(){
	echo
	echo -e "${cm1}push_swap count test with 100 random elements${r}"
	for (( i = 0; i < 20; i++ ))
	do
		ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`;
		NEL=$(echo -n $ARG | tr ' ' '\n' | wc -l)
		echo -ne "${cb}$NEL : ${r}"
		./push_swap $ARG | wc -l
	done
}

tc500(){
	echo
	echo -e "${cm1}push_swap count test with 500 random elements${r}"
	for (( i = 0; i < 20; i++ ))
	do
		ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`;
		NEL=$(echo -n $ARG | tr ' ' '\n' | wc -l)
		echo -ne "${cb}$NEL : ${r}"
		./push_swap $ARG | wc -l
	done
}

special(){
	pause "special cases test"
	echo 'ARG="-1"; ./push_swap -1'
	ARG="-1"; ./push_swap $ARG
	echo -e "${cg}one element or already soorted${r}"
	echo
	echo "ARG='0 1'; ./push_swap 0 1"
	ARG='0 1'; ./push_swap $ARG
	echo -e "${cg}one element or already soorted${r}"
	echo
	echo 'ARG="12 13 15"; ./push_swap 12 13 15'
	ARG="12 13 15"; ./push_swap $ARG
	echo -e "${cg}one element or already soorted${r}"
	echo
	echo "ARG='12'; ./push_swap 12"
	ARG='12'; ./push_swap $ARG
	echo -e "${cg}one element or already soorted${r}"
	echo
	echo "./push_swap 12 13 15"
	./push_swap 12 13 15
	echo -e "${cg}one element or already soorted${r}"
	echo
	echo './push_swap "12 13 15"'
	./push_swap "12 13 15"
	echo -e "${cg}ERROR : parse invalid arg${r}"
	echo
	echo './push_swap "24897 933 83"'
	./push_swap "24897 933 83"
	echo -e "${cg}ERROR : parse invalid arg${r}"
	echo
	echo './push_swap "24897 933 83 190" "34"'
	./push_swap "24897 933 83 190" "34"
	echo -e "${cg}ERROR : parse invalid arg${r}"
	echo
	echo './push_swap "0" 0 " 1"'
	./push_swap "0" 0 " 1"
	echo -e "${cg}ERROR : parse invalid arg${r}"
	echo
	echo 'ARG="3 24 33 84"; ./push_swap "$ARG"'
	ARG="3 24 33 84"; ./push_swap "$ARG"
	echo -e "${cg}ERROR : parse invalid arg${r}"
	echo
	echo 'ARG="1 24 33 82"; test $ARG'
	ARG="1 24 33 82"; test $ARG
	echo -e "${cg}one element or already soorted${r}"
	echo
	echo 'ARG="2 24 33 83"; test $ARG'
	ARG="2 24 33 83"; test "$ARG"
	echo -e "${cg}ERROR : parse invalid arg${r}"
	echo
}

testwithlog(){
	NARG=$1
	NTEST=$2
	for (( i = 0; i < $NTEST; i++ )); do
		if ! ((i % (${NTEST} / 10))); then
			echo -e "${cb}push_swap:${NARG} ${i}/${NTEST}${r}"
		fi
		ARG=`ruby -e "puts (1..${NARG}).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l >> result.log
	done
	MIN=$(cat result.log | sort -h | uniq | head -n 2 | tail -n 1)
	MAX=$(cat result.log | sort -h | uniq | tail -n 1)
	rm result.log
	echo -e "${cb}push_swap:${NARG} ${cw1}[${MIN}..${MAX}]${r}"
}


rm -rf logs *.log
mkdir logs
# ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`;
# cd 42push_swap_visual && bash ./visualize.sh $ARG
# exit
##### TESTS
testwithlog $1 $2
# tc5
# tc100
# tc500
exit
# exit
# special
# validone
# valid2
randomtest
exit
error
s1
s2
s3
s4
s5
validone
valid2
valid3
valid4
valid5
randomtest
special
tc5
tc100
tc500
exit
