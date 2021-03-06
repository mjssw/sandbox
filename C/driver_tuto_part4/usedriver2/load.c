/**********************************************************************
 * 
 *  Toby Opferman
 *
 *  Example Communicating with a driver
 *
 *  This example is for educational purposes only.  I license this source
 *  out for use in learning how to write a device driver.
 *
 *    
 **********************************************************************/


#include <windows.h>
#include <WINIOCTL.H>
#include <stdio.h>
#include <public.h>

/*********************************************************
 *   Main Function Entry
 *
 *********************************************************/
int _cdecl main(int argc, char **argv)
{
    HANDLE hFile;
    DWORD dwReturn;
    char szTemp[256] = {0};

    sprintf(szTemp, "\\\\.\\Example\\%s", argv[1]);
    
    hFile = CreateFile(szTemp, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

    if(hFile != INVALID_HANDLE_VALUE)
    {

        while(szTemp[0] != 'q' && szTemp[0] != 'Q')
        {
        
            printf("Enter a string and press enter, 'Q' to quit>\n");
            gets(szTemp);
            dwReturn = 0;
            WriteFile(hFile, szTemp, strlen(szTemp) + 1, &dwReturn, NULL); 
            
            printf("%d bytes written\n", dwReturn);
        }
        
        CloseHandle(hFile);
    }
    
    return 0;
}


