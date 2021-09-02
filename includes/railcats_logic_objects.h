#ifndef railcats_logic_objects
#define railcats_logic_objects

#include <string>
#include <vector>
#include "tinyxml/tinyxml.h"

class RailCats_Locomotive{

	public:
		RailCats_Locomotive();
		~RailCats_Locomotive();


        void SetAddress(int AddressIN);
        void SetName(std::string NameIN);
        void SetSpeed(int SpeedIN);
        void EmergencyStop();
        void SetDirection(int DirectionIN);
        void SetFn(int Fnum,int Pos);

        int             GetAddress();
        std::string     GetName();
        int             GetSpeed();
        int             GetDirection();
        int             GetFn(int Fnum);

    private:

        int                 address;            // logic address (not HW!!!)
        std::string         name;               //
        int                 speed;              // speed in %
        bool                direction;          // true-forward, false-reverse
        std::vector <int>   FNs;                // vector of Fn (1 or 0 for now, may be need to reduce to bool)

};

class RailCats_LocoCollection{


    public:
        RailCats_LocoCollection();
        ~RailCats_LocoCollection();

        bool AddLoco(RailCats_Locomotive LocoIN);
        bool DelLoco(RailCats_Locomotive LocoIN);
        bool GetLoco(int AddressIN,RailCats_Locomotive * LocoIN);
        bool GetNext(RailCats_Locomotive * LocoIN);
        bool GetPrev(RailCats_Locomotive * LocoIN);
        bool SetLoco(RailCats_Locomotive LocoIN);
        bool AddressCheck(int AddressIN);
        bool SaveToFile(std::string FileName);
        bool LoadFromFile(std::string FileName);


    private:


        int Iterator;
        std::vector <RailCats_Locomotive> Collection;



};

#endif
