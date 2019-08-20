#include "lang/lang.h"
#include <fstream>

#include "common/inifile.h"
#include "lang/langStrings.h"

std::string langs[] = { "de", "en", "es", "fr", "it", "jp"};

void Lang::loadLangStrings(int lang) {
	// Declare variables
	char path[32];
	std::string line;

	// Load app strings
	snprintf(path, sizeof(path), "romfs:/lang/%s/app.ini", langs[lang].c_str());
	CIniFile ini(path);

	// [keyboard]
	Lang::typeName = ini.GetString("keyboard", "typeName", Lang::typeName);

	// [language]
	Lang::language = ini.GetString("language", "ccl", Lang::language);

	// [mainmenu]
	Lang::mainMenu[0] = ini.GetString("mainmenu", "townmanager", Lang::mainMenu[0]);
	Lang::mainMenu[1] = ini.GetString("mainmenu", "editor", Lang::mainMenu[1]);
	Lang::mainMenu[2] = ini.GetString("mainmenu", "settings", Lang::mainMenu[2]);

	// [messages]
	Lang::messages[0] = ini.GetString("messages", "1", Lang::messages[0]);
	Lang::messages[1] = ini.GetString("messages", "2", Lang::messages[1]);
	Lang::messages[2] = ini.GetString("messages", "3", Lang::messages[2]);
	Lang::messages[3] = ini.GetString("messages", "4", Lang::messages[3]);
	Lang::messages[4] = ini.GetString("messages", "5", Lang::messages[4]);
	Lang::messages[5] = ini.GetString("messages", "6", Lang::messages[5]);
	Lang::messages[6] = ini.GetString("messages", "7", Lang::messages[6]);

	// [messages]
	Lang::messages2[0] = ini.GetString("messages2", "continue", Lang::messages2[0]);
	Lang::messages2[1] = ini.GetString("messages2", "confirm", Lang::messages2[1]);
	Lang::messages2[2] = ini.GetString("messages2", "backup", Lang::messages2[2]);
	Lang::messages2[3] = ini.GetString("messages2", "restore", Lang::messages2[3]);
	Lang::messages2[4] = ini.GetString("messages2", "launch", Lang::messages2[4]);

	// [misc]
	Lang::notImplemented = ini.GetString("misc", "notImplemented", Lang::notImplemented);

	// [title]
	Lang::title = ini.GetString("title", "title", Lang::title);

	// [titleSelector]
	Lang::titleSelector[0] = ini.GetString("titleSelector", "title", Lang::titleSelector[0]);
	Lang::titleSelector[1] = ini.GetString("titleSelector", "card", Lang::titleSelector[1]);
	Lang::titleSelector[2] = ini.GetString("titleSelector", "installed", Lang::titleSelector[2]);

	// [townmanager]
	Lang::townmanager[0] = ini.GetString("townmanager", "launch", Lang::townmanager[0]);
	Lang::townmanager[1] = ini.GetString("townmanager", "backup", Lang::townmanager[1]);
	Lang::townmanager[2] = ini.GetString("townmanager", "restore", Lang::townmanager[2]);


	// [scan]
	Lang::scan[0] = ini.GetString("scan", "TF", Lang::scan[0]);
	Lang::scan[1] = ini.GetString("scan", "TNF", Lang::scan[1]);
	Lang::scan[2] = ini.GetString("scan", "IDM", Lang::scan[2]);
	Lang::scan[3] = ini.GetString("scan", "IDDM", Lang::scan[3]);
	Lang::scan[4] = ini.GetString("scan", "NCI", Lang::scan[4]);

	// [update]
	Lang::update[0] = ini.GetString("update", "found", Lang::update[0]);
	Lang::update[1] = ini.GetString("update", "notFound", Lang::update[1]);
}