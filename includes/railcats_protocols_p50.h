#ifndef railcats_protocols_P50
#define railcats_protocols_P50

#include "includes/build_settings.h"
#include "railcats_service.h"
#include <vector>

#ifdef RC_PLATFORM_WIN32

#include "Windows.h"

#endif

#ifdef RC_PLATFORM_LINUX

#include "termios.h"
#include "fcntl.h"
#include <sys/ioctl.h>

#endif

class RailCats_Protocols_P50_Commands{

    public:

        RailCats_Protocols_P50_Commands();
        int CommandLength;
        std::vector<unsigned char> Command;
        int ParamsLength;
        std::vector<unsigned char> Params;
        int AnswerLength;
        std::vector<unsigned char> Answer;

};

class RailCats_Protocols_P50_CommandQueue{

    public:
        RailCats_Protocols_P50_CommandQueue();

        int AddCommand(RailCats_Protocols_P50_Commands Command);
        std::vector<unsigned char> GetAnswer();

    private:

        std::vector<RailCats_Protocols_P50_Commands> Commands;
        int CommandCount;

};

class RailCats_Protocols_P50{

    public:
        RailCats_Protocols_P50();
//		RailCats_Protocols_P50_CommandQueue CQueue;

        bool InitSerial();
        bool CloseSerial();


        // P50x binary commands

        // ----- general purpose commands
        bool XPwrOn();
        bool XPwrOff();
        bool XHalt();

        bool XSOSet(unsigned char LByte,unsigned char HByte, unsigned char NValue);
        bool XSOGet(unsigned char LByte,unsigned char HByte); // need to return answer
        std::string XVer();
        bool XP50XCh(unsigned char NChar);
        bool XStatus();
        bool XNOP();

        // ----- sensors related commands

        // ----- events related commands



        // ----- Loco commands

        bool XLok(unsigned char LLokAddr, unsigned char HLokAddr, unsigned char Speed, unsigned char Options);
        bool XLokSts(unsigned char LLokAddr, unsigned char HLokAddr);
        bool XLokCfg(unsigned char LLokAddr, unsigned char HLokAddr);
        bool XLkDisp(unsigned char LLokAddr, unsigned char HLokAddr);
        bool XFunc(unsigned char LLokAddr, unsigned char HLokAddr, unsigned char Status);
        bool XFuncSts(unsigned char LLokAddr, unsigned char HLokAddr);

        // ----- Turnouts commands

        bool XTrnt(unsigned char LTrntAddr, unsigned char HTrntAddr);
        bool XTrntFree();
        bool XTrntSts(unsigned char LTrntAddr, unsigned char HTrntAddr);
        bool XTrntGrp(unsigned char TrntGrpAddr1, unsigned char TrntGrpAddr2);



        // p50xb PT protcol
        // General use
        bool XPTSts();
        bool XPTOn();
        bool XPTOff();
        bool XEvtPT();
        bool XPTTerm();

        // DCC
        bool XPTDCCSr();
        bool XPTDCCQa();
        bool XPTDCCRr();
        bool XPTDCCWr();
        bool XPTDCCRp();
        bool XPTDCCWp();
        bool XPTDCCRd();
        bool XPTDCCWd();
        bool XPTDCCRb();
        bool XPTDCCWb();
        bool XPTDCCQd();
        bool XPTDCCRl();
        bool XPTDCCWl();
        bool XPTDCCRa();
        bool XPTDCCWa();
        bool XPTDCCEWr();

    protected:


    private:


#ifdef RC_PLATFORM_WIN32

        HANDLE COMHandle;

#endif

#ifdef RC_PLATFORM_LINUX

        int COMHandle;

#endif
        RailCats_Service MyService;

        bool SerialState;

        bool SerialTxRx(unsigned char CmdCode,unsigned char *CmdParam, int CmdParamLen, unsigned char *CmdAnswer, int  CmdAnswerLen, bool multibyte);




};

#endif
