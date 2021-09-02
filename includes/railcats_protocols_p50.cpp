#include "includes/build_settings.h"
#include "railcats_protocols_p50.h"



#include <string>
#include <iostream>

RailCats_Protocols_P50_Commands::RailCats_Protocols_P50_Commands(){

    CommandLength=0;
    AnswerLength=0;

}

RailCats_Protocols_P50_CommandQueue::RailCats_Protocols_P50_CommandQueue(){
    CommandCount=0;
}

int RailCats_Protocols_P50_CommandQueue::AddCommand(RailCats_Protocols_P50_Commands Command){
    return 0;
}

RailCats_Protocols_P50::RailCats_Protocols_P50(){

    COMHandle=0;
    SerialState=false;

}

bool RailCats_Protocols_P50::XPTSts(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTSts");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [2];

    if(SerialTxRx(0xE0,Param,0,Answer,2,false)){

//		do something with answer

    };

    return true;


}

bool RailCats_Protocols_P50::XPTOn(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTOn");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xE1,Param,0,Answer,0,false)){

//		do something with answer

    };

    return true;


}

bool RailCats_Protocols_P50::XPTOff(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTOff");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xE2,Param,0,Answer,1,false)){

//		do something with answer

    };

    return true;


}

bool RailCats_Protocols_P50::XEvtPT(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XEvtPT");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xCE,Param,0,Answer,7,true)){

//		do something with answer

    };

    return true;

}

bool RailCats_Protocols_P50::XPTTerm(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTTerm");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xFE,Param,0,Answer,1,false)){

//		do something with answer

    };

    return true;


}


bool RailCats_Protocols_P50::XPTDCCSr(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCSr");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xEA,Param,0,Answer,1,false)){

//		do something with answer

    };

    return true;
}

bool RailCats_Protocols_P50::XPTDCCQa(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCQa");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xEB,Param,0,Answer,1,false)){

//		do something with answer

    };

    return true;
}

bool RailCats_Protocols_P50::XPTDCCRr(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCRr");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xEC,Param,2,Answer,0,false)){

//		do something with answer

    };

    return true;
}

bool RailCats_Protocols_P50::XPTDCCWr(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCWr");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xED,Param,3,Answer,0,false)){

//		do something with answer

    };

    return true;
}

bool RailCats_Protocols_P50::XPTDCCRp(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCRp");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xEE,Param,2,Answer,0,false)){

//		do something with answer

    };

    return true;
}

bool RailCats_Protocols_P50::XPTDCCWp(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCWp");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xEF,Param,3,Answer,0,false)){

//		do something with answer

    };

    return true;
}

bool RailCats_Protocols_P50::XPTDCCRd(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCRd");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xF0,Param,2,Answer,0,false)){

//		do something with answer

    };

    return true;
}

bool RailCats_Protocols_P50::XPTDCCWd(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCWd");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xF1,Param,3,Answer,0,false)){

//		do something with answer

    };

    return true;
}

bool RailCats_Protocols_P50::XPTDCCRb(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCRb");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xF2,Param,2,Answer,0,false)){

//		do something with answer

    };

    return true;
}

bool RailCats_Protocols_P50::XPTDCCWb(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCWb");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xF3,Param,4,Answer,0,false)){

//		do something with answer

    };

    return true;
}

bool RailCats_Protocols_P50::XPTDCCQd(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCQd");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xF4,Param,0,Answer,0,false)){

//		do something with answer

    };

    return true;
}

bool RailCats_Protocols_P50::XPTDCCRl(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCRl");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xF5,Param,0,Answer,0,false)){

//		do something with answer

    };

    return true;
}

bool RailCats_Protocols_P50::XPTDCCWl(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCWl");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xF6,Param,2,Answer,0,false)){

//		do something with answer

    };

    return true;
}

bool RailCats_Protocols_P50::XPTDCCRa(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCRa");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xF7,Param,0,Answer,0,false)){

//		do something with answer

    };

    return true;
}

bool RailCats_Protocols_P50::XPTDCCWa(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCWa");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xF8,Param,2,Answer,0,false)){

//		do something with answer

    };

    return true;
}

bool RailCats_Protocols_P50::XPTDCCEWr(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPTDCCEWr");

    unsigned char *Param = new unsigned char [0];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0xF8,Param,4,Answer,0,false)){

//		do something with answer

    };

    return true;
}


bool RailCats_Protocols_P50::XTrntGrp(unsigned char TrntGrpAddr1, unsigned char TrntGrpAddr2){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XTrntGrp");

    unsigned char *Param = new unsigned char [2];
    unsigned char *Answer = new unsigned char [3];
    Param[0]=TrntGrpAddr1;
    Param[1]=TrntGrpAddr2;

    if(SerialTxRx(0x95,Param,2,Answer,3,false)){

//		do something with answer

    };

    return true;

}


bool RailCats_Protocols_P50::XTrntSts(unsigned char LTrntAddr, unsigned char HTrntAddr){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XTrntSts");

    unsigned char *Param = new unsigned char [2];
    unsigned char *Answer = new unsigned char [2];
    Param[0]=LTrntAddr;
    Param[1]=HTrntAddr;

    if(SerialTxRx(0x94,Param,3,Answer,2,false)){

//		do something with answer

    };

    return true;

}


bool RailCats_Protocols_P50::XTrntFree(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XTrntFree");

    unsigned char *Param = new unsigned char [1];
    unsigned char *Answer = new unsigned char [1];

    if(SerialTxRx(0x93,Param,0,Answer,1,false)){

//		do something with answer

    };

    return true;

}


bool RailCats_Protocols_P50::XTrnt(unsigned char LTrntAddr, unsigned char HTrntAddr){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XTrnt");

    unsigned char *Param = new unsigned char [3];
    unsigned char *Answer = new unsigned char [1];
    Param[0]=LTrntAddr;
    Param[1]=HTrntAddr;

    if(SerialTxRx(0x90,Param,3,Answer,1,false)){

//		do something with answer

    };

    return true;

}


bool RailCats_Protocols_P50::XFuncSts(unsigned char LLokAddr, unsigned char HLokAddr){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XFuncSts");

    unsigned char *Param = new unsigned char [3];
    unsigned char *Answer = new unsigned char [2];
    Param[0]=LLokAddr;
    Param[1]=HLokAddr;

    if(SerialTxRx(0x8C,Param,3,Answer,2,false)){

//		do something with answer

    };

    return true;

}

bool RailCats_Protocols_P50::XFunc(unsigned char LLokAddr, unsigned char HLokAddr, unsigned char Status){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XFunc");

    unsigned char *Param = new unsigned char [3];
    unsigned char *Answer = new unsigned char [1];
    Param[0]=LLokAddr;
    Param[1]=HLokAddr;
    Param[2]=Status;

    if(SerialTxRx(0x88,Param,3,Answer,1,false)){

//		do something with answer

    };

    return true;

}

bool RailCats_Protocols_P50::XLkDisp(unsigned char LLokAddr, unsigned char HLokAddr){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XLkDisp");

    unsigned char *Param = new unsigned char [2];
    unsigned char *Answer = new unsigned char [1];
    Param[0]=LLokAddr;
    Param[1]=HLokAddr;

    if(SerialTxRx(0x83,Param,2,Answer,1,false)){

//		do something with answer

    };

    return true;

}


bool RailCats_Protocols_P50::XLokCfg(unsigned char LLokAddr, unsigned char HLokAddr){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XLokCfg");

    unsigned char *Param = new unsigned char [2];
    unsigned char *Answer = new unsigned char [5];
    Param[0]=LLokAddr;
    Param[1]=HLokAddr;

    if(SerialTxRx(0x85,Param,2,Answer,5,false)){

//		do something with answer

    };

    return true;

}


bool RailCats_Protocols_P50::XLokSts(unsigned char LLokAddr, unsigned char HLokAddr){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XLokSts");

    unsigned char *Param = new unsigned char [2];
    unsigned char *Answer = new unsigned char [4];
    Param[0]=LLokAddr;
    Param[1]=HLokAddr;

    if(SerialTxRx(0x84,Param,2,Answer,4,false)){

//		do something with answer

    };

    return true;

}

bool RailCats_Protocols_P50::XLok(unsigned char LLokAddr, unsigned char HLokAddr, unsigned char Speed, unsigned char Options){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XLok");

    unsigned char *Param = new unsigned char [4];
    unsigned char *Answer = new unsigned char [1];
    Param[0]=LLokAddr;
    Param[1]=HLokAddr;
    Param[2]=Speed;
    Param[3]=Options;

    if(SerialTxRx(0x80,Param,4,Answer,1,false)){

//		do something with answer

    };

    return true;


};

bool RailCats_Protocols_P50::XPwrOn(){


    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPwrOn");

    unsigned char *Param = new unsigned char [1];
    unsigned char *Answer = new unsigned char [1];
    Param[0]=0;

    if(SerialTxRx(0xA7,Param,0,Answer,1,false)){


//		do something with answer

    };

    return true;

};

bool RailCats_Protocols_P50::XPwrOff(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XPwrOff");

    unsigned char *Param = new unsigned char [1];
    unsigned char *Answer = new unsigned char [1];
    Param[0]=0;

    if(SerialTxRx(0xA6,Param,0,Answer,1,false)){

//		do something with answer

    };

    return true;
};

bool RailCats_Protocols_P50::XHalt(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XHalt");

    unsigned char *Param = new unsigned char [1];
    unsigned char *Answer = new unsigned char [1];
    Param[0]=0;

    if(SerialTxRx(0xA5,Param,0,Answer,1,false)){

//		do something with answer

    };

    return true;
};


bool RailCats_Protocols_P50::XSOSet(unsigned char LByte,unsigned char HByte, unsigned char NValue){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XSOSet");

    unsigned char *Param = new unsigned char [3];
    unsigned char *Answer = new unsigned char [1];
    Param[0]=LByte;
    Param[1]=HByte;
    Param[2]=NValue;

    if(SerialTxRx(0xA3,Param,3,Answer,1,false)){

//		do something with answer

    };

    return true;
};

bool RailCats_Protocols_P50::XSOGet(unsigned char LByte,unsigned char HByte)
{

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XSOGet");

    unsigned char *Param = new unsigned char [3];
    unsigned char *Answer = new unsigned char [2];
    Param[0]=LByte;
    Param[1]=HByte;


    if(SerialTxRx(0xA4,Param,2,Answer,2,false)){

//		do something with answer

    };

    return true;
}

std::string RailCats_Protocols_P50::XVer(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XVer");

    std::string OutString="";

    unsigned char *Param = new unsigned char [2];
    unsigned char *Answer = new unsigned char [2];

    if(SerialTxRx(0xA0,Param,0,Answer,255,true)){

//		do something with answer

    };

    return OutString;
}

bool RailCats_Protocols_P50::XP50XCh(unsigned char NChar){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XP50XCh");

    unsigned char *Param = new unsigned char [2];
    unsigned char *Answer = new unsigned char [2];

    Param[0]=NChar;

    if(SerialTxRx(0xA1,Param,1,Answer,0,false)){

//		do something with answer

    };

    return true;
};


bool RailCats_Protocols_P50::XStatus(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XStatus");

    unsigned char *Param = new unsigned char [2];
    unsigned char *Answer = new unsigned char [2];


    if(SerialTxRx(0xA2,Param,0,Answer,1,false)){

//		do something with answer

    };

    return true;
};

bool RailCats_Protocols_P50::XNOP(){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: XNOP");

    unsigned char *Param = new unsigned char [2];
    unsigned char *Answer = new unsigned char [2];


    if(SerialTxRx(0xC4,Param,0,Answer,1,false)){

//		do something with answer

    };

    return true;
};

#ifdef RC_PLATFORM_LINUX

bool RailCats_Protocols_P50::SerialTxRx(unsigned char CmdCode,unsigned char *CmdParam, int CmdParamLen, unsigned char *CmdAnswer, int CmdAnswerLen, bool multibyte){



    MyService.ThrowLog(0,"RailCats_Protocols_P50: SerialTxRx");

    std::cout<<"CmdParamLen"<<CmdParamLen<<" CmdAnswerLen="<<CmdAnswerLen<<std::endl;

    unsigned char *EncodedCommand = new unsigned char [CmdParamLen+4+2];
    unsigned char *bufptr;
    bufptr=EncodedCommand;

    EncodedCommand[0]=0x78;
    EncodedCommand[1]=CmdCode;	// Command Code

    for (int i=0;i<CmdParamLen;i++){
        EncodedCommand[i+2]=CmdParam[i]; // copy parameters to encoded command
    }


    for (int a=0;a<CmdParamLen+2;a++){
        int b=EncodedCommand[a];
        std::cout<<"0x"<<std::hex<<b<<" ";
    }

    std::cout<<std::endl;

    MyService.ThrowLog(0,"RailCats_Protocols_P50: SerialTxRx - TX");

    int res=write(COMHandle,EncodedCommand,CmdParamLen+2);

    std::cout<<"write - bytes="<<res<<std::endl;

    res=0;
    while (res==0){
        res = read(COMHandle,CmdAnswer,1);
    }

    std::cout<<"First read byte="<<res<<std::endl;

    if (multibyte){
        res=read(COMHandle,CmdAnswer,res);
        std::cout<<"Second read MultiByte="<<res<<" CmdAnswerLen="<<CmdAnswerLen<<std::endl;
        for (int a=0;a<res;a++){
            int b=CmdAnswer[a];
            std::cout<<"0x"<<std::hex<<b<<" ";
        }
    }else{

        std::cout<<"Second read OneByte="<<res<<" CmdAnswerLen="<<CmdAnswerLen<<std::endl;
        for (int a=0;a<CmdAnswerLen;a++){
            int b=CmdAnswer[a];
            std::cout<<"0x"<<std::hex<<b<<" ";
        }

    }

    std::cout<<std::endl;

    MyService.ThrowLog(0,"RailCats_Protocols_P50: SerialTxRx end");

    return true;
};


bool RailCats_Protocols_P50::CloseSerial(){
    MyService.ThrowLog(0,"RailCats_Protocols_P50: CloseSerial");
    if(0!=COMHandle or SerialState!=true){

        close(COMHandle);
        MyService.ThrowLog(0,"RailCats_Protocols_P50: CloseSerial - Closed");
        return true;
        SerialState=false;
    }else{
        MyService.ThrowLog(0,"RailCats_Protocols_P50: CloseSerial - Not open");
        return false;
    }

    return false;

}

bool RailCats_Protocols_P50::InitSerial(){


    MyService.ThrowLog(0,"RailCats_Protocols_P50: InitSerial");

    if (SerialState){
        MyService.ThrowLog(0,"RailCats_Protocols_P50: InitSerial - Already connected");
        return false;
    };


    COMHandle = open("/dev/ttyUSB0",O_RDWR|O_NOCTTY|O_NDELAY|O_NONBLOCK);

    if (COMHandle == -1){
        MyService.ThrowLog(0,"RailCats_Protocols_P50: InitSerial - Cant open COM-port");
        return false;
    }else{
        fcntl(COMHandle, F_SETFL,0);


        struct termios options;

        bzero(&options,sizeof(options));

        //tcgetattr(COMHandle,&options);


 //       cfsetispeed(&options,B19200);		// set baudrate
   //     cfsetospeed(&options,B19200);


        options.c_cflag=(B19200|CLOCAL|CREAD|CS8|CRTSCTS);

        /*options.c_cflag |= (CLOCAL|CREAD);	// must be always enabled!!
        //options.c_cflag &= ~PARENB;		// Parity OFF
        options.c_cflag |= CS8;			// 8 bits
        options.c_cflag &= ~CSTOPB;		// 1 stop bits
        options.c_cflag &= ~CSIZE;		// 1 stop bits
        options.c_cflag |= CRTSCTS;
        options.c_cflag |= HUPCL;

//		options.c_cflag &= ~PARODD;		// Even parity

//		options.c_iflag |= (INPCK|ISTRIP);	// Enable input parity checking
//		options.c_iflag |= (IXON|IXOFF);	// Enable XON XOFF flow control
*/
        tcsetattr(COMHandle,TCSANOW,&options);




        MyService.ThrowLog(0,"RailCats_Protocols_P50: InitSerial - COM-port succsessfully opened");

    }

    return true;

};

#endif

#ifdef RC_PLATFORM_WIN32


bool RailCats_Protocols_P50::SerialTxRx(unsigned char CmdCode,unsigned char *CmdParam, int CmdParamLen, unsigned char *CmdAnswer, int CmdAnswerLen, bool multibyte){

    MyService.ThrowLog(0,"RailCats_Protocols_P50: SerialTxRx");

    std::cout<<"CmdParamLen"<<CmdParamLen<<" CmdAnswerLen="<<CmdAnswerLen<<std::endl;

    unsigned char * EncodedCommand = new unsigned char [CmdParamLen+4+2];
    unsigned char *bufptr;
    bufptr=EncodedCommand;

    EncodedCommand[0]=0x78;
    EncodedCommand[1]=CmdCode;	// Command Code

    for (int i=0;i<CmdParamLen;i++){
        EncodedCommand[i+2]=CmdParam[i]; // copy parameters to encoded command
    }


    for (int a=0;a<CmdParamLen+2;a++){
        int b=EncodedCommand[a];
        std::cout<<"0x"<<std::hex<<b<<" ";
    }

    std::cout<<std::endl;

    MyService.ThrowLog(0,"RailCats_Protocols_P50: SerialTxRx - TX");

    DWORD bytes_write=0;
    std::cout<<"comhandle="<<COMHandle<<std::endl;

    DWORD lpErrors;
    COMSTAT lpStat;

    ClearCommError(COMHandle,&lpErrors,&lpStat);

    std::cout<<"lperrors="<<lpErrors<<std::endl;

    int res=WriteFile(COMHandle,(LPCVOID)EncodedCommand,(CmdParamLen+2),&bytes_write,NULL);

    std::cout<<"res="<<res<<std::endl;
    std::cout<<"write bytes="<<bytes_write<<std::endl;
/*
    res=0;
    int bytes_in=0;
    while (bytes_in==0){
        res = ReadFile(COMHandle,CmdAnswer,1,(LPDWORD)bytes_in,NULL);
        std::cout<<"res="<<res<<" bytes_in="<<bytes_in<<std::endl;
    }

    std::cout<<"First read byte="<<res<<std::endl;

    if (multibyte){
        res=ReadFile(COMHandle,CmdAnswer,bytes_in,NULL,NULL);
        std::cout<<"Second read MultiByte="<<res<<" CmdAnswerLen="<<CmdAnswerLen<<std::endl;
        for (int a=0;a<res;a++){
            int b=CmdAnswer[a];
            std::cout<<"0x"<<std::hex<<b<<" ";
        }
    }else{

        std::cout<<"Second read OneByte="<<res<<" CmdAnswerLen="<<CmdAnswerLen<<std::endl;
        for (int a=0;a<CmdAnswerLen;a++){
            int b=CmdAnswer[a];
            std::cout<<"0x"<<std::hex<<b<<" ";
        }

    }
*/
    std::cout<<std::endl;

    MyService.ThrowLog(0,"RailCats_Protocols_P50: SerialTxRx end");

    return true;
}

bool RailCats_Protocols_P50::CloseSerial(){


    MyService.ThrowLog(0,"RailCats_Protocols_P50: CloseSerial");
    if(0!=COMHandle || SerialState!=true){

        int result=CloseHandle(COMHandle);
        if(result!=0){
            MyService.ThrowLog(0,"RailCats_Protocols_P50: CloseSerial - Closed");
            SerialState=false;
            return true;
        }else{
            MyService.ThrowLog(0,"RailCats_Protocols_P50: CloseSerial - unexpected error");
            return false;
        }

    }else{
        MyService.ThrowLog(0,"RailCats_Protocols_P50: CloseSerial - Not open");
        return false;
    }

    return false;
}

bool RailCats_Protocols_P50::InitSerial(){


    MyService.ThrowLog(0,"RailCats_Protocols_P50: InitSerial");

    if (SerialState){
        MyService.ThrowLog(0,"RailCats_Protocols_P50: InitSerial - Already connected");
        return false;
    };


    // open handle
    COMHandle = CreateFileA("//./COM3", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
    if (COMHandle!=INVALID_HANDLE_VALUE){

        std::cout<<"handle="<<COMHandle<<std::endl;
            // structure
            DCB hCommSettings;

            // get serial port settings
            if(GetCommState(COMHandle,&hCommSettings)){

                // fill port settings with my own settings
                // baudrate
                hCommSettings.BaudRate=CBR_19200;
                // bitsize 8(N1)
                hCommSettings.ByteSize=8;
                // parity checking
                hCommSettings.Parity=NOPARITY;
                // stop bits 1
                hCommSettings.StopBits=ONESTOPBIT;

                // Set serial port settings
                if(SetCommState(COMHandle,&hCommSettings)){

                                    // Timeoputs realised by

                       COMMTIMEOUTS RC_timeouts;
                       GetCommTimeouts(COMHandle,&RC_timeouts);
                       RC_timeouts.WriteTotalTimeoutConstant=0;
                       RC_timeouts.WriteTotalTimeoutMultiplier=0;
                       SetCommTimeouts(COMHandle,&RC_timeouts);
                                    // GetCommTimeouts
                                    // SetCommTimeouts

                    // now we're ready to read|write operations

                                    // WriteFile()
                                    // ReadFile
                    MyService.ThrowLog(0,"RailCats_Protocols_P50: InitSerial - COM-port succsessfully opened");
                    return true;
                }else{
                    MyService.ThrowLog(0,"RailCats_Protocols_P50: InitSerial - Can't set COM-port properties");
                    return false;
                }

            }else{
                MyService.ThrowLog(0,"RailCats_Protocols_P50: InitSerial - Can't get COM-port properties");
                return false;
            }

    }else{

        MyService.ThrowLog(0,"RailCats_Protocols_P50: InitSerial - Cant open COM-port");
        return false;

    }

    return false;
}
#endif
