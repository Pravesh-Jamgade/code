#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<arpa/inet.h>

using namespace std;

int main(){

	int sockfd =0;
	int n = 0;
	char recvBuff[1025];

	struct sockaddr_in serv_addr;

	memset(recvBuff, '0', sizeof(recvBuff));

	if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\nError: Could not create socket\n");
		return 1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(5000);
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) <0)
	{
		printf("\nError: Connection Failed\n");
		return 1;
	}

	while( (n=read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
	{
		recvBuff[n] = 0;
		if(fputs(recvBuff, stdout) == EOF)
		{
			printf("\nError: fputs error\n");
		}
		printf("\n");
	}

	if(n<0){
		printf("\nRead Error\n");
	}
	return 0;
}