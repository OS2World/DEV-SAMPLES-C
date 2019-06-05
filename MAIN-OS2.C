/*        MAIN.C

        Alternate, standalone main() file.  Demonstrates
        linking to the startup code without having to link
        to any of the Turbo C library routines.

*/

#include "DOSCALLS.H"
#include <STRING.H>

exit(int retcode) {DosExit(1,retcode);}

main(int argc, char **argv, char **environ)
{
int i, BytesWritten;
        for (i=0;i<argc;i++) {
            DosWrite(1,argv[i],strlen(argv[i]),&BytesWritten);
            DosWrite(1,"\n",1,&BytesWritten);
        }
        for (i=0;environ[i]!=0;i++) {
            DosWrite(1,environ[i],strlen(environ[i]),&BytesWritten);
            DosWrite(1,"\n",1,&BytesWritten);
        }
        exit(0);
}
