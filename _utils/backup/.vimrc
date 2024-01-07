"VIMRC CONFIG 23/07 @Kodpe
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"							AUTO QUICKFIX ON MAKE
"
" Command Make will call make and then cwindow which
" opens a 3 line error window if any errors are found.
" If no errors, it closes any open cwindow.
:command -nargs=* Make make <args> | cwindow 3
" Automatically open, but do not go to (if there are errors) the quickfix /
" location list window, or close it when is has become empty.
autocmd QuickFixCmdPost [^l]* nested cwindow
autocmd QuickFixCmdPost    l* nested lwindow
" Note: Must allow nesting of autocmds to enable any customizations for
" quickfix buffers. Normally, :cwindow jumps to the quickfix window if the
" command opens it However, as part of the autocmd, this doesn't seem to happen
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"							BASICS SETTINGS
set background=dark
syn on						"syntax highlighting
set showmode				"always show currently mode
set showmatch				" set show matching ( " >
colorscheme pablo			"pablo peachpuff
set cc=80
highlight ColorColumn ctermbg=darkgrey
"set noswapfile
set noerrorbells
set vb t_vb=
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"							42 HEADER
let	g:user42 = 'sloquet'
let g:mail42 = 'sloquet@student.42.fr'
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"							CURSOR OPTIONS
"set mouse=a "set mouse=r
set ruler					"show the cursor position
set nu rnu					"set number set relativenumber
set cursorline				"ligne contenant le curseur mise en valeur
set scrolloff=10			"10 lines keep above /below cursor
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"							INDENTING OPTIONS
set ai						"Indentation automatique
set tabstop=4				"Largeur d'une tabulation
set shiftwidth=4			"Largeur d'une indentation
set softtabstop=4
set noexpandtab				"Pas d'espaces à la place des tabulations
"set list "Masques pour remplir les espaces vides, tab, space, etc...
set listchars=tab:▸\ ,trail:·,nbsp:_,eol:¬,precedes:«,extends:»,nbsp:░
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"							SEARCH OPTIONS
set hlsearch
set ignorecase
set incsearch
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"								MAPPING
"imap <C-Y> <esc> yypi
imap <F9> <esc>
nmap <F10> <C-W>w
nmap <F8> :vne<CR><C-W>r
nmap ,mm <esc>:w<CR>:make<CR><CR><CR>
nmap <F11> 9j 
nmap <F12> 9k 
inoremap <,kl> {<enter>}<esc>O<tab>
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"						STATUS BAR & SPLIT OPTIONS

highlight VertSplit ctermbg=7 ctermfg=7 "Barre de split vertical

au InsertEnter * hi statusline ctermfg=Magenta ctermbg=White
au InsertLeave * hi statusline ctermfg=DarkGreen ctermbg=Black
hi statusline ctermfg=DarkGreen ctermbg=Black

let g:currentmode={
	\ 'n'      : 'NORMAL ',
	\ 'no'     : 'N·Operator Pending ',
	\ 'v'      : 'VISUAL',
	\ 'V'      : 'V·Line ',
	\ '\<C-V>' : 'V·Block ',
	\ 's'      : 'Select ',
	\ 'S'      : 'S·Line ',
	\ '\<C-S>' : 'S·Block ',
	\ 'i'      : 'INSERT ',
	\ 'R'      : 'REPLACE ',
	\ 'Rv'     : 'V·Replace ',
	\ 'c'      : 'COMMAND ',
	\ 'cv'     : 'Vim Ex ',
	\ 'ce'     : 'Ex ',
	\ 'r'      : 'Prompt ',
	\ 'rm'     : 'More ',
	\ 'r?'     : 'Confirm ',
	\ '!'      : 'Shell ',
	\ 't'      : 'Terminal '
		\}

	set laststatus=2
	set statusline=
	set statusline+=%0*\ %n\                                 " Buffer number
	set statusline+=[%{getbufvar(bufnr('%'),'&mod')?'ALTER':'SAVED'}] 
	set statusline+=%0*\ %{toupper(g:currentmode[mode()])}   " The current mode
	set statusline+=%1*\ %<%F%m%r%h%w\                       " File path, modified, readonly, helpfile, preview
	set statusline+=%3*│                                     " Separator
	set statusline+=%2*\ %Y\                                 " FileType
	set statusline+=%2*\ %{''.(&fenc!=''?&fenc:&enc).''}     " Encoding
	set statusline+=\ (%{&ff})                               " FileFormat (dos/unix..)
	set statusline+=%=                                       " Right Side
	set statusline+=%1*\ [%b][0x%B]\               			 " ASCII and byte code under cursor
	set statusline+=%0*\ %02v.%02l/%L\%3p%%\                 " Colonne.Ligne/TotalLigne %
	set statusline+=%0*\ %{toupper(g:currentmode[mode()])}\  " The current mode

	hi User1 ctermfg=007 ctermbg=239 
	hi User2 ctermfg=007 ctermbg=236 
	hi User3 ctermfg=236 ctermbg=236 
	hi User4 ctermfg=239 ctermbg=239 

