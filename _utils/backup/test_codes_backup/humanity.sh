#!/bin/bash

clear
echo

echo -en "\033[31m"
for ((i = 0; i < 99998; i++)); do
	echo -en "\u2588"
done

echo -en "\033[32m"
for ((i = 0; i < 2; i++)); do
	echo -en "\u2588"
done

echo -en "\033[33m"
for ((i = 0; i < 5333; i++)); do
	echo -en "\u2588"
done


echo -en "\033[0m"

echo
