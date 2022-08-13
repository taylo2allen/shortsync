<!-- #+TITLE: ShortSync -->
<!-- #+AUTHOR: Taylor Allen -->
[![GitHub issues](https://img.shields.io/github/issues/taylo2allen/shortsync)](https://github.com/taylo2allen/shortsync/issues)
# DESCRIPTION
shortsync is a program that creates and manages: alias, file, and folder shortcuts between multiple applications.

# Installation
## AUR
To install from the AUR install the package shortsync-git.
``` shell
yay -S shortsync-git
yaourt -S shortsync-git
```
## Pacman
To install with pacman download the latest release then run the command:
``` shell
pacman -U shortsync-git-ver#-x86_64.pkg.tar.zst
```
## From Source
To install from source run the command:
``` shell
git clone https://github.com/taylo2allen/shortsync.git
cd shortsync
make install
```

# Usage
## -h, --help
Print this help message.
## -c, --config "PATH"
Load another config given the path.
## -w, --write
Appends the source command field to the specified config file.

## Configuration
``` conf
# alias_shortcuts
s     shortsync
sh    shortsync -h
```

```conf
# folder_shortcuts
hcS     $HOME/.config/shortsync
hcsC    $HOME/.config/shortsync/shortcut-configs
```

```conf
# file_shortcuts
fA   ~/.config/shortsync/shortcut-configs/alias_shortcuts.conf
ff   ~/.config/shortsync/shortcut-configs/file_shortcuts.conf
fF   ~/.config/shortsync/shortcut-configs/folder_shortcuts.conf
```

```yaml
# shortsync config
#
# shortcuts: Source the shortcut files, default format is
#            any plain text file comment syntax is a #.
#     alias-shortcuts: Source the alias shortcut file.
#     file-shortcuts: Source the file shortcut file.
#     folder-shortcuts: Source the folder shortcut file.

# anyapplication: You can put any name you would like, this is used
#                 to load the config of a specific application.
#   configpath: This designates where the source command is to be appended.
#   sourcecmd: This is the format of the source command keywords are $path$.
#   outputpath: Where would you like to store the shortcut file.
#   outputformat: What format would you like the shortcut file in,
#                 keywords are $aliases$, $files$, $folders$ each
#                 keywords relates to which shortcut file to output.
#   aliasformat: What format makes an alias to a command,
#                keywords are $short$, $cmd$.
#   filesformat: What format makes an alias to open a specific file,
#                keywords are $short$, $path$.
#   foldersformat: What format makes an alias to navigate to a specific folder,
#                  keywords are $short$, $path$.

shortcuts:
    alias-shortcuts: "$HOME/.config/shortsync/shortcut-configs/alias_shortcuts.conf"
    file-shortcuts: "$HOME/.config/shortsync/shortcut-configs/file_shortcuts.conf"
    folder-shortcuts: "$HOME/.config/shortsync/shortcut-configs/folder_shortcuts.conf"

bash:
    configpath: "~/.bashrc"
    sourceconf: "source $path$"
    outputpath: "$HOME/.config/shortsync/shortcut-files/bash_shortcuts"
    outputformat: "# alias shortcuts\n$aliases$\n# file shortcuts\n$files$\n# folder shortcuts\n$folders$\n"
    aliasformat: "alias $short$=\"$cmd$\""
    filesformat: "alias $short$=\"$EDITOR $path$\""
    foldersformat: "alias $short$=\"cd $path$\""
```
