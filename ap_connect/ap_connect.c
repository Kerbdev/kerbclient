/*
 * ap_connect.c
 *
 *  Created on: Apr 11, 2014
 *      Author: ivan
 */
#include "ap_connect.h"
#define PORT "3491"
void *get_in_addr(struct sockaddr *sa) {
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*) sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*) sa)->sin6_addr);
}
void ap_connect() {
	char *l="Привет";
	struct addrinfo hints, *servinfo, *p;
	char s[INET6_ADDRSTRLEN];
	int sockfd,rv;
	memset(&hints, 0, sizeof hints);
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
	if ((rv = getaddrinfo("127.0.0.1", PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		//return 1;
	}
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
			//return 2;
		}

		inet_ntop(p->ai_family, get_in_addr((struct sockaddr *) p->ai_addr), s,
				sizeof s);
		printf("client: connecting to %s\n", s);

		send(sockfd,l,strlen(l),0);


		close(sockfd);
}

