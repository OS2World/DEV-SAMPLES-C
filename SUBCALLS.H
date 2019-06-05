/*SCCSID = @(#)subcalls.hwc	7.15 87/03/16*/
/*
	rcl version

	Windows-like case convention
	typedefs for structs
	Windows-like variable naming conventions
*/
typedef struct {
	unsigned uStartLine;
	unsigned uEndLine;
	unsigned uWidth;
	unsigned uAttribute;
	}CURSORDATA;
typedef struct {
	unsigned uLength;
	unsigned uBitMask;
	unsigned uTurnAroundChar;
	unsigned iTnterimCharFlags;
	unsigned uShiftState;
	}KBDSTATUS;
typedef struct  {
	unsigned char cCharCode;
	unsigned char cScanCode;
	unsigned char cStatus;
	unsigned char cNlsShift;
	unsigned uShiftState;
	unsigned long tTime;
	unsigned uKbdDDFFlags;
	unsigned uXltFlags;
	unsigned uXltShiftState;
	unsigned xlt_rsrv_0;
	}KBDTRANS;

typedef struct {
	unsigned char cCharCode;
	unsigned char cScanCode;
	unsigned char cStatus;
	unsigned char cNlsShift;
	unsigned uShiftState;
	unsigned long tTime;
	}KBDDATA;

typedef struct {
	unsigned uLength;
	unsigned char cType;
	unsigned char cColor;
	unsigned uCol;
	unsigned uRow;
	unsigned uHRes;
	unsigned uVRes;
	}MODEDATA;
typedef struct {
	unsigned uPvbSize;
	unsigned long lPvbPtr;
	unsigned uPvbLength;
	unsigned uPvbRows;
	unsigned uPvbCols;
	unsigned char cPvbType;
	}PVBDATA;
typedef struct {
	unsigned long lBufStart;
	unsigned long lBufLength;
	unsigned      uSelectors[2];
	}PHYSBUFDATA;
typedef struct {
	unsigned uLength ;
	unsigned uAdapterType;
	unsigned uDisplayType;
	unsigned long lMemorySize;
	}CONFIGDATA;
typedef struct {
	unsigned uLength;
	unsigned uReqType;
	unsigned uPelCols;
	unsigned uPelRows;
	unsigned long lFontData;
	unsigned uFontLen;
	}VIOFONT;
typedef struct  {
	unsigned uLength;
	unsigned uReqType;
	unsigned uDoubleDefined;
	unsigned uPalette0;
	unsigned uPalette1;
	unsigned uPalette2;
	unsigned uPalette3;
	unsigned uPalette4;
	unsigned uPalette5;
	unsigned uPalette6;
	unsigned uPalette7;
	unsigned uPalette8;
	unsigned uPalette9;
	unsigned uPalette10;
	unsigned uPalette11;
	unsigned uPalette12;
	unsigned uPalette13;
	unsigned uPalette14;
	unsigned uPalette15;
	}VIOSTATE;
typedef struct {
	unsigned uMask;
	unsigned long lTime;
	unsigned uRow;
	unsigned uCol;
	}EVENTINFO;
typedef struct {
	unsigned uRow;
	unsigned uCol;
	unsigned uHeight;
	unsigned uWidth;
	}NOPOINTER;
typedef struct {
	unsigned uTotLength;
	unsigned uCol;
	unsigned uRow;
	unsigned uColOffset;
	unsigned uRowOffset;
	}PTRIMAGE;
typedef struct {
	unsigned uRowPos;
	unsigned uColPos;
	}PTRLOC;
typedef struct {
	unsigned uEvents;
	unsigned uQSize;
	}QUEINFO;
typedef struct {
	unsigned uRowScale;
	unsigned uColScale;
	}SCALEFACT;
typedef struct {
	unsigned uLength;
	unsigned uRelated;
	unsigned uFgBg;
	unsigned uTraceOpt;
	char far * pszPgmTitle;
	char far * pszPgmName;
	char far * pszPgmInputs;
	char far * pszTermQ;
	}STARTDATA;
typedef struct {
	unsigned uLength;
	unsigned uSelectInd;
	unsigned uBindInd;
	}STATUSDATA;
typedef struct
   {
    unsigned int  uLength;
    unsigned int  uLengthB;
   }KBDSTRINGINLENGTH;
extern unsigned far pascal KbdRegister (
	char far *,
	char far *,
	unsigned long);
extern unsigned far pascal KbdDeRegister (
	void );
extern unsigned far pascal KbdCharIn (
	KBDDATA far *,
	unsigned,
	unsigned );
/*	Values for IOWAIT param in KBDCHARIN */
#define	KBD_WAIT	0
#define	KBD_NO_WAIT	1

extern unsigned far pascal KbdFlushBuffer (
	unsigned );
extern unsigned far pascal KbdGetStatus (
	KBDSTATUS far *,
	unsigned );
extern unsigned far pascal KbdPeek (
	KBDDATA far *,
	unsigned );
extern unsigned far pascal KbdSetStatus (
	KBDSTATUS far *,
	unsigned );
extern unsigned far pascal KbdStringIn (
	char far *,
	KBDSTRINGINLENGTH far *,
	unsigned,
	unsigned );
extern unsigned far pascal KbdOpen (
	unsigned far * );
extern unsigned far pascal KbdClose (
	unsigned );
extern unsigned far pascal KbdGetFocus (
	unsigned,
	unsigned );
extern unsigned far pascal KbdFreeFocus (
	unsigned );
extern unsigned far pascal KbdGetCP (
	unsigned long,
	unsigned far *,
	unsigned );
extern unsigned far pascal KbdSetCP (
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal KbdXlate (
	KBDTRANS far *,
	unsigned );
extern unsigned far pascal KbdSetCusTxt (
	unsigned far *,
	unsigned );
extern unsigned far pascal KbdSynch (
	unsigned );
extern unsigned far pascal VioRegister (
	char far *,
	char far *,
	unsigned long,
	unsigned long );
extern unsigned far pascal VioDeRegister (
	void );
extern unsigned far pascal VioGetBuf (
	unsigned long far *,
	unsigned far *,
	unsigned );
extern unsigned far pascal VioGetCurPos (
	unsigned far *,
	unsigned far *,
	unsigned );
extern unsigned far pascal VioGetCurType (
	CURSORDATA far *,
	unsigned );
extern unsigned far pascal VioGetMode (
	MODEDATA far *,
	unsigned );
extern unsigned far pascal VioGetPhysBuf (
	PHYSBUFDATA far *,
	unsigned );
extern unsigned far pascal VioReadCellStr (
	char far *,
	unsigned far *,
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal VioReadCharStr (
	char far *,
	unsigned far *,
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal VioScrollDn (
	unsigned,
	unsigned,
	unsigned,
	unsigned,
	unsigned,
	char far *,
	unsigned );
extern unsigned far pascal VioScrollUp (
	unsigned,
	unsigned,
	unsigned,
	unsigned,
	unsigned,
	char far *,
	unsigned );
extern unsigned far pascal VioScrollLf (
	unsigned,
	unsigned,
	unsigned,
	unsigned,
	unsigned,
	char far *,
	unsigned );
extern unsigned far pascal VioScrollRt (
	unsigned,
	unsigned,
	unsigned,
	unsigned,
	unsigned,
	char far *,
	unsigned );
extern unsigned far pascal VioSetCurPos (
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal VioSetCurType (
	CURSORDATA far *,
	unsigned );
extern unsigned far pascal VioSetMode (
	MODEDATA far *,
	unsigned );
extern unsigned far pascal VioShowBuf (
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal VioWrtCellStr (
	char far *,
	unsigned,
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal VioWrtCharStr (
	char far *,
	unsigned,
	unsigned,
	unsigned,
	unsigned );
/* No doc */
extern unsigned far pascal VioWrtCharStrAtt (
	char far *,
	unsigned,
	unsigned,
	unsigned,
	char far *,
	unsigned );
extern unsigned far pascal VioWrtNAttr (
	char far *,
	unsigned,
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal VioWrtNCell (
	char far *,
	unsigned,
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal VioWrtNChar (
	char far *,
	unsigned,
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal VioWrtTTY (
	char far *,
	unsigned,
	unsigned );
extern unsigned far pascal VioSetANSI (
	unsigned,
	unsigned );
extern unsigned far pascal VioGetAnsi (
	unsigned far *,
	unsigned );
extern unsigned far pascal VioPrtSc (
	unsigned );
extern unsigned far pascal VioPrtScToggle (
	unsigned );
extern unsigned far pascal VioSavReDrawWait (
	unsigned,
	unsigned far *,
	unsigned );
extern unsigned far pascal VioSavReDrawUndo (
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal VioModeWait (
	unsigned,
	unsigned far *,
	unsigned );
extern unsigned far pascal VioModeUndo (
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal VioScrLock (
	unsigned,
	unsigned char far *,
	unsigned );
extern unsigned far pascal VioScrUnLock (
	unsigned );
extern unsigned far pascal VioPopUp (
	unsigned far *,
	unsigned );
extern unsigned far pascal VioEndPopUp (
	unsigned );
extern unsigned far pascal VioGetConfig (
	unsigned,
	CONFIGDATA far *,
	unsigned );
extern unsigned far pascal VioGetFont (
	VIOFONT far *,
	unsigned );
extern unsigned far pascal VioGetCP (
	unsigned,
	unsigned far *,
	unsigned );
extern unsigned far pascal VioSetCP (
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal VioSetFont (
	VIOFONT far *,
	unsigned );
extern unsigned far pascal VioGetState (
	VIOSTATE far *,
	unsigned );
extern unsigned far pascal VioSetState (
	VIOSTATE far *,
	unsigned );
extern unsigned far pascal MouRegister (
	char far *,
	char far *,
	unsigned long );
extern unsigned far pascal MouDeRegister (
	void );
extern unsigned far pascal MouFlushQue (
	unsigned );
extern unsigned far pascal MouGetHotKey (
	unsigned far *,
	unsigned );
extern unsigned far pascal MouSetHotKey (
	unsigned far *,
	unsigned );
extern unsigned far pascal MouGetPtrPos (
	PTRLOC far *,
	unsigned );
extern unsigned far pascal MouSetPtrPos (
	PTRLOC far *,
	unsigned );
extern unsigned far pascal MouGetPtrShape (
	unsigned char far *,
	PTRIMAGE far *,
	unsigned );
extern unsigned far pascal MouSetPtrShape (
	unsigned char far *,
	PTRIMAGE far *,
	unsigned );
extern unsigned far pascal MouGetDevStatus (
	unsigned far *,
	unsigned );
extern unsigned far pascal MouGetNumButtons (
	unsigned far *,
	unsigned );
extern unsigned far pascal MouGetNumMockeys (
	unsigned far *,
	unsigned );
extern unsigned far pascal MouReadEventQue (
	EVENTINFO far *,
	unsigned far *,
	unsigned );
extern unsigned far pascal MouGetNumQueEl (
	QUEINFO far *,
	unsigned );
extern unsigned far pascal MouGetEventMask (
	unsigned far *,
	unsigned );
extern unsigned far pascal MouSetEventMask (
	unsigned far *,
	unsigned );
extern unsigned far pascal MouGetScaleFact (
	SCALEFACT far *,
	unsigned );
extern unsigned far pascal MouSetScaleFact (
	SCALEFACT far *,
	unsigned );
extern unsigned far pascal MouOpen (
	char far *,
	unsigned far * );
extern unsigned far pascal MouClose (
	unsigned );
extern unsigned far pascal MouRemovePtr (
	NOPOINTER far *,
	unsigned );
extern unsigned far pascal MouDrawPtr (
	unsigned );
extern unsigned far pascal MouSetDevStatus (
	unsigned far *,
	unsigned );
extern unsigned far pascal MouInitReal (
	char far * );
extern unsigned far pascal DosStartSession (
	STARTDATA far *,
	unsigned far *,
	unsigned far * );
extern unsigned far pascal DosSetSession (
	unsigned,
	STATUSDATA far * );
extern unsigned far pascal DosSelectSession (
	unsigned,
	unsigned long );
extern unsigned far pascal DosStopSession (
	unsigned,
	unsigned,
	unsigned long );
