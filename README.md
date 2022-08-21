# ShortSync
[![ShortSync](https://img.shields.io/badge/ShortSync-a_program_than_creates_and_manages:_alias,_file,_and_folder_shortcuts_between_multiple_applications.-9cf)](https://github.com/taylo2allen/shortsync/)

[![GitHub issues](https://img.shields.io/github/issues/taylo2allen/shortsync)](https://github.com/taylo2allen/shortsync/issues)
[![GitHub forks](https://img.shields.io/github/forks/taylo2allen/shortsync)](https://github.com/taylo2allen/shortsync/network)
[![GitHub stars](https://img.shields.io/github/stars/taylo2allen/shortsync)](https://github.com/taylo2allen/shortsync/stargazers)
[![GitHub license](https://img.shields.io/github/license/taylo2allen/shortsync)](https://github.com/taylo2allen/shortsync/blob/main/LICENSE)
[![Donate](https://img.shields.io/badge/Donate-$$$-9cf)](https://linktr.ee/taylo2allen)

[![asciicast](/examples/demo.gif)](https://asciinema.org/a/1fYxzcxBYzo7k7OKb24iZDMfg?autoplay=1&loop=1)

## Summary
shortsync is a program that creates and manages: alias, file, and folder shortcuts between multiple applications.

## Installation
### AUR
To install from the AUR install the package shortsync-git.

### Pacman
To install with pacman download the latest release then run the command:
```bash
pacman -U shortsync-git-0.1.0-1-x86_64.pkg.tar.zst
```
### From Source
To install from source run the command:
```bash
git clone https://github.com/taylo2allen/shortsync.git
cd shortsync
make install
```
## Usage
### -h, --help
Print this help message.
### -c, --config "PATH"
Load another config given the path.
### -w, --write
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

[![Example](examples/example.svg)]()

## Support
Just a freelance programmer trying to make a living, everything is appreciated Thank You for the donation.
[![Donate](https://img.shields.io/badge/Donate-$$$-9cf)](https://linktr.ee/taylo2allen)
