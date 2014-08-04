/*
 * ap_connect.c
 *
 *  Created on: Apr 11, 2014
 *      Author: ivan
 */
#include "ap_connect.h"
#include "../dynamic/dynamic.h"
#include "../mess/mess.h"
#define PORT "3491"
void *get_in_addr(struct sockaddr *sa) {
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*) sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*) sa)->sin6_addr);
}
void ap_connect(krb5_ticket *ticket,krb5_keyblock *session) {
	configuration config;
	get_config_param(&config);
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
		        	krb5_ap_rep *ap_rep=calloc(1,sizeof(krb5_ap_rep));
		        		malloc_krb5_ap_rep(ap_rep);
		krb5_authenticator *authen=calloc(1,sizeof(krb5_authenticator));
				malloc_krb5_authenticator(authen);

				krb5_error *error=calloc(1,sizeof(krb5_error));
				        	malloc_krb5_error(error);

				krb5_auth(authen,&config);
				krb5_ap_req *ap_req=calloc(1,sizeof(krb5_ap_req));
				malloc_krb5_ap_req(ap_req);
				krb5_ap_req_imp(ap_req,authen,ticket,session,"key");

				send_krb5_ap_req(sockfd,*ap_req);
				recv_krb5_ap_rep(sockfd,ap_rep,error);

				check_krb5_ap_rep(ap_rep,session);


		close(sockfd);
}

