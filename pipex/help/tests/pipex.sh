#!/bin/bash

make

test() {
	ls -l > .infile
	chmod 000 .infile

	touch .out
	chmod 200 .out

	echo -ne "\033[35m"; ls -an .infile .out; echo -ne "\033[0m"

	valgrind	--leak-check=full \
				--show-leak-kinds=all \
				--track-origins=yes \
				"$@"

				# --trace-children=yes \

	echo -e "\033[31mpipex exitcode : $?\033[0m"
	echo -e "\033[32mdone !!\033[0m"

	# < .infile date | cat -n |rev > .diff

	chmod 666 .out
	echo --- cat .out
	cat .out
	echo ---
	# echo -e "\033[32m"; diff -s .diff .out; echo -e "\033[0m"
	rm -rf out* .out* .infile .diff
}

# test ./pipex .infile cat rev cat rev rev cat rev cat .out
# test ./pipex .infile cat cat rev cat rev cat rev rev cat cat cat cat rev cat cat cat rev cat cat .out
# test ./pipex .infile cat rev rev rev "cat -n" rev date rev wc h date h .out
test ./pipex nofile cat rev hobe .out
# test ./pipex .infile rev jj cat "ls -luv" "cat -n" rev rev .out
# test ./pipex .infile fewj joiej iowjoi iejioi fjiojfioj iojioj .out
# test env -i ./pipex .infile cmd1 cmd2 cmd3 date cmd5 hostname wc dji wc .out


# ./pipex .infile cat cat rev cat rev cat rev rev cat cat cat cat rev cat cat cat rev cat cat .out
