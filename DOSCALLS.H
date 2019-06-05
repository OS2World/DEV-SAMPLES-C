/*static char *SCCSID = "@(#)doscalls.hwc	7.22 87/03/18";*/
/*
	rcl version
	Windows-like case convention
	typedefs for structs
	Windows-like variable naming conventions
*/
typedef struct {
	unsigned char uHour;
	unsigned char uMinutes;
	unsigned char Useconds;
	unsigned char uHundredths;
	unsigned char uDay;
	unsigned char uMonth;
	unsigned uYear;
	int nTimezone;
	unsigned char cDayOfWeek;
	}DATETIME;
typedef struct {
	unsigned uCreateDate;
	unsigned uCreateTime;
	unsigned uAccessDate;
	unsigned uAccessTime;
	unsigned uWriteDate;
	unsigned uWriteTime;
	unsigned long lFileSize;
	unsigned long lFallocSize;
	unsigned uAttributes;
	unsigned char cStringLen;
	char szFilename[13];
	}FILEFINDBUF;
typedef struct {
	unsigned uCreateDate;
	unsigned uCreateTime;
	unsigned uAccessDate;
	unsigned uAccessTime;
	unsigned uWriteDate;
	unsigned uWriteTime;
	unsigned long lFileSize;
	unsigned long lFallocSize;
	unsigned uAttributes;
	}FILESTATUS;
typedef struct {
	unsigned long lFilsysID;
	unsigned long lSecPerUnit;
	unsigned long lNumUnits;
	unsigned long lAvailUnits;
	unsigned uBytesSec;
	}FSALLOCATE;
typedef struct {
	unsigned uProcidCpID;
	unsigned uProcidCtID;
	unsigned uProcidPppID;
	}PROCIDSAREA;
typedef struct {
	unsigned uTermCodePID;
	unsigned uExitCode;
	}RESULTCODES;
typedef struct {
	unsigned uCountry;
	unsigned uCodepage;
}COUNTRYCODE;
extern unsigned far pascal DosCreateThread (
	void (far *)(void),
	unsigned far *,
	unsigned char far * );
extern unsigned far pascal DosResumeThread (
	unsigned );
extern unsigned far pascal DosSuspendThread (
	unsigned );
extern unsigned far pascal DosCWait (
	unsigned,
	unsigned,
	RESULTCODES far *,
	unsigned far *,
	unsigned );
extern void far pascal DosEnterCritSec (void);
extern unsigned far pascal DosExecPgm (
	char far *,
	unsigned,
	unsigned,
	char far *,
	char far *,
	RESULTCODES far *,
	char far * );
extern void far pascal DosExit (
	unsigned,
	unsigned );
extern void far pascal DosExitCritSec (void);
extern unsigned far pascal DosExitList (
	unsigned,
	void (far *)(void) );
extern unsigned far pascal DosGetPID (
	PROCIDSAREA far *);
extern unsigned far pascal DosGetPrty (
	unsigned,
	unsigned far *,
	unsigned );
extern unsigned far pascal DosSetPrty (
	unsigned,
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal DosKillProcess (
	unsigned,
	unsigned );
extern unsigned far pascal DosHoldSignal (
	unsigned );
extern unsigned far pascal DosFlagProcess (
	unsigned,
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal DosSetSigHandler (
	void (far *)(),
	unsigned long far *,
	unsigned far *,
	unsigned,
	unsigned );
extern unsigned far pascal DosSendSignal (
	unsigned,
	unsigned);
extern unsigned far pascal DosMakePipe (
	unsigned far *,
	unsigned far *,
	unsigned );
extern unsigned far pascal DosCloseQueue (
	unsigned ) ;
extern unsigned far pascal DosCreateQueue (
	unsigned far *,
	unsigned,
	char far * ) ;
extern unsigned far pascal DosOpenQueue (
	unsigned far *,
	unsigned far *,
	char far * ) ;
extern unsigned far pascal DosPeekQueue (
	unsigned,
	unsigned long far *,
	unsigned far *,
	unsigned long far *,
	unsigned far *,
	unsigned char,
	unsigned char far *,
	unsigned long ) ;
extern unsigned far pascal DosPurgeQueue (
	unsigned ) ;
extern unsigned far pascal DosQueryQueue (
	unsigned,
	unsigned far * );
extern unsigned far pascal DosReadQueue (
	unsigned,
	unsigned long far *,
	unsigned far *,
	unsigned long far *,
	unsigned,
	unsigned char,
	unsigned char far *,
	unsigned long ) ;
extern unsigned far pascal DosWriteQueue (
	unsigned,
	unsigned,
	unsigned,
	unsigned char far *,
	unsigned char );
extern unsigned far pascal DosSemClear (
	unsigned long );
extern unsigned far pascal DosSemRequest (
	unsigned long,
	long );
extern unsigned far pascal DosSemSet (
	unsigned long );
extern unsigned far pascal DosSemSetWait (
	unsigned long,
	long );
extern unsigned far pascal DosSemWait (
	unsigned long,
	long );
extern unsigned far pascal DosMuxSemWait (
	unsigned far *,
	unsigned far *,
	long );
extern unsigned far pascal DosCloseSem (
	unsigned long );
extern unsigned far pascal DosCreateSem (
	unsigned,
	unsigned long far *,
	char far * );
extern unsigned far pascal DosOpenSem (
	unsigned long far *,
	char far * );
extern unsigned far pascal DosGetDateTime (
	DATETIME far * );
extern unsigned far pascal DosSetDateTime (
	DATETIME far * );
extern unsigned far pascal DosSleep (
	unsigned long );
extern unsigned far pascal DosGetTimerInt (
	unsigned far * );
extern unsigned far pascal DosTimerAsync (
	unsigned long,
	unsigned long,
	unsigned far * );
extern unsigned far pascal DosTimerStart (
	unsigned long,
	unsigned long,
	unsigned far * );
extern unsigned far pascal DosTimerStop (
	unsigned );
extern unsigned far pascal DosAllocSeg (
	unsigned,
	unsigned far *,
	unsigned );
extern unsigned far pascal DosAllocShrSeg (
	unsigned,
	char far *,
	unsigned far * );
extern unsigned far pascal DosGetShrSeg (
	char far *,
	unsigned far * );
extern unsigned far pascal DosGiveSeg (
	unsigned,
	unsigned,
	unsigned far * );
extern unsigned far pascal DosGetSeg (
	unsigned );
extern unsigned far pascal DosLockSeg (
	unsigned );
extern unsigned far pascal DosUnlockSeg (
	unsigned );
extern unsigned far pascal DosMemAvail (
	unsigned long far * );
extern unsigned far pascal DosReAllocSeg (
	unsigned,
	unsigned );
extern unsigned far pascal DosFreeSeg (
	unsigned );
extern unsigned far pascal DoaAllocHuge (
	unsigned,
	unsigned,
	unsigned far *,
	unsigned,
	unsigned );
extern unsigned far pascal DosGetHugeShift (
	unsigned far *);
extern unsigned far pascal DosReAllocHuge (
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal DosCreateCSAlias (
	unsigned,
	unsigned far * );
extern unsigned far pascal DosSubAlloc (
	unsigned,
	unsigned far *,
	unsigned );
extern unsigned far pascal DosSubFree (
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal DosSubSet (
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal DosLoadModule (
	char far *,
	unsigned,
	char far *,
	unsigned far * );
extern unsigned far pascal DosFreeModule (
	unsigned );
extern unsigned far pascal DosGetProcAddr (
	unsigned,
	char far *,
	unsigned long far * );
extern unsigned far pascal DosGetModHandle (
	char far *,
	unsigned far *);
extern unsigned far pascal DosGetModName (
	unsigned,
	unsigned,
	char far * );
extern unsigned far pascal DosBeep (
	unsigned,
	unsigned );
extern unsigned far pascal DosCLIAccess (void);
extern unsigned far pascal DosDevConfig (
	unsigned char far *,
	unsigned,
	unsigned );
extern unsigned far pascal DosDevIOCtl (
	char far *,
	char far *,
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal DosIOAccess (
	unsigned,
	unsigned,
	unsigned,
	unsigned );
extern unsigned far pascal DosPortAccess (
	unsigned,
	unsigned,
	unsigned,
	unsigned );
/* no doc */
extern unsigned far pascal DosSGNum (
	unsigned far *);
extern unsigned far pascal DosSgSwitch (
	unsigned );
extern unsigned far pascal DosSGSwitchMe (
	unsigned );
extern unsigned far pascal DosMonOpen (
	char far *,
	unsigned far * );
extern unsigned far pascal DosMonClose (
	unsigned );
extern unsigned far pascal DosMonReg (
	unsigned,
	unsigned char far *,
	unsigned char far *,
	unsigned,
	unsigned );
extern unsigned far pascal DosMonRead (
	unsigned char far *,
	unsigned char,
	unsigned char far *,
	unsigned far * );
extern unsigned far pascal DosMonWrite (
	unsigned char far *,
	unsigned char far *,
	unsigned );
extern unsigned far pascal DosBufReset (
	unsigned );
extern unsigned far pascal DosChdir (
	char far *,
	unsigned long );
extern unsigned far pascal DosChgFilePtr (
	unsigned,
	long,
	unsigned,
	unsigned long far * );
extern unsigned far pascal DosClose (
	unsigned );
extern unsigned far pascal DosDelete (
	char far *,
	unsigned long );
extern unsigned far pascal DosDupHandle (
	unsigned,
	unsigned far * );
extern unsigned far pascal DosFindClose (
	unsigned );
extern unsigned far pascal DosFindFirst (
	char far *,
	unsigned far *,
	unsigned,
	FILEFINDBUF far *,
	unsigned,
	unsigned far *,
	unsigned long );
extern unsigned far pascal DosFindNext (
	unsigned,
	FILEFINDBUF far *,
	unsigned,
	unsigned far * );
extern unsigned far pascal DosFileLocks (
	unsigned,
	long far *,
	long far * );
extern unsigned far pascal DosGetInfoSeg (
	unsigned far *,
	unsigned far * );
extern unsigned far pascal DosMkdir (
	char far *,
	unsigned long );
extern unsigned far pascal DosMove (
	char far *,
	char far *,
	unsigned long );
extern unsigned far pascal DosNewSize (
	unsigned,
	unsigned long );
extern unsigned far pascal DosOpen (
	char far *,
	unsigned far *,
	unsigned far *,
	unsigned long,
	unsigned,
	unsigned,
	unsigned,
	unsigned long );
extern unsigned far pascal DosQCurDir (
	unsigned,
	char far *,
	unsigned far * );
extern unsigned far pascal DosQCurDisk (
	unsigned far *,
	unsigned long far * );
extern unsigned far pascal DosQFHandState (
	unsigned,
	unsigned far * );
extern unsigned far pascal DosQFileInfo (
	unsigned,
	unsigned,
	char far *,
	unsigned );
extern unsigned far pascal DosQFileMode (
	char far *,
	unsigned far *,
	unsigned long );
extern unsigned far pascal DosQFSInfo (
	unsigned,
	unsigned,
	char far *,
	unsigned );
extern unsigned far pascal DosQHandType (
	unsigned,
	unsigned far *,
	unsigned far * );
extern unsigned far pascal DosQSwitChar (
	unsigned char far * );
extern unsigned far pascal DosQVerify (
	unsigned far * );
extern unsigned far pascal DosRead (
	unsigned,
	char far *,
	unsigned,
	unsigned far * );
extern unsigned far pascal DosReadAsync (
	unsigned,
	unsigned long far *,
	unsigned far *,
	char far *,
	unsigned,
	unsigned far * );
extern unsigned far pascal DosRmdir (
	char far *,
	unsigned long );
extern unsigned far pascal DosSelectDisk (
	unsigned );
extern unsigned far pascal DosSetFHandState (
	unsigned,
	unsigned);
extern unsigned far pascal DosSetFSInfo (
	unsigned,
	unsigned,
	char far *,
	unsigned );
extern unsigned far pascal DosSetFileInfo (
	unsigned,
	unsigned,
	char far *,
	unsigned );
extern unsigned far pascal DosSetFileMode (
	char far *,
	unsigned,
	unsigned long );
extern unsigned far pascal DosSetMaxFH (
	unsigned );
extern unsigned far pascal DosSetVerify (
	unsigned );
extern unsigned far pascal DosWrite (
	unsigned,
	char far *,
	unsigned,
	unsigned far * );
extern unsigned far pascal DosWriteAsync (
	unsigned,
	unsigned long far *,
	unsigned far *,
	char far *,
	unsigned,
	unsigned far * );
extern unsigned far pascal DosError (
	unsigned );
extern unsigned far pascal DosSetVec (
	unsigned,
	void (far *)(void),
	void (far * far *)(void) );
extern unsigned far pascal DosGetMessage (
	char far * far *,
	unsigned,
	char far *,
	unsigned,
	unsigned,
	char far *,
	unsigned far * );
extern unsigned far pascal DosErrClass (
	unsigned,
	unsigned far *,
	unsigned far *,
	unsigned far * );
extern unsigned far pascal DosInsMessage (
	char far * far *,
	unsigned,
	char far *,
	unsigned,
	char far *,
	unsigned,
	unsigned far * );
extern unsigned far pascal DosPutMessage (
	unsigned,
	unsigned,
	char far * );
extern unsigned far pascal DosSysTrace (
	unsigned,
	unsigned,
	unsigned,
	char far * );
extern unsigned far pascal DosGetEnv (
	unsigned far *,
	unsigned far * );
extern unsigned far pascal DosScanEnv (
     char far *,
     char far * far * );
extern unsigned far pascal DosSearchPath (
     unsigned,
     char far *,
     char far *,
     char far *,
     unsigned );
extern unsigned far pascal DosGetVersion (
	unsigned far * );
extern unsigned far pascal DosGetMachineMode (
	unsigned char far * );
extern unsigned far pascal DosGetCtryInfo (
	unsigned,
	COUNTRYCODE far *,
	char far *,
	unsigned far * );
extern unsigned far pascal DosGetDBCSEv (
	unsigned,
	COUNTRYCODE far *,
	char far * );
extern unsigned far pascal DosCaseMap (
	unsigned,
	COUNTRYCODE far *,
	char far * );
extern unsigned far pascal DosGetCollate (
	unsigned,
	COUNTRYCODE far *,
	char far *,
	unsigned far *);
extern unsigned far pascal DosGetCP (
	unsigned,
	unsigned far *,
	unsigned far *);
extern unsigned far pascal DosSetCP (
	unsigned,
	unsigned);
extern unsigned far pascal DosPhysicalDisk (
	unsigned,
	char far *,
	unsigned,
	char far *,
	unsigned);
extern unsigned far pascal DosSystemService (
	unsigned,
	char far *,
	char far *);
