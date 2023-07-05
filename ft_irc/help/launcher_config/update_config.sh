#!/bin/bash

#######
### SETUP
launcher_dir="launcher_config"
layout_config="$launcher_dir/layout_proxy"
proxy_py="$launcher_dir/proxy.py"
term_config="$HOME/.config/terminator/config"
KEY1="layouts"
REF1=$(cat -n $term_config | grep "\[$KEY1\]" | awk '{print $1}')
KEY2="plugins"
REF2=$(cat -n $term_config | grep "\[$KEY2\]" | awk '{print $1}')

#######
### CHECKS FOR KEYS INUSER TERM CONFIG
if [ -z "$REF1" ]; then
	echo -e "\033[31mERROR: [$KEY1] unfound in $term_config\033[0m"
	exit 1
fi

if [ -z "$REF2" ]; then
	echo -e "\033[31mERROR: [$KEY2] unfound in $term_config\033[0m"
	exit 2
fi

if [ $REF2 -le $REF1 ]; then
	echo -e "\033[31mERROR: [$KEY2] invalid in $term_config\033[0m"
	exit 3
fi

#######
### SETUP SUMMARY
echo "===== irc launcher v5 ====="
echo "current directory  : $PWD"
echo "launcher directory : $launcher_dir"
echo "layout config file : $layout_config"
echo "proxy python file  : $proxy_py"
echo "term config file   : $term_config"
echo "key1 is            : [$KEY1] at line $REF1"
echo "key2 is            : [$KEY2] at line $REF2"
echo ------

#######
### BUILD NEW TERMINATOR CONFIG FILE AND REPLACE OLD
echo "building... new terminator config"
cat $term_config | head -$(echo $REF1) > new_config
cat $layout_config >> new_config
cat $term_config | tail +$(echo $REF2) >> new_config

cp $term_config ${term_config}_backup
rm $term_config
sed "s+IRC_CONFIG_PATH+$PWD/$launcher_dir+g" new_config > $term_config
rm new_config

#######
### LAUNCH TERMINATOR LAYOUT
#echo "starting... terminator -l IRCPROX"
#echo "current pwd : $PWD"
#terminator -l IRCPROX
echo "Done!"
exit
