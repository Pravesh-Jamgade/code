#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define RBS 32

void DieWithError(const char* errorMsg){
	printf("Error:%s\n", errorMsg);
	exit(1);
}

int main(int argc, char* argv[]){

	int sock;
	struct sockaddr_in echoServAddr;
	unsigned short echoServPort;
	char* servIp;
	char* echoString;
	char echoBuffer[RBS];
	unsigned int echoStrLen;
	int byteRcvd, totalByteRcvd;

	if(argc < 3 || argc>4){
		fprintf(stderr, "%s <server_ip> <echo word> <echo port>\n", argv[0]);
		exit(1);
	}

	servIp = argv[1]; /* server ip */
	echoString = argv[2];
	if(argc == 4){
		echoServPort = atoi(argv[3]);
	}else{
		echoServPort = 7;
	}

	if((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		DieWithError("socket() failed");

	memset(&echoServAddr, 0, sizeof(echoServAddr));

	echoServAddr.sin_family = AF_INET;
	echoServAddr.sin_addr.s_addr = inet_addr(servIp);
	echoServAddr.sin_port = htons(echoServPort);

	if(connect(sock, (struct sockaddr*)&echoServAddr, sizeof(echoServAddr)) < 0){
		DieWithError("connect() failed");
	}

	echoStrLen = strlen(echoString);

	if(send(sock, echoString, echoStrLen, 0) != echoStrLen)
		DieWithError("send() failed");


	totalByteRcvd = 0;
	printf("Received: ");

	while(totalByteRcvd<echoStrLen){
		if( (byteRcvd = recv(sock, echoBuffer, RBS-1, 0)) <= 0)
			DieWithError("recv() failed");

		totalByteRcvd += byteRcvd;
		echoBuffer[byteRcvd]='\0';
		printf("%s",echoBuffer);
		sleep(1);
	}

	printf("\n");

	return 0;
}