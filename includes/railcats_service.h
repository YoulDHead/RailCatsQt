#ifndef railcats_service
#define railcats_service

#include <string>
#include <iostream>
#include "tinyxml/tinyxml.h"
#include <QTextEdit>
#include "includes/railcats_settings.h"

extern RailCats_Settings RailCatsSettings;
class RailCats_Service{

	public:
		RailCats_Service();
		~RailCats_Service();



		// configs
		bool LoadConfig();
		bool SaveConfig();
        bool SetLogWindow(QTextEdit * mlogWindow);

		// log options
		bool ThrowLog(int MessageLogLevel,std::string Message);
		bool SwitchLogMode(int LogMode);

		// path and filenames

		std::string ConfigName;

		// logging
		std::string LogName;
		int 	    LogLevel;

        // log window        



	private:

};

#endif

