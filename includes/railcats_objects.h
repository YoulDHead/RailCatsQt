#ifndef railcats_objects
#define railcats_objects

#include <string>
#include <vector>
#include "railcats_service.h"
#include "railcats_queue.h"

const bool Forward=true;
const bool Backward=false;


class RailCats_Object_Types{
	public: 
		int ObjectID;
};


class RailCats_Decoder:public RailCats_Object_Types{

	public:
		int GetType();
		bool SetMessageToQueue(int Message);
	protected:
		int Type; // 1 - locomotive, 2 - turnout, 3 - accessory, 4 - feedback
};


class RailCats_Locomotive:public RailCats_Decoder{

	public: 
		RailCats_Locomotive();
		bool SetName(std::string NameToSet);
		std::string GetName();


		// speed control
		int GetSpeed();
		bool SetSpeed(int SpeedToSet);

		// direction control		
		bool GetDirection();
		bool SetDirection(bool DirectionToSet);

	protected:


		// loco label
		std::string Name;

		// Direction true=forward false=backward
		bool Direction;
		
		// Speed %
		int Speed;		
};









// Objects class  // something strange for me :) need to think about it
class RailCats_Objects{

	public: 

		RailCats_Objects();
		~RailCats_Objects();


		// Loco management
		int CreateLoco();
		bool DeleteLoco(int LocoID);
		RailCats_Locomotive GetLoco(int LocoID);
		bool SetLoco(RailCats_Locomotive TempLoco);

		
	protected:


	private:		

		// Service 

		RailCats_Service MyService;

		// objects handling (old and cannot be used)
		int AddObject(RailCats_Object_Types ObjectToAdd); // return ObjectID;
		bool DelObject(int ObjectToDelete); // return true/false;
		std::vector<RailCats_Object_Types> Objects;

		// object IDs handling
		int CreateObjectID();
		bool DeleteObjectID(int ObjectID);

		// objects handling variables

		int ObjectsCounter;
		std::vector<int> ObjectsID;

		// Locos vector
		std::vector<RailCats_Locomotive> Locos;

};












// Actions


class RailCats_Message:public RailCats_Object_Types{
	protected:
		

};

class RailCats_Action:public RailCats_Message{
	protected: 
};

class RailCats_Info:public RailCats_Message{
	protected:
		std::string InfoMessage;
		bool AddInfoMessage(std::string Text);
};


// decoders
class RailCats_LocoDecoder:public RailCats_Object_Types{
	protected:
		int Address;
		int Steps;
};

// Locos
class RailCats_Loco:public RailCats_Object_Types{
	public:
		std::string Description;
		int  Speed;
	private:

		bool Direction;
		RailCats_LocoDecoder Decoder;
};


// rails
class Turnout:public RailCats_Object_Types{
	public:
		std::string Description;
};


// maps
class Map:public RailCats_Object_Types{
	public:
		std::string Description;
};


#endif
