#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

#define MAX 5
#define RBS 32


void DieWithError(const char* errMsg){
	printf("%s", errMsg);
	exit(1);
}

void HandleTCPClient(int cltSock){
	char echoBuffer[RBS];
	int rcvMsgSize;

	if( (rcvMsgSize = recv(cltSock, echoBuffer, RBS, 0)) < 0)
		DieWithError("recv() failed");

	while(rcvMsgSize > 0){
		if(send(cltSock, echoBuffer, rcvMsgSize, 0) != rcvMsgSize){
			DieWithError("send() failed");
		}

		if((rcvMsgSize = recv(cltSock, echoBuffer, RBS, 0)) < 0)
			DieWithError("recv() failed");
	}
	close(cltSock);
}

int a2i(const char *s)
{
  int num=0;
  while(*s){
    num=((*s)-'0')+num*10;
    s++;   
  }
  return num;
}

int main(int argc, char *argv[])
{
	int servSock;
	int cltSock;

	struct sockaddr_in echoServAddr;
	struct sockaddr_in echoCltAddr;

	unsigned short echoServPort;
	unsigned int cltLen;

	if(argc!=2){
		fprintf(stderr, "Usage: %s <Server Port>\n", argv[0]);
		exit(1);
	}

	echoServPort = atoi(argv[1]);

	if( (servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0 )
		DieWithError("socket() failed");

	memset(&echoServAddr, 0, sizeof(echoServAddr));
	echoServAddr.sin_family = AF_INET;
	echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	echoServAddr.sin_port = htons(echoServPort);


	if(bind(servSock, (struct sockaddr*)&echoServAddr, sizeof(echoServAddr)) < 0)
		DieWithError("bind() failed");

	if(listen(servSock, MAX) < 0)
		DieWithError("listen() failed");


	for(;;){
		cltLen = sizeof(echoCltAddr);

		if( (cltSock = accept(servSock, (struct sockaddr*)&echoCltAddr, &cltLen)) < 0)
			DieWithError("accept() failed");

		printf("Handling client %s\n", inet_ntoa(echoCltAddr.sin_addr));
		HandleTCPClient(cltSock);
	}

	return 0;
}