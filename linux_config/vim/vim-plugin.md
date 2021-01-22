# 快速浏览代码 tagbar

使用 [tagbar](https://github.com/majutsushi/tagbar) 快速浏览代码。

依赖于 [universal ctags](https://ctags.io/)

安装 universal ctags：

```
brew tap universal-ctags/universal-ctags
brew install --HEAD universal-ctags
```

在 vimrc 中添加:

```
Plug 'majutsushi/tagbar'
```

然后：

```
source ~/.vimrc
:PlugInstall
```

在 vimrc 中设置快捷方式：

```
let mapleader = ','
innoremap <leader>t :TagbarToggle<cr>
```

这是使用 `,t` 即可显示快速代码浏览。
