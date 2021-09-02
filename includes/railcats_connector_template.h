// RailCats P50 connector (DCC version)
#ifndef railcats_connector
#define railcats_connector

#include <string>

#include "railcats_protocols_p50.h"
#include "railcats_service.h"




// Some constants


class RailCats_Connector{

	public: 

		RailCats_Connector();
		~RailCats_Connector();
		
		std::string RailCats_Connector_Name;		

		int GetConnectorState();

		bool GoConnect();
		bool GoDisconnect();
		bool GoDefunct();

	private:		
		static const int Uninitialized = 0;
		static const int Disconnected = 1;
		static const int Connected = 3;
		static const int Defunct = 4;

		RailCats_Service MyService;

		int ConnectorState;
		RailCats_Protocols_P50 Protocol;
};





#endif
