# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:/usr/local/bin:$PATH
#touch ~/.config/google-chrome/Singleton
#rm -rf ~/.config/google-chrome/Singleton*
#rm -rf ~/.mozilla

# Path to your oh-my-zsh installation.
export ZSH="$HOME/.oh-my-zsh"
export EDITOR=/usr/bin/vim

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time oh-my-zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/ohmyzsh/ohmyzsh/wiki/Themes
ZSH_THEME="robbyrussell"
#ZSH_THEME="agnoster"

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in $ZSH/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment one of the following lines to change the auto-update behavior
# zstyle ':omz:update' mode disabled  # disable automatic updates
# zstyle ':omz:update' mode auto      # update automatically without asking
# zstyle ':omz:update' mode reminder  # just remind me to update when it's time

# Uncomment the following line to change how often to auto-update (in days).
# zstyle ':omz:update' frequency 13

# Uncomment the following line if pasting URLs and other text is messed up.
# DISABLE_MAGIC_FUNCTIONS="true"

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
#ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# You can also set it to another string to have that shown instead of the default red dots.
# e.g. COMPLETION_WAITING_DOTS="%F{yellow}waiting...%f"
# Caution: this setting can cause issues with multiline prompts in zsh < 5.7.1 (see #5765)
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in $ZSH/plugins/
# Custom plugins may be added to $ZSH_CUSTOM/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(git)
source $ZSH/oh-my-zsh.sh

#xmodmap ~/Documents/xcape/xmodmap
#~/Documents/xcape/xcape -e 'Mode_switch=Escape';

# User configuration
setopt shwordsplit

# export MANPATH="/usr/local/man:$MANPATH"
#export PS1="%B[%m %~]$%b "
export MAIL="sloquet@student.42.fr"
export EDITOR='vim'
#
libft_path="~/Documents/42-cursus/libft"
##############
alias help="tail -n 70 ~/.zshrc"
alias cfz="vim ~/.zshrc"
#
alias rain="~/.start"
alias mvs="mv ~/Screenshot*.png ~/Documents/42-cursus/docs/screenshots"
alias gcc="gcc -Wall -Wextra -Werror"
alias cls="clear"
alias chx="chmod +x"
alias save="~/Documents/ft_containers/save.sh"
alias dume="du -hs ~/../sloquet"
alias h="head -n"
alias t="tail -n"
alias ggo="/usr/bin/gcc"
##############
#   DeepL    #
##############
alias tfr="xdg-open 'https://www.deepl.com/translator?utm_source=lingueebanner1&il=fr#en/fr/' &> /dev/null"
alias ten="xdg-open 'https://www.deepl.com/translator?utm_source=lingueebanner1&il=fr#fr/en/' &> /dev/null"
alias tru="xdg-open 'https://www.deepl.com/translator?utm_source=lingueebanner1&il=fr#fr/ru/' &> /dev/null"
##############
#  Chrome    #
##############
alias gg="xdg-open 'https://github.com/kodpe?tab=repositories' &> /dev/null"
alias cheh="xdg-open 'https://www.google.fr/' &> /dev/null"
alias int="xdg-open 'https://profile.intra.42.fr/' &> /dev/null"
alias intg="xdg-open 'https://projects.intra.42.fr/projects/graph' &> /dev/null"
alias intl="xdg-open 'https://projects.intra.42.fr/projects/list' &> /dev/null"
alias spo="xdg-open 'https://open.spotify.com/collection/tracks' &> /dev/null"
alias goe1="xdg-open 'https://stud42.fr/clusters/1' &> /dev/null"
alias goe2="xdg-open 'https://stud42.fr/clusters/2' &> /dev/null"
alias goe3="xdg-open 'https://stud42.fr/clusters/3' &> /dev/null"
alias go42="xdg-open 'https://github.com/kodpe/42-cursus' &> /dev/null"
alias exc="xdg-open 'https://excalidraw.com/' &> /dev/null"
##############
#     LS     #
##############
alias la="ls -lA"
alias lr="ls -R"
##############
#     CD     #
##############
alias cdd="cd ~/Documents && ls"
alias cdl="cd ~/.local && ls"
alias cds="cd /sgoinfre/goinfre/Perso/sloquett && ls"
alias cdcom="cd /sgoinfre/goinfre/Perso/sloquett/dcom && ls -la"
##############
#    GIT     #
##############
alias glg='git log --graph --pretty='\''%Cred%h%Creset -%C(auto)%d%Creset %s %Cgreen(%ar) %C(bold blue)<%an>%Creset'\'' --stat'
alias gll="git log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold green)(%ar)%C(reset) %C(white)%s%C(reset) %C(dim white)- %an%C(reset)%C(bold yellow)%d%C(reset)' --all"
alias gld="git log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold cyan)%aD%C(reset) %C(bold green)(%ar)%C(reset)%C(bold yellow)%d%C(reset)%n''          %C(white)%s%C(reset) %C(dim white)- %an%C(reset)' --all"
##############
#    DIFF    #
##############
alias dif='echo -ne "\e[0;31m" && diff -Nrq'
alias difl="echo -ne '\e[0;31m' && diff -Nrq ${libft_path}"
alias difz="diff -Nur"
alias difzl="diff -Nur ${libft_path}"
#
alias name='clear && cat ./*/Make* | grep "NAME" | grep -v "(NAME)" && ls -R'
alias keybr="xdg-open 'https://www.keybr.com/' &> /dev/null"
#
##############
#  END CFZ   #
##############
#
# zsheep_0.2.8-b Linux Thu 26 May 2022 09:29:42 PM CEST
# zsheep alias list
ZSHEEP_PATH="~/.local/zsheep/zsheep_app"
alias gps="$ZSHEEP_PATH/42gps/gps"
alias sna="$ZSHEEP_PATH/snails/snails"
alias snails="$ZSHEEP_PATH/snails/snails"
alias sky="$ZSHEEP_PATH/askyy/askyy_road"
alias askyy="$ZSHEEP_PATH/askyy/askyy_road"
alias color="$ZSHEEP_PATH/color/color_scheme"
alias zhelp="$ZSHEEP_PATH/help/usage"
alias ui="$ZSHEEP_PATH/goint/gointra"
alias qi="$ZSHEEP_PATH/goint/qrintra"
alias gi="$ZSHEEP_PATH/goint/ghintra"
alias iph="$ZSHEEP_PATH/short/ip"
alias ntl="$ZSHEEP_PATH/short/ntl"
alias img="$ZSHEEP_PATH/short/img"
alias norm="$ZSHEEP_PATH/short/norm"
alias magick="$ZSHEEP_PATH/short/magick $@"
# zsheep_@kodpe
LYNX_CFG=~/lynx.cfg; export LYNX_CFG
#alias elie="/sgoinfre/goinfre/Perso/sloquett/eamar.exe"

alias tli="terminator -l IRCPROX"


PATH+=":$HOME/.local/bin"
# mkup - auto update or create a makefile
alias mkup="~/.local/mkup"

#docker
alias dock="~/Documents/dock.sh"
alias dockrm="~/Documents/dockrm.sh"

#chrome
alias gle-reset="rm -rf ~/.config/google-chrome/Singleton*"
