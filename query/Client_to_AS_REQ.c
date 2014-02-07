#include "request.h"
void Client_to_AS_REQ(int sockfd,char *date_time,char *user_name,char *TGS_ID,char *server_msg,char *FLAGS){
	char buf_for_tgs[MAXDATASIZE];
	char buf[MAXDATASIZE];
if ((recv(sockfd, date_time, MAXDATASIZE, 0)) == -1) {
		perror("recv");
	}
	//RECV "ENTER NAME ID CLIENT"
	if ((recv(sockfd, buf, MAXDATASIZE, 0)) == -1) {
		perror("recv");
		printf("%s", buf);
	}
	printf("%s", buf);
	scanf("%s", user_name);
	//SEND USER ID to server
	if (send(sockfd, user_name, MAXDATASIZE, 0) == -1) {
		perror("send");
	}
	//RECV "ENTER TGS ID"
	if ((recv(sockfd, buf_for_tgs, MAXDATASIZE, 0)) == -1) {
		perror("recv");
	}
	printf("%s", buf_for_tgs);
	scanf("%s", TGS_ID);
	if (send(sockfd, TGS_ID, MAXDATASIZE, 0) == -1) {
		perror("send");
	}

	//RECV msg from service about ID client
	if (recv(sockfd, server_msg, MAXDATASIZE, 0) == -1)
		perror("recv");

printf("%s",server_msg);
    //recv FLAGS
   //int b;
	if ((recv(sockfd, FLAGS, 1, 0)) == -1)
			perror("recv");
	//*FLAGS=b;
}
