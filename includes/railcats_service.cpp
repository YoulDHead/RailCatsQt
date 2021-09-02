//#include "includes/globalsettings.h"
#include "includes/build_settings.h"
#include "railcats_service.h"

RailCats_Service::RailCats_Service(){

	// default config name and path
	ConfigName="RailCatsConfig.xml";

	// default log name and path
	LogName="RailCatsMain.log";
	
	// default log level (0-4) 0 - nothing, 4 - all
	LogLevel=4;



};

RailCats_Service::~RailCats_Service(){};


bool RailCats_Service::SetLogWindow(QTextEdit * mlogWindow){

    //logWindow=mlogWindow;

    return true;


}

// Logging

bool RailCats_Service::ThrowLog(int MessageLogLevel,std::string Message){

    if (MessageLogLevel<=LogLevel && LogLevel!=0){
		std::cout<<Message<<std::endl;

        QString Qmessage = QString::fromUtf8(Message.c_str());
        RailCatsSettings.logWindow->append(Qmessage);

	}
	
	return true;

};

bool RailCats_Service::SwitchLogMode(int LogMode){

	switch (LogMode){
		case 0:
		break;
		case 1:
		break;
	}

    return true;
};


// Configs
bool RailCats_Service::LoadConfig(){

	ThrowLog(0,"Loading configuration..");

#ifdef RC_PLATFORM_WIN32
    TiXmlDocument XmlConfig(ConfigName.c_str());
#endif

#ifdef RC_PLATFORM_LINUX
    TiXmlDocument XmlConfig(ConfigName);
#endif

	if(XmlConfig.LoadFile()){

		TiXmlNode* Body = 0;
		TiXmlElement* ConfigElement = 0;

		Body = XmlConfig.FirstChild("Body");
		if(Body==NULL){
			ThrowLog(4,"Config file error - Body element not found");
			return false;
		};

		ConfigElement = Body -> FirstChildElement("Config");
		if(ConfigElement==NULL){
			ThrowLog(4,"Config file error - Config element not found");
			return false;
		};

		// next - load parameters
		/*MySettings.BaseAppPath=static_cast<std::string>(ConfigElement->Attribute("BaseAppPath"));
			std::string TempMFR=static_cast<std::string>(ConfigElement->Attribute("MiFareReader"));
				if(strcmp(TempMFR.c_str(),"1")==0){
					MySettings.MiFareReader=true;
				}else{
					MySettings.MiFareReader=false;
				}*/

	}else{

		// Throw message to log
			ThrowLog(2,"Could not load config file");
		//
		return false;

	}

	return true;

};

//Save settings
bool RailCats_Service::SaveConfig(){


#ifdef RC_PLATFORM_WIN32
    TiXmlDocument XmlConfig(ConfigName.c_str());
#endif

#ifdef RC_PLATFORM_LINUX
    TiXmlDocument XmlConfig(ConfigName);
#endif


	TiXmlDeclaration * XmlDeclaration = new TiXmlDeclaration( "1.0", "koi8-r", "" );

	XmlConfig.LinkEndChild(XmlDeclaration);

	TiXmlElement * BodyElement = new TiXmlElement("Body");
	XmlConfig.LinkEndChild(BodyElement);

	
	TiXmlElement * ConfigElement = new TiXmlElement( "Config" );

			// next save settings
/*			ConfigElement->SetAttribute("YarusGuid",MySettings.YarusGuid);
			if(MySettings.IsLoggedOn){
				ConfigElement->SetAttribute("IsLoggedOn","1");
			}else{
				ConfigElement->SetAttribute("IsLoggedOn","0");
			};
*/
	BodyElement->LinkEndChild( ConfigElement );

			

	if(XmlConfig.SaveFile()){
		return true;
	}else{
		return false;			
	}

};


