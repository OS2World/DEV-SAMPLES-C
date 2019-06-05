/*        MAIN.C

        Alternate, standalone main() file.  Demonstrates
        linking to the startup code without having to link to
        any of the (MS-DOS dependent) Turbo C library routines.

*/

#include "DOSCALLS.H"
#include "SUBCALLS.H"
#include <STRING.H>

exit(int retcode) {DosExit(1,retcode);}

int ComHandle;
char *DialPrefix, *DialSuffix, *HangUp;
char error[] = "Error -- code = 0000\n";

PutC(int handle, char c)
{
int retcode, BytesOut;
        retcode = DosWrite(handle,&c,1,&BytesOut);
        if (BytesOut != 1) PutS(2,"DosWrite problem in PutC");
        if (retcode) {
            error[16] = (retcode / 1000) % 10 + '0';
            error[17] = (retcode / 100 ) % 10 + '0';
            error[18] = (retcode / 10  ) % 10 + '0';
            error[19] = (retcode / 1   ) % 10 + '0';
            PutS(2,error);
        }
}

PutS(int handle, char *string)
{
int i, retcode, BytesOut;
        retcode = DosWrite(handle,string,i=strlen(string),&BytesOut);
        if (BytesOut != i) PutS(2,"DosWrite problem in PutS");
        if (retcode) {
            error[16] = (retcode / 1000) % 10 + '0';
            error[17] = (retcode / 100 ) % 10 + '0';
            error[18] = (retcode / 10  ) % 10 + '0';
            error[19] = (retcode / 1   ) % 10 + '0';
            PutS(2,error);
        }
}

TellModem(char *command)
{
int i;
        for (i=0;command[i]!=0;i++) {
            if (command[i] == '\\') {
                switch (command[++i]) {
                    case 'n': PutS(ComHandle,"\015\012");
                              break;
                    case 'p': DosSleep(1000);
                              break;
                    default:  PutC(ComHandle,command[i]);
                }
            } else {
              PutC(ComHandle,command[i]);
            }
        }
}

void far ReadCom()
{
int BytesIn, row, col;
char Buffer;
    while (1) {
        DosRead(ComHandle,&Buffer,1,&BytesIn);
        if (Buffer != '\033') {
            VioWrtTTY(&Buffer,1,0);
        } else {
            DosRead(ComHandle,&Buffer,1,&BytesIn);
            switch (Buffer) {
                case 'Y': DosRead(ComHandle,&Buffer,1,&BytesIn);
                          row = Buffer - ' ';
                          DosRead(ComHandle,&Buffer,1,&BytesIn);
                          col = Buffer - ' ';
                          VioSetCurPos(row,col,0);
                          break;
                case 'J': VioScrollUp(0,0,-1,-1,-1," \007",0);
                          break;
            }
        }
    }
}

void far WriteCom()
{
int i, BytesIn;
static char number[20];
KBDDATA Buffer;
    while (1) {
        KbdCharIn(&Buffer,0,0);
        if ((Buffer.cCharCode == 0) || (Buffer.cCharCode == 224)) {
            switch (Buffer.cScanCode) {
/* F2 */        case 60: PutS(ComHandle,"\033m");
                         break;
/* up arrow */  case 72: PutS(ComHandle,"\033A");
                         break;
/* dn arrow */  case 80: PutS(ComHandle,"\033B");
                         break;
/* right */     case 77: PutS(ComHandle,"\033C");
                         break;
/* left */      case 75: PutS(ComHandle,"\033D");
                         break;
/* Alt-X */     case 45: PutS(1,"\015\012Good-bye!\n");
                         exit(0);
                         break;
/* Alt-D */     case 32: VioWrtTTY("\015\012Enter number: ",16,0);
                         for (i=0;i<20;i++) {
                              KbdCharIn(&Buffer,0,0);
                              VioWrtTTY(&Buffer.cCharCode,1,0);
                              if ((number[i]=Buffer.cCharCode)<' ') break;
                         }
                         number[i] = '\0';
/* Alt-Q */     case 16: VioWrtTTY("\015\012Dialing...",12,0);
                         TellModem(DialPrefix);
                         PutS(ComHandle,number);
                         TellModem(DialSuffix);
                         break;
/* Alt-H */     case 35: VioWrtTTY("\015\012Hanging up...",15,0);
                         TellModem(HangUp);
                         break;
            }
        } else {
            PutC(ComHandle,Buffer.cCharCode);
        }
    }
}

main(int argc, char **argv, char **environ)
{
int i, Action;
int ReadThread, WriteThread;
static char ReadStack[1024], WriteStack[1024];
        i = DosOpen(argv[1],&ComHandle,&Action,0,0,0x11,0x0012,0);
	if (i != 0) {
            error[16] = (i / 1000) % 10 + '0';
            error[17] = (i / 100 ) % 10 + '0';
            error[18] = (i / 10  ) % 10 + '0';
            error[19] = (i / 1   ) % 10 + '0';
            PutS(2,error);
            exit(1);
        }
        for (i=0;environ[i]!=0;i++) {
            if (strncmp(environ[i],"MODEM INIT=",11) == 0)
                TellModem(&environ[i][11]);
            if (strncmp(environ[i],"DIAL PREFIX=",12) == 0)
                DialPrefix = &environ[i][12];
            if (strncmp(environ[i],"DIAL SUFFIX=",12) == 0)
                DialSuffix = &environ[i][12];
            if (strncmp(environ[i],"HANG UP=",8) == 0)
                HangUp = &environ[i][8];
        }
        PutS(1,"\015\012Alt-D = Dial, Alt-H = HangUp, Alt-Q = Redial, Alt-X = Exit\015\012");
        DosCreateThread(ReadCom,&ReadThread,ReadStack+1024);
        DosCreateThread(WriteCom,&WriteThread,WriteStack+1024);
        DosExit(0,0);
}
