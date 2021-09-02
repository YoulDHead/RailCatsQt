#include "includes/build_settings.h"
#include "railcats_connector_p50.h"
#include <sstream>

RailCats_Connector_p50_Loco_Decoder_DCC::RailCats_Connector_p50_Loco_Decoder_DCC(){

    HWAddress=0;
    Steps=0;
    LAddress=0;

};

RailCats_Connector_p50_Loco_Decoder_DCC::~RailCats_Connector_p50_Loco_Decoder_DCC(){};

void RailCats_Connector_p50_Loco_Decoder_DCC::SetHWAddress(int address){

    HWAddress=address;

};

void RailCats_Connector_p50_Loco_Decoder_DCC::SetSteps(int steps){

    Steps=steps;
};

void RailCats_Connector_p50_Loco_Decoder_DCC::SetLAddress(int ladress){

    LAddress=ladress;
};



int RailCats_Connector_p50_Loco_Decoder_DCC::GetHWAddress(){

    return HWAddress;
};

int RailCats_Connector_p50_Loco_Decoder_DCC::GetSteps(){

    return Steps;

};
int RailCats_Connector_p50_Loco_Decoder_DCC::GetLAddress(){

    return LAddress;

};





RailCats_Connector_p50::RailCats_Connector_p50(){


	ConnectorState=Uninitialized;
	Name="RailCats P50 binary Connector";
    EmergencyStopped=false;


};

RailCats_Connector_p50::~RailCats_Connector_p50(){};


int RailCats_Connector_p50::GetConnectorState(){
	MyService.ThrowLog(0,"RailCats_Connector_p50: GetConnectorState");
	return ConnectorState;
};

bool RailCats_Connector_p50::GoConnect(){
	MyService.ThrowLog(0,"RailCats_Connector_p50: GoConnect");


	// Init ComPort
	if(Protocol.InitSerial()){
		// we re connected to serial
		ConnectorState=Connected;

		// check protocol states

		return true;
	}else{
		// oops, cant connect to station
		ConnectorState=Disconnected;
		return false;
	}

	ConnectorState=Defunct;
	return false;
};

bool RailCats_Connector_p50::GoDisconnect(){
	MyService.ThrowLog(0,"RailCats_Connector_p50: GoDisconnect");

	if(Protocol.CloseSerial()){
		ConnectorState=Disconnected;
		return true;
	}else{
		return false;
	}


	return false;
};

bool RailCats_Connector_p50::GoDefunct(){
	MyService.ThrowLog(0,"RailCats_Connector_p50: GoDefunct");

	ConnectorState=Defunct;
	return true;
};



bool RailCats_Connector_p50::GoQueue(){

    return true;
};

bool RailCats_Connector_p50::GetEmergencyStopState(){

    return EmergencyStopped;

}

void RailCats_Connector_p50::EmergencyStop(){

    if(!EmergencyStopped){
        Protocol.XHalt();
        EmergencyStopped=true;
    }else{
        Protocol.XPwrOn();
        EmergencyStopped=false;
    }


};

// loco functions



bool RailCats_Connector_p50::LocoExecute(RailCats_Locomotive * LocoIN){

    RailCats_Service RailCats_Service;
    RailCats_Service.ThrowLog(3,"LocoExecute");

    if(ConnectorState==Connected && LocoIN!=NULL){

        unsigned char LAddr; // low address byte
        unsigned char HAddr; // high address byte
        unsigned char Speed; // speed in steps (0, 1- EMstop, steps)
        unsigned char Opt;  // Options
        unsigned char Funcs; // Functions

        for (int i=0;i<LocoDecoders.size();i++){

            std::cout<<"LocoLA="<<LocoDecoders.at(i).GetLAddress()<<std::endl;
            std::cout<<"LocoINLA="<<LocoIN->GetAddress()<<std::endl;


            if(LocoDecoders.at(i).GetLAddress()==LocoIN->GetAddress()){

                //Prepare LAddr and HAddr

                int TempHWAddr=LocoDecoders.at(i).GetHWAddress();

                std::stringstream MYSS;
                std::string tempString;
                MYSS<<TempHWAddr;
                MYSS>>tempString;

                tempString.append(" hwaddr");

                RailCats_Service.ThrowLog(3,tempString);

                LAddr=TempHWAddr;
                HAddr=TempHWAddr>>8;

                // prepare speed ( %->steps)

                Speed=(LocoDecoders.at(i).GetSteps()/100)*LocoIN->GetSpeed();

                if(Speed==1){
                    Speed=2;
                };

                // prepare functions

                Opt=0;

                // add direction

                if (LocoIN->GetDirection()==1){
                    Opt = 0x20;
                }

                std::cout<<"FL="<<LocoIN->GetFn(0)<<std::endl;

                if(LocoIN->GetFn(0)==1){
                    Opt = Opt + 0x10;
                }


                Funcs=0;



                for (int n=0;n<=8;n++){
                    Funcs |= (LocoIN->GetFn(n)<<n);
                }


                {
                std::stringstream MYSS1;
                int a=Opt;
                MYSS1<<std::hex<<a;
                std::string tempStr;
                MYSS1>>tempStr;

                std::cout<<"OPT="<<tempStr<<std::endl;
                }

                break;
            }
        }

       bool res = Protocol.XLok(LAddr, HAddr, Speed, Opt);

 //      res = Protocol.XFunc(LAddr,HAddr,Funcs);
       //std::string res = Protocol.XVer();


    }else{
        RailCats_Service.ThrowLog(3,"Not connected, or locomotive == null");
    };

    return false;

};

bool RailCats_Connector_p50::MapLocoToDecoder(RailCats_Locomotive * LocoIN, RailCats_Connector_p50_Loco_Decoder_DCC * DecoderIN){


    RailCats_Connector_p50_Loco_Decoder_DCC TempDecoder;


    //DecoderProg decoderWindow;

    //decoderWindow.setWindowModality(Qt::ApplicationModal);
    //std::cout<<"DEcoder show"<<std::endl;
    //decoderWindow.show();
    //std::cout<<"Decoder show stop"<<std::endl;

    TempDecoder.SetHWAddress(DecoderIN->GetHWAddress());
    TempDecoder.SetLAddress(DecoderIN->GetLAddress());
    TempDecoder.SetSteps(DecoderIN->GetSteps());


    std::cout<<"DecHW="<<TempDecoder.GetHWAddress()<<std::endl;
    std::cout<<"DecLA="<<TempDecoder.GetLAddress()<<std::endl;
    std::cout<<"DecSteps="<<TempDecoder.GetSteps()<<std::endl;

    LocoDecoders.push_back(TempDecoder);

    return true;

};



bool RailCats_Connector_p50::SaveDecodersToFile(std::string FileName){

    // check if we have void FileName
    if(FileName.length()==0){
           FileName="DecodersLoco.xml";
    }
#ifdef RC_PLATFORM_WIN32
    TiXmlDocument XmlDecodersConfig(FileName.c_str());
#endif

#ifdef RC_PLATFORM_LINUX
    TiXmlDocument XmlDecodersConfig(FileName);
#endif


    TiXmlDeclaration * XmlDeclaration = new TiXmlDeclaration( "1.0", "koi8-r", "" );

    XmlDecodersConfig.LinkEndChild(XmlDeclaration);

    TiXmlElement * BodyElement = new TiXmlElement("Body");
    XmlDecodersConfig.LinkEndChild(BodyElement);


    for(int i=0;i<LocoDecoders.size();i++){

        TiXmlElement * DecoderElement = new TiXmlElement( "Decoder" );

        DecoderElement->SetAttribute("HWAddress",LocoDecoders.at(i).GetHWAddress());
        DecoderElement->SetAttribute("Steps",LocoDecoders.at(i).GetSteps());
        DecoderElement->SetAttribute("LAddress",LocoDecoders.at(i).GetLAddress());

        BodyElement->LinkEndChild( DecoderElement );

    }

    if(XmlDecodersConfig.SaveFile()){
        return true;
    }else{
        return false;
    }



};

bool RailCats_Connector_p50::LoadDecodersFromFile(std::string FileName){

    // check if we have void FileName
    if(FileName.length()==0){
           FileName="DecodersLoco.xml";
    }

    RailCats_Connector_p50_Loco_Decoder_DCC TempDecoder;

#ifdef RC_PLATFORM_WIN32
    TiXmlDocument XmlDecodersConfig(FileName.c_str());
#endif

#ifdef RC_PLATFORM_LINUX
    TiXmlDocument XmlDecodersConfig(FileName);
#endif
    if(XmlDecodersConfig.LoadFile()){

        TiXmlNode* Body = 0;
        TiXmlElement* DecoderElement = 0;

        Body = XmlDecodersConfig.FirstChild("Body");
        if(Body==NULL){
            return false;
        };

        DecoderElement = Body -> FirstChildElement("Decoder");
        if(DecoderElement==NULL){
            return false;
        };

        // next - load parameters

           std::string TempHWAddressString=static_cast<std::string>(DecoderElement->Attribute("HWAddress"));
        std::string TempLAddressString=static_cast<std::string>(DecoderElement->Attribute("LAddress"));
        std::string TempStepsString=static_cast<std::string>(DecoderElement->Attribute("Steps"));

        std::stringstream MYSS1;
        MYSS1<<TempHWAddressString;
        int HWAddress;
        MYSS1>>HWAddress;
        TempDecoder.SetHWAddress(HWAddress);

        std::stringstream MYSS2;
        MYSS2<<TempLAddressString;
        int LAddress;
        MYSS2>>LAddress;
        TempDecoder.SetLAddress(LAddress);

        std::stringstream MYSS3;
        MYSS3<<TempStepsString;
        int Steps;
        MYSS3>>Steps;
        TempDecoder.SetSteps(Steps);


        // next is fucking shit !!!

        LocoDecoders.push_back(TempDecoder);

    }else{

        // Throw message to log

        //
        return false;

    }

    return true;


};


bool RailCats_Connector_p50::AddDecoder(RailCats_Connector_p50_Loco_Decoder_DCC DecoderIN){

        LocoDecoders.push_back(DecoderIN);

        return true;
};
