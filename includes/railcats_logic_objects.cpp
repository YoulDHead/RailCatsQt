#include "build_settings.h"
#include "railcats_logic_objects.h"
#include <iostream>

#ifdef RC_PLATFORM_WIN32
#include <sstream>
#endif

RailCats_Locomotive::RailCats_Locomotive(){

    address=0;
    name="";               //
    speed=0;              // speed in %
    direction=true;          // true-forward, false-reverse

    for (int i=0;i<255;i++){
        FNs.push_back(0);
    }


};
RailCats_Locomotive::~RailCats_Locomotive(){};


void RailCats_Locomotive::EmergencyStop(){


};

void RailCats_Locomotive::SetAddress(int AddressIN){
    address=AddressIN;
};


void RailCats_Locomotive::SetName(std::string NameIN){
    name=NameIN;
};

void RailCats_Locomotive::SetSpeed(int SpeedIN){
    speed=SpeedIN;
};

void RailCats_Locomotive::SetDirection(int DirectionIN){
    if(DirectionIN==1){
        direction=true;
    }else{
        direction=false;
    }
};

void RailCats_Locomotive::SetFn(int Fnum,int Pos){

    if(Fnum<255){
        FNs.at(Fnum)=Pos;
    }

};


int RailCats_Locomotive::GetAddress(){

    return address;

};
std::string RailCats_Locomotive::GetName(){

    return name;

};

int RailCats_Locomotive::GetSpeed(){

    return speed;

};

int RailCats_Locomotive::GetDirection(){

    if (direction){
        return 1;
    }

    return 0;
};

int RailCats_Locomotive::GetFn(int Fnum){

    if(Fnum<255){
        return FNs.at(Fnum);
    }

    return 0xffffffff;
};

RailCats_LocoCollection::RailCats_LocoCollection(){

    Iterator=0;
};
RailCats_LocoCollection::~RailCats_LocoCollection(){};

bool RailCats_LocoCollection::AddLoco(RailCats_Locomotive LocoIN){

    Collection.push_back(LocoIN);

    return true;
};

bool RailCats_LocoCollection::DelLoco(RailCats_Locomotive LocoIN){

    for (int i=0;i<Collection.size();i++){
        if(Collection.at(i).GetAddress()==LocoIN.GetAddress()){
            Collection.erase(Collection.begin()+i);
            return true;
        }
    }
       return false;
};


bool RailCats_LocoCollection::SetLoco(RailCats_Locomotive LocoIN){

    for(int i=0;i<Collection.size();i++){

        if(Collection.at(i).GetAddress()==LocoIN.GetAddress()){
            Collection.at(i)=LocoIN;
            return true;
        }


    }

    return false;
};

bool RailCats_LocoCollection::GetLoco(int AddressIN,RailCats_Locomotive * LocoIN){


    std::cout<<Collection.size()<<std::endl;
    for(int i=0;i<Collection.size();i++){

        if(Collection.at(i).GetAddress()==AddressIN){
            //LocoIN=&Collection.at(i);

            * LocoIN=Collection.at(i);

            return true;
        }
    }
};

bool RailCats_LocoCollection::GetNext(RailCats_Locomotive * LocoIN){

    std::cout<<"Iterator="<<Iterator<<std::endl;
    std::cout<<"Collection.size()="<<Collection.size()<<std::endl;
    if(Collection.size()==0){
        return false;
    }
    if(Iterator<Collection.size()-1){
        Iterator++;
    }else{
        Iterator=0;
    }

    //LocoIN->SetAddress(Collection.at(Iterator).GetAddress());
    //LocoIN->SetName(Collection.at(Iterator).GetName());

    * LocoIN=Collection.at(Iterator);
    return true;
};

bool RailCats_LocoCollection::GetPrev(RailCats_Locomotive * LocoIN){

    if(Collection.size()==0){
        return false;
    }

    if(Iterator>0){
        Iterator--;
    }else{
        Iterator=Collection.size()-1;
    }

    //LocoIN->SetAddress(Collection.at(Iterator).GetAddress());
    //LocoIN->SetName(Collection.at(Iterator).GetName());

    * LocoIN=Collection.at(Iterator);

    return true;

};


bool RailCats_LocoCollection::AddressCheck(int AddressIN){
    for(int i=0;i<Collection.size();i++){

        if(Collection.at(i).GetAddress()==AddressIN){
            return true;
        }
    }
    return false;
};


bool RailCats_LocoCollection::SaveToFile(std::string FileName){

    // check if we have void FileName
    if(FileName.length()==0){
           FileName="LocoCollection.xml";
    }

#ifdef RC_PLATFORM_WIN32

    TiXmlDocument XmlCollectionConfig(FileName.c_str());

#endif

#ifdef RC_PLATFORM_LINUX

    TiXmlDocument XmlCollectionConfig(FileName);

#endif

    TiXmlDeclaration * XmlDeclaration = new TiXmlDeclaration( "1.0", "koi8-r", "" );

    XmlCollectionConfig.LinkEndChild(XmlDeclaration);

    TiXmlElement * BodyElement = new TiXmlElement("Body");
    XmlCollectionConfig.LinkEndChild(BodyElement);


    for(int i=0;i<Collection.size();i++){

        RailCats_Locomotive TempLoco=Collection.at(i);

        TiXmlElement * LocoElement = new TiXmlElement( "Loco" );

#ifdef RC_PLATFORM_WIN32
        LocoElement->SetAttribute("Address",TempLoco.GetAddress());
        LocoElement->SetAttribute("Name",TempLoco.GetName().c_str());
        LocoElement->SetAttribute("Direction",TempLoco.GetDirection());
        LocoElement->SetAttribute("Speed",TempLoco.GetSpeed());
#endif

#ifdef RC_PLATFORM_LINUX
        LocoElement->SetAttribute("Address",TempLoco.GetAddress());
        LocoElement->SetAttribute("Name",TempLoco.GetName());
        LocoElement->SetAttribute("Direction",TempLoco.GetDirection());
        LocoElement->SetAttribute("Speed",TempLoco.GetSpeed());
#endif


        for(int fn=0;fn<255;fn++){
            std::string FName="F";
            std::string FNum;
            std::stringstream MYSS;
            MYSS<<fn;
            MYSS>>FNum;
            FName.append(FNum);
#ifdef RC_PLATFORM_WIN32
            LocoElement->SetAttribute(FName.c_str(),TempLoco.GetFn(fn));
#endif
#ifdef RC_PLATFORM_LINUX
            LocoElement->SetAttribute(FName,TempLoco.GetFn(fn));
#endif
        }

        BodyElement->LinkEndChild( LocoElement );

    }

    if(XmlCollectionConfig.SaveFile()){
        return true;
    }else{
        return false;
    }

};

bool RailCats_LocoCollection::LoadFromFile(std::string FileName){

    // check if we have void FileName
    if(FileName.length()==0){
           FileName="LocoCollection.xml";
    }

    RailCats_Locomotive TempLoco;

#ifdef RC_PLATFORM_WIN32
    TiXmlDocument XmlLocoConfig(FileName.c_str());
#endif
#ifdef RC_PLATFORM_LINUX
    TiXmlDocument XmlLocoConfig(FileName);
#endif

    if(XmlLocoConfig.LoadFile()){

        TiXmlNode* Body = 0;
        TiXmlElement* LocoElement = 0;

        Body = XmlLocoConfig.FirstChild("Body");
        if(Body==NULL){
            return false;
        };

        LocoElement = Body -> FirstChildElement("Loco");
        if(LocoElement==NULL){
            return false;
        };

        for (LocoElement;LocoElement;LocoElement=LocoElement->NextSiblingElement()){

            // next - load parameters

            std::string TempAddressString=static_cast<std::string>(LocoElement->Attribute("Address"));
            std::string TempNameString=static_cast<std::string>(LocoElement->Attribute("Name"));
            std::string TempDirectionString=static_cast<std::string>(LocoElement->Attribute("Direction"));
            std::string TempSpeedString=static_cast<std::string>(LocoElement->Attribute("Speed"));

            std::stringstream MYSS1;
            std::stringstream MYSS2;
            std::stringstream MYSS3;

            // Set Address
            MYSS1<<TempAddressString;
            int Address;
            MYSS1>>Address;
            TempLoco.SetAddress(Address);

            // Set name
            TempLoco.SetName(TempNameString);

            // Set Direction
            MYSS2<<TempDirectionString;
            int Direction;
            MYSS2>>Direction;
            TempLoco.SetDirection(Direction);

            // Set Speed

            MYSS3<<TempSpeedString;
            int Speed;
            MYSS3>>Speed;
            TempLoco.SetSpeed(Speed);

            for (int fn=0;fn<255;fn++){
                std::stringstream MYSS;
                MYSS<<fn;
                std::string FNum;
                MYSS>>FNum;
                std::string FName="F";
                FName.append(FNum);

                std::string TempFN=static_cast<std::string>(LocoElement->Attribute(FName.c_str()));

                std::stringstream MYSS1;
                MYSS1<<TempFN;
                int FNVal;
                MYSS1>>FNVal;
                TempLoco.SetFn(fn,FNVal);

            }

            std::cout<<TempLoco.GetName()<<std::endl;

            // fucking shit
            Collection.push_back(TempLoco);

        }


    }else{

        // Throw message to log

        //
        return false;

    }

    return true;


};
