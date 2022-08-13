# ShortSync
[![ShortSync](https://img.shields.io/badge/ShortSync-a_program_than_creates_and_manages:_alias,_file,_and_folder_shortcuts_between_multiple_applications.-9cf)](https://github.com/taylo2allen/shortsync/)

[![GitHub issues](https://img.shields.io/github/issues/taylo2allen/shortsync)](https://github.com/taylo2allen/shortsync/issues)
[![GitHub forks](https://img.shields.io/github/forks/taylo2allen/shortsync)](https://github.com/taylo2allen/shortsync/network)
[![GitHub stars](https://img.shields.io/github/stars/taylo2allen/shortsync)](https://github.com/taylo2allen/shortsync/stargazers)
[![GitHub license](https://img.shields.io/github/license/taylo2allen/shortsync)](https://github.com/taylo2allen/shortsync/blob/main/LICENSE)
[![Donate](https://img.shields.io/badge/Donate-$$$-9cf)](https://linktr.ee/taylo2allen)

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

### Configuration
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

[![Example](https://carbon.now.sh/?bg=rgba%28171%2C+184%2C+195%2C+1%29&t=one-dark&wt=none&l=auto&width=680&ds=true&dsyoff=20px&dsblur=68px&wc=true&wa=true&pv=56px&ph=56px&ln=false&fl=1&fm=Hack&fs=14px&lh=133%25&si=false&es=2x&wm=false&code=%25E2%259D%25AE%2520shortsync%2520-c%2520%27%7E%252F.config%252Fshortsync-example%252Fconfig.yaml%27%250Abash%253A%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%250Aconfig%2520file%253A%2520%252Fhome%252Ftaylorallen%252F.bashrc%250Aoutput%2520file%253A%2520%252Fhome%252Ftaylorallen%252F.config%252Fshortsync-example%252Fshortcut-files%252Fbash_shortcuts%250A%250Aunformatted%2520source%2520command%253A%2520source%2520%2524path%2524%250Aformatted%2520source%2520command%253A%2520source%2520%252Fhome%252Ftaylorallen%252F.config%252Fshortsync-example%252Fshortcut-files%252Fbash_shortcuts%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%250A%250Aunformatted%2520alias%2520shortcuts%253A%2520alias%2520%2524short%2524%253D%2522%2524cmd%2524%2522%250Aformatted%2520alias%2520shortcuts%253A%250Aalias%2520s%253D%2522shortsync%2522%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%250Aalias%2520sh%253D%2522shortsync%2520-h%2522%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%250A%250Aunformatted%2520file%2520shortcuts%253A%2520alias%2520%2524short%2524%253D%2522%2524EDITOR%2520%2524path%2524%2522%250Aformatted%2520file%2520shortcuts%253A%250Aalias%2520fa%253D%2522%2524EDITOR%2520%7E%252F.config%252Fshortsync%252Fshortcut-configs%252Falias_shortcuts.conf%2522%250Aalias%2520ff%253D%2522%2524EDITOR%2520%7E%252F.config%252Fshortsync%252Fshortcut-configs%252Ffile_shortcuts.conf%2522%250Aalias%2520fF%253D%2522%2524EDITOR%2520%7E%252F.config%252Fshortsync%252Fshortcut-configs%252Ffolder_shortcuts.conf%2522%250A%250Aunformatted%2520folder%2520shortcuts%253A%2520alias%2520%2524short%2524%253D%2522cd%2520%2524path%2524%2522%250Aformatted%2520folder%2520shortcuts%253A%250Aalias%2520hcS%253D%2522cd%2520%2524HOME%252F.config%252Fshortsync%2522%250Aalias%2520hcsC%253D%2522cd%2520%2524HOME%252F.config%252Fshortsync%252Fshortcut-configs%2522)]
