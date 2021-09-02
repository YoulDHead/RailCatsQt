// RailCats P50 connector (DCC version)
#ifndef railCats_connector_p50
#define railCats_connector_p50

#include <string>
#include <vector>

#include "railcats_protocols_p50.h"
#include "railcats_service.h"
//RailCats_Service MyService;
#include "railcats_logic_objects.h"
#include "decoderprog.h"



// Some constants

class RailCats_Connector_p50_Loco_Decoder_DCC{

    public:
        RailCats_Connector_p50_Loco_Decoder_DCC();
        ~RailCats_Connector_p50_Loco_Decoder_DCC();

        void SetHWAddress(int address);
        void SetSteps(int steps);
        void SetLAddress(int ladress);

        int GetHWAddress();
        int GetSteps();
        int GetLAddress();

    private:

        int HWAddress;
        int Steps;
        int LAddress;

};


class RailCats_Connector_p50{

	public: 

		RailCats_Connector_p50();
		~RailCats_Connector_p50();
		
		std::string Name;		

		int GetConnectorState();

		bool GoConnect();
		bool GoDisconnect();
		bool GoDefunct();

		bool GoQueue();

        void EmergencyStop();
        bool GetEmergencyStopState();
		
        // Service functions
        std::string ConnectorGetVersion();


        bool AddDecoder(RailCats_Connector_p50_Loco_Decoder_DCC DecoderIN);

        bool MapLocoToDecoder(RailCats_Locomotive * LocoIN, RailCats_Connector_p50_Loco_Decoder_DCC * DecoderIN);

        bool SaveDecodersToFile(std::string FileName);
        bool LoadDecodersFromFile(std::string FileName);

        // Loco functions
        bool LocoExecute(RailCats_Locomotive * LocoIN);

        // Program Functions


	private:		

        static const int Uninitialized = 0;
		static const int Disconnected = 1;
		static const int Connected = 3;
		static const int Defunct = 4;

        bool EmergencyStopped;

        RailCats_Service MyService;

		int ConnectorState;
		RailCats_Protocols_P50 Protocol;

        std::vector<RailCats_Connector_p50_Loco_Decoder_DCC> LocoDecoders;

};

#endif
