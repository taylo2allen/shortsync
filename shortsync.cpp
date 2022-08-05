#include <cstring>
#include <fstream>
#include <ios>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <yaml-cpp/yaml.h>

int main(int argc, char **argv) {
  std::string homedir = getenv("HOME");
  std::string configdir = homedir + "/.config/shortsync/config.yaml";
  std::string shortcutsdir =
      homedir + "/.config/shortsync/sourceshortcuts.yaml";
  std::string aliasesdir;
  std::string filesdir;
  std::string foldersdir;

  std::regex commentregex("^(.*#.*)$");
  std::regex homeregex("^[$~](HOME)?");

  const YAML::Node &shortcutf = YAML::LoadFile(shortcutsdir);

  // std::cout << shortcutfiles << "\n\n";

  for (YAML::const_iterator shortcut = shortcutf.begin();
       shortcut != shortcutf.end(); ++shortcut) {

    if (shortcut->second["aliasshortcut"].as<std::string>() != "") {
      aliasesdir = shortcut->second["aliasshortcut"].as<std::string>();
    } else {
      aliasesdir =
          homedir + "/.config/shortsync/shortcut-configs/alias_shortcuts.conf";
    }

    if (shortcut->second["fileshortcut"].as<std::string>() != "") {
      filesdir = shortcut->second["fileshortcut"].as<std::string>();
    } else {
      filesdir =
          homedir + "/.config/shortsync/shortcut-configs/file_shortcuts.conf";
    }

    if (shortcut->second["fileshortcut"].as<std::string>() != "") {
      foldersdir = shortcut->second["foldershortcut"].as<std::string>();
    } else {
      foldersdir =
          homedir + "/.config/shortsync/shortcut-configs/folder_shortcuts.conf";
    }
  }

  aliasesdir = std::regex_replace(aliasesdir, homeregex, homedir);
  filesdir = std::regex_replace(filesdir, homeregex, homedir);
  foldersdir = std::regex_replace(foldersdir, homeregex, homedir);

  bool writetofile = false;
  bool printstdout = true;
  for (int i = 1; i < argc; i++) {
    if (std::strcmp(argv[i], "-h") == 0 ||
        std::strcmp(argv[i], "--help") == 0) {
      std::cout << "shortsync [-OPTION] \"PATH\"\n\t-h, --help:\t\t\tPrint "
                   "this "
                   "help.\n\t-c, --config:\t\t\tLoad another config given the "
                   "path.\n\t-w, --write:\t\t\tAppends the source command "
                   "field "
                   "to "
                   "the specified config file.\n\t-a, --alias-shortcuts "
                   "\"PATH\":\tLoad another alias shortcut file given the "
                   "path.\n\t-f, --file-shortcuts \"PATH\":\tLoad another file "
                   "shortcut file given the path.\n\t-F, --folder-shortcuts "
                   "\"PATH\":\tLoad another folder shortcut file given the "
                   "path.\n\n"
                   "Visit the manpage for more information.";
      writetofile = false;
      printstdout = false;
    } else if (std::strcmp(argv[i], "-c") == 0 ||
               std::strcmp(argv[i], "--config") == 0) {
      configdir = argv[i + 0];
      configdir = std::regex_replace(configdir, homeregex, homedir);
    } else if (std::strcmp(argv[i], "-a") == 0 ||
               std::strcmp(argv[i], "--alias-shortcuts") == 0) {
      aliasesdir = argv[i + 0];
      aliasesdir = std::regex_replace(aliasesdir, homeregex, homedir);
    } else if (std::strcmp(argv[i], "-f") == 0 ||
               std::strcmp(argv[i], "--file-shortcuts") == 0) {
      filesdir = argv[i + 0];
      filesdir = std::regex_replace(filesdir, homeregex, homedir);
    } else if (std::strcmp(argv[i], "-F") == 0 ||
               std::strcmp(argv[i], "--folder-shortcuts") == 0) {
      foldersdir = argv[i + 0];
      foldersdir = std::regex_replace(foldersdir, homeregex, homedir);
    } else if (std::strcmp(argv[i], "-w") == 0 ||
               std::strcmp(argv[i], "--write") == 0) {
      writetofile = true;
      printstdout = false;
    }
  }

  std::ifstream iAlias;
  std::string iAliasContents, aliasstr;
  iAlias.open(aliasesdir);
  if (!iAlias.is_open()) {
    std::cout << "Error opening alias shortcuts file!\n";
    return 0;
  }

  int aliaslinecount = 0;
  while (std::getline(iAlias, iAliasContents)) {
    if (std::regex_match(iAliasContents, commentregex)) {
      continue;
    }
    aliaslinecount++;
    aliasstr = aliasstr + iAliasContents + "\n";
  }

  std::ifstream iFile;
  std::string iFileContents, filestr;
  iFile.open(filesdir);
  if (!iFile.is_open()) {
    std::cout << "Error opening file shortcuts file!\n";
    return 0;
  }

  int filelinecount = 0;
  while (std::getline(iFile, iFileContents)) {
    if (std::regex_match(iFileContents, commentregex)) {
      continue;
    }
    filelinecount++;
    filestr = filestr + iFileContents + "\n";
  }

  std::ifstream iFolder;
  std::string iFolderContents, folderstr;
  iFolder.open(foldersdir);
  if (!iFolder.is_open()) {
    std::cout << "Error opening folder shortcuts file!\n";
    return 0;
  }

  int folderlinecount = 0;
  while (std::getline(iFolder, iFolderContents)) {
    if (std::regex_match(iFolderContents, commentregex)) {
      continue;
    }
    folderlinecount++;
    folderstr = folderstr + iFolderContents + "\n";
  }

  const YAML::Node &config = YAML::LoadFile(configdir);

  for (YAML::const_iterator app = config.begin(); app != config.end(); ++app) {
    std::string aliasesstr, filesstr, foldersstr, outputstr;
    std::regex commentregex("^(.*#.*)$");
    std::regex replaceregex("[$](path|cmd)[$]");
    std::regex shortcutregex("[$](short)[$]");
    std::regex sourceregex("([a-zA-z]*) *(.*)");

    std::string configstr = app->second["configpath"].as<std::string>();
    std::string sourcecmdstr = app->second["sourcecmd"].as<std::string>();
    std::string outputfilestr = app->second["outputpath"].as<std::string>();
    outputstr = app->second["outputformat"].as<std::string>();
    std::string configpath = std::regex_replace(configstr, homeregex, homedir);
    std::string outputpath =
        std::regex_replace(outputfilestr, homeregex, homedir);
    std::string sourcecmd =
        std::regex_replace(sourcecmdstr, replaceregex, outputpath);

    std::ofstream sourcefile;
    sourcefile.open(configpath, std::ios::app);

    std::ofstream shortcutfile;
    if (writetofile) {
      shortcutfile.open(outputpath);
    }

    std::ifstream iConfig;
    std::string iConfigContents;
    iConfig.open(configpath);

    bool writesrc = true;
    // bool writesrc = false;
    std::regex configregex(sourcecmd);
    while (std::getline(iConfig, iConfigContents)) {
      if (std::regex_match(iConfigContents, configregex)) {
        writesrc = false;
        // break;
      }

      // if (iConfig.eof())
      // writesrc = true;
    }

    if (writesrc && writetofile) {
      sourcefile << sourcecmd;
    }

    if (app->second["configpath"].as<std::string>() == "") {
      std::cout << "Error while loading " << app->first
                << " missing required fields configpath.";
      return 0;
    } else if (app->second["sourcecmd"].as<std::string>() == "") {
      std::cout << "Error while loading " << app->first
                << " missing required fields sourcecmd.";
      return 0;
    } else if (!iConfig.is_open()) {
      std::cout << "Error while loading " << app->first
                << " config, an invalid path was loaded.";
      return 0;
    } else if (!shortcutfile.is_open() && writetofile) {
      std::cout << "Error while loading " << app->first
                << " outputpath field, an invalid path was loaded.";
      return 0;
    }

    if (printstdout && !writetofile) {
      std::cout << app->first << ":\nconfig file: " << configpath
                << "\noutput file: " << outputpath
                << "\n\nunformatted source command: " << sourcecmdstr
                << "\nformatted source command: " << sourcecmd << std::endl;
    }

    if (app->second["aliasformat"].as<std::string>() != "") {
      std::string aliasformatstr = app->second["aliasformat"].as<std::string>();
      std::string aliases, aliasstrbuf;
      std::smatch aliasmatch;
      if (printstdout && !writetofile) {
        std::cout << "\nunformatted alias shortcuts: "
                  << app->second["aliasformat"]
                  << "\nformatted alias shortcuts:\n";
      }

      std::string parsedalias;
      std::stringstream ssalias(aliasstr);

      for (int i = 0; i < aliaslinecount; i++) {
        std::getline(ssalias, parsedalias);
        std::regex_search(parsedalias, aliasmatch, sourceregex);
        aliasstrbuf = std::regex_replace(aliasformatstr, shortcutregex,
                                         aliasmatch.str(1));
        aliases =
            std::regex_replace(aliasstrbuf, replaceregex, aliasmatch.str(2));
        aliasesstr = aliasesstr + aliases + "\n";
      }

      if (printstdout && !writetofile) {
        std::cout << aliasesstr << std::endl;
      }
    }

    if (app->second["filesformat"].as<std::string>() != "") {
      std::string fileformatstr = app->second["filesformat"].as<std::string>();
      std::string files, filestrbuf;
      std::smatch filematch;

      if (printstdout && !writetofile) {
        std::cout << "unformatted file shortcuts: "
                  << app->second["filesformat"]
                  << "\nformatted file shortcuts:\n";
      }

      std::string parsedfile;
      std::stringstream ssfile(filestr);

      for (int i = 0; i < filelinecount; i++) {
        std::getline(ssfile, parsedfile);
        std::regex_search(parsedfile, filematch, sourceregex);
        filestrbuf =
            std::regex_replace(fileformatstr, shortcutregex, filematch.str(1));
        files = std::regex_replace(filestrbuf, replaceregex, filematch.str(2));
        filesstr = filesstr + files + "\n";
      }
      if (printstdout && !writetofile) {
        std::cout << filesstr << std::endl;
      }
    }

    if (app->second["foldersformat"].as<std::string>() != "") {
      std::string folderformatstr =
          app->second["foldersformat"].as<std::string>();
      std::string folders, folderstrbuf;
      std::smatch foldermatch;
      if (printstdout && !writetofile) {
        std::cout << "unformatted folder shortcuts: "
                  << app->second["foldersformat"]
                  << "\nformatted folder shortcuts:\n";
      }

      std::string parsedfolder;
      std::stringstream ssfolder(folderstr);

      for (int i = 0; i < folderlinecount; i++) {
        std::getline(ssfolder, parsedfolder);
        std::regex_search(parsedfolder, foldermatch, sourceregex);
        folderstrbuf = std::regex_replace(folderformatstr, shortcutregex,
                                          foldermatch.str(1));
        folders =
            std::regex_replace(folderstrbuf, replaceregex, foldermatch.str(2));
        foldersstr = foldersstr + folders + "\n";
      }
      if (printstdout) {
        std::cout << foldersstr << std::endl;
      }
    }

    std::regex aliasesregex("[$](aliases)[$]");
    std::regex filesregex("[$](files)[$]");
    std::regex foldersregex("[$](folders)[$]");
    outputstr = std::regex_replace(outputstr, aliasesregex, aliasesstr);
    outputstr = std::regex_replace(outputstr, filesregex, filesstr);
    outputstr = std::regex_replace(outputstr, foldersregex, foldersstr);

    if (writetofile) {
      shortcutfile << outputstr;
      shortcutfile.close();
    }
  }

  iAlias.close();
  iFile.close();
  iFolder.close();

  return 0;
}
