#include "query/request.h"
#include "mess/mess.h"
#include "dynamic/dynamic.h"
#include "ap_connect/ap_connect.h"
#define PORTS "3490" // Порт, к которому подключается клиент
// получение структуры sockaddr, IPv4 или IPv6:

int main(int argc, char *argv[]) {
	int sockfd;
	struct addrinfo hints, *servinfo, *p;
	int rv;
	struct ifreq ifr;
	configuration config;
	get_config_param(&config);
	char s[INET6_ADDRSTRLEN];
	if (argc != 2) {
		fprintf(stderr, "usage: client hostname\n");
		exit(1);
	}

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((rv = getaddrinfo(argv[1], PORTS, &hints, &servinfo)) != 0) {
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
	ifr.ifr_addr.sa_family = AF_INET;


	if (p == NULL) {
		fprintf(stderr, "client: failed to connect\n");
		return 2;
	}

	inet_ntop(p->ai_family, get_in_addr((struct sockaddr *) p->ai_addr), s,
			sizeof s);
	printf("client: connecting to %s\n", s);

	freeaddrinfo(servinfo); // эта структура больше не нужна
	int kdc_options=4;
	krb5_kdc_req *as_req=calloc(1,sizeof(krb5_kdc_req));
	malloc_krb5_kdc_req(as_req);
	char pass[]="12345";
	//int c=strlen(pass)
	krb5_as_req(as_req,kdc_options,&config,"ivan",pass);

	krb5_kdc_rep *as_rep=calloc(1,sizeof(krb5_kdc_rep));
		malloc_krb5_kdc_rep(as_rep);




	send_krb5_kdc_req(sockfd,*as_req);


/*	krb5_kdc_req *as_req=calloc(1,sizeof(krb5_kdc_req));
	malloc_krb5_kdc_req(as_req);
	//KRB_AS_REQ(as_req,as_req->padata);
	send_krb5_kdc_req(sockfd,*as_req); */




	krb5_error *error=calloc(1,sizeof(krb5_error));
	malloc_krb5_error(error);


	recv_krb5_kdc_rep(sockfd,as_rep,error);


	check_krb5_as_rep(as_req,as_rep,pass);

	krb5_kdc_req *tgs_req=calloc(1,sizeof(krb5_kdc_req));
	malloc_krb5_kdc_req(tgs_req);

	krb5_tgs_req(tgs_req,as_rep,kdc_options,&config);
	send_krb5_kdc_req(sockfd,*tgs_req);
	krb5_kdc_rep *new_as_rep=calloc(1,sizeof(krb5_kdc_rep));
	malloc_krb5_kdc_rep(new_as_rep);
	recv_krb5_kdc_rep(sockfd,new_as_rep,error);
	check_krb5_tgs_rep(new_as_rep,as_rep->enc_part2->session);


	/*
	//KRB_AS_REP(config,as_rep,as_req, as_req->padata,error);
	//fprintf(stderr,"%d",as_rep->enc_part2->msg_type);
//fprintf(stderr,"%s",as_rep->enc_part2->aaddrs->contents);
	KRB_AS_REP_CHECK(as_rep,error,as_req);//add logic if function return ERROR restart )

	AS_TGS_REP_CHECK(as_req,error, as_rep, config);
	krb5_kdc_rep *new_as_rep=calloc(1,sizeof(krb5_kdc_rep));
	malloc_krb5_kdc_rep(new_as_rep);
	krb5_kdc_req *new_as_req=calloc(1,sizeof(krb5_kdc_req));
	malloc_krb5_kdc_req(new_as_req);
	KRB_TGS_REQ_FORM (new_as_req,new_as_req, &config);
	send_krb5_kdc_req(sockfd,*new_as_req);
	recv_krb5_kdc_rep(sockfd,new_as_rep);
	//krb5_crypt_kdc_rep_part(new_as_rep->enc_part2,"Ivan");
	//krb5_decrypt_kdc_rep_part(new_as_rep->enc_part2,"Ivan");

	//krb5_decrypt_kdc_rep_part(new_as_rep->enc_part2,"Ivan");
	//fprintf(stderr,"%s",new_as_rep->enc_part2->session->contents);
	//krb5_crypt_enc_data(&as_rep->enc_part,"Ivan");
	//krb5_decrypt_enc_data(&as_rep->enc_part,"Ivan");
	krb5_ticket *ticket=calloc(1,sizeof(krb5_ticket));
	malloc_krb5_ticket(ticket);
	recv_krb5_ticket(sockfd,ticket);
	//NEED FUNCTION KRB_TGS_REP_CHECK

	krb5_authenticator *authen=calloc(1,sizeof(krb5_authenticator));
	malloc_krb5_authenticator(authen);
	//auth_form(&config,authen);
	krb5_ap_req *ap_req=calloc(1,sizeof(krb5_ap_req));
	malloc_krb5_ap_req(ap_req);
	krb_ap_req (ap_req);
	krb5_crypt_tkt_part(ticket->enc_part2,"Ivan");
	//krb5_decrypt_tkt_part(ticket->enc_part2,"Ivan");
	        	//fprintf(stderr,"%s",ticket->enc_part2->caddrs->contents);
	//krb5_decrypt_tkt_part(ticket->enc_part2,"Ivan");
	send_krb5_ap_req(sockfd,*ap_req);
	send_krb5_authenticator(sockfd,*authen);
	send_krb5_ticket(sockfd,*ticket);


	krb5_ap_rep *ap_rep=calloc(1,sizeof(krb5_ap_rep));
	malloc_krb5_ap_rep(ap_rep);
	recv_krb5_ap_rep(sockfd,ap_rep);

	krb5_authenticator *cleartext=calloc(1,sizeof(krb5_authenticator));
	malloc_krb5_authenticator(cleartext);
	krb_ap_rep_check(ap_rep, error, cleartext, authen);

	//free memory
	krb5_free_kdc_req(as_req);
	krb5_free_kdc_rep(as_rep);
	krb5_free_error(error);
	krb5_free_kdc_rep(new_as_rep);
	krb5_free_kdc_req(new_as_req);
	krb5_free_ticket(ticket);
	krb5_free_authenticator(authen);
	krb5_free_ap_req(ap_req);
	krb5_free_ap_rep(ap_rep);
	krb5_free_authenticator(cleartext);*/
	close(sockfd);
	ap_connect(new_as_rep->ticket,new_as_rep->enc_part2->session);
	exit(0);
}
