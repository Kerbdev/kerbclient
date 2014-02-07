#include "query/request.h"
#define PORT "3490" // Порт, к которому подключается клиент
// получение структуры sockaddr, IPv4 или IPv6:
void *get_in_addr(struct sockaddr *sa) {
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*) sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*) sa)->sin6_addr);
}

int main(int argc, char *argv[]) {
	int sockfd;
	char date_time[MAXDATASIZE];
	struct addrinfo hints, *servinfo, *p;
	int rv;
	char FLAGS=0;
	char s[INET6_ADDRSTRLEN];
	char user_name[MAXDATASIZE];
	char TGS_ID[MAXDATASIZE];
	char server_msg[MAXDATASIZE];
	char session_key_client_tgs_secret[MAXDATASIZE];
	char id_server_secret[MAXDATASIZE];
	int time_live_secret=0;
	char id_service[MAXDATASIZE];
	struct TGT tgt;
	struct AUTH_CLIENT AUTH;
	struct SERVICE_TICKET service_ticket;
	struct TICKET ticket;
	struct AUTH_CLIENT NEW_AUTH;
	if (argc != 2) {
		fprintf(stderr, "usage: client hostname\n");
		exit(1);
	}

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((rv = getaddrinfo(argv[1], PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}
	// Проходим через все результаты и соединяемся к первому возможному
	for (p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol))
				== -1) {
			perror("client: socket");
			continue;
		}

		if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("client: connect");
			continue;
		}

		break;
	}

	if (p == NULL) {
		fprintf(stderr, "client: failed to connect\n");
		return 2;
	}

	inet_ntop(p->ai_family, get_in_addr((struct sockaddr *) p->ai_addr), s,
			sizeof s);
	printf("client: connecting to %s\n", s);

	freeaddrinfo(servinfo); // эта структура больше не нужна
	//RECV date time
	Client_to_AS_REQ(sockfd,date_time,user_name,TGS_ID,server_msg,&FLAGS);
	if(FLAGS){
		printf("You in BD\n");
	AS_RECV(sockfd,session_key_client_tgs_secret,id_server_secret,time_live_secret,&tgt);
		printf("Enter ID SERVICE:");
		scanf("%s",id_service);
	TGS_REQ(sockfd,id_service,tgt,AUTH);
	TGS_REP_RECV(sockfd,ticket,service_ticket);
	Connect_to_service(sockfd,NEW_AUTH,service_ticket);
	if (confirm(sockfd,NEW_AUTH)){
		printf("Client confirm to  service");
	}
	else printf("NOT CONFIRM A SERVICE");


	}
	else{ printf("Error you not in BD");
		close(1);}


	//printf("%s", server_msg);
	//strcpy(cmd, "date --set");
	//strcat(cmd, "=");
	//strcat(cmd, "\"");
	//strcat(cmd, date_time);
	//strcat(cmd, "\"");
	//system(cmd);

	exit(0);
}
