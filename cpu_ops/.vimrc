execute pathogen#infect()
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'


" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required


" NerdTree hotkeys
map <C-n> :NERDTreeToggle<CR>


set showcmd
syntax on
set nu
set rnu
command WQ wq
command Wq wq
command W w
command Q q

" Remove physical wrapping and use visual wrapping
set wrap
set formatoptions=
