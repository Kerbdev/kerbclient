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
	struct addrinfo hints, *servinfo, *p;
	int rv;
	char FLAGS=0;
	char s[INET6_ADDRSTRLEN];
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
	krb5_kdc_req *as_rep=malloc(sizeof(krb5_kdc_req));
	as_rep->padata=malloc(sizeof(krb5_pa_data));
	as_rep->client->data=malloc(sizeof(krb5_data));
	as_rep->addresses=malloc(sizeof(krb5_address));
	as_rep->unenc_authdata=malloc(sizeof(krb5_authdata));
	as_rep->second_ticket=malloc(sizeof(krb5_ticket));

	send_krb5_kdc_req(sockfd,as_rep,&FLAGS);
	if(FLAGS){}
		close(1);


	//printf("%s", server_msg);
	//strcpy(cmd, "date --set");
	//strcat(cmd, "=");
	//strcat(cmd, "\"");
	//strcat(cmd, date_time);
	//strcat(cmd, "\"");
	//system(cmd);

	exit(0);
}
