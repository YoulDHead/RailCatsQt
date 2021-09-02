#ifndef railcats_serial
#define railcats_serial
#include <string>

class RailCats_Serial{


	public:
		RailCats_Serial();
		~RailCats_Serial();



		bool OpenSerial();
		bool CloseSerial();
		bool WriteSerial();
		bool ReadSerial();
		

		// Com port settings

		std::string 	Serial_Port;
		int		Serial_Baudrate;
		bool 		Serial_Parity;
		int		Serial_Bits;
		bool		Serial_Stop;


};


#endif
