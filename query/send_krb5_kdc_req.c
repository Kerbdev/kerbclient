#include "request.h"

void recv_principal_data(int sockfd,krb5_principal_data *as_rep){

		if (recv(sockfd, &as_rep->length,sizeof(as_rep->length) , 0) == -1){
				                   perror("recv");}
		as_rep->length=ntohl(as_rep->length);
		recv_krb5_data(sockfd,(krb5_data *) &as_rep->realm);
		recv_krb5_data(sockfd,as_rep->data);


		if (recv(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
						                   perror("recv");}
		as_rep->magic=ntohl(as_rep->magic);

		if (recv(sockfd, &as_rep->type,sizeof(as_rep->type) , 0) == -1){
								                   perror("recv");}
		as_rep->type=ntohl(as_rep->type);


}

void recv_krb5_data(int sockfd,krb5_data *as_rep){

	if (recv(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
					                   perror("recv");}
	as_rep->magic=ntohl(as_rep->magic);

	if (recv(sockfd, &as_rep->length,sizeof(as_rep->length) , 0) == -1){
						                   perror("recv");}
	as_rep->length=ntohl(as_rep->length);
	if (recv(sockfd, as_rep->data,as_rep->length , 0) == -1){
						                   perror("recv");}

}
void send_padata(int sockfd,krb5_pa_data *as_rep){
	as_rep->contents=(krb5_octet *)"Hello";
	//as_rep->magic=3;
	//as_rep->pa_type=2;
	as_rep->length=strlen((char *) as_rep->contents);
	int len=as_rep->length;
	as_rep->length=htonl(as_rep->length);
	if (send(sockfd, &as_rep->length,sizeof(as_rep->length) , 0) == -1){
			                   perror("send");}

	if (send(sockfd, (char *) as_rep->contents,len , 0) == -1){
		                   perror("send");}
	as_rep->magic=htonl(as_rep->magic);
	if (send(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
			                   perror("send");}
	as_rep->pa_type=htonl(as_rep->pa_type);
	if (send(sockfd, &as_rep->pa_type,sizeof(as_rep->pa_type) , 0) == -1){
			                   perror("send");}

}

void send_principal_data(int sockfd,krb5_principal_data *as_rep){
	    as_rep->length=htonl(as_rep->length);
		if (send(sockfd, &as_rep->length,sizeof(as_rep->length) , 0) == -1){
				                   perror("send");}
		send_krb5_data(sockfd,(krb5_data *) &as_rep->realm);
		send_krb5_data(sockfd,as_rep->data);

		as_rep->magic=htonl(as_rep->magic);
		if (send(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
						                   perror("send");}
		as_rep->type=htonl(as_rep->type);
		if (send(sockfd, &as_rep->type,sizeof(as_rep->type) , 0) == -1){
								                   perror("send");}



}

void send_krb5_data(int sockfd,krb5_data *as_rep){
	as_rep->magic=htonl(as_rep->magic);
	if (send(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
					                   perror("send");}
	as_rep->length=strlen(as_rep->data);
	int len=as_rep->length;
	as_rep->length=htonl(as_rep->length);
	if (send(sockfd, &as_rep->length,sizeof(as_rep->length) , 0) == -1){
						                   perror("send");}
	if (send(sockfd, as_rep->data,len , 0) == -1){
						                   perror("send");}

}


void send_krb5_address(int sockfd,krb5_address *as_rep){
	as_rep->magic=htonl(as_rep->magic);
		if (send(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
						                   perror("send");}
	as_rep->addrtype=htonl(as_rep->addrtype);
		if (send(sockfd, &as_rep->addrtype,sizeof(as_rep->addrtype) , 0) == -1){
							               perror("send");}
	as_rep->length=strlen((char *) as_rep->contents);
	int len=as_rep->length;
	as_rep->length=htonl(as_rep->length);
		if (send(sockfd, &as_rep->length,sizeof(as_rep->length) , 0) == -1){
					                   perror("send");}

		if (send(sockfd, (char *) as_rep->contents,len , 0) == -1){
				                   perror("send");}
}
void send_krb5_enc_data(int sockfd,krb5_enc_data *as_rep){
	as_rep->magic=htonl(as_rep->magic);
			if (send(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
			                   perror("send");}

	as_rep->enctype=htonl(as_rep->enctype);
			if (send(sockfd, &as_rep->enctype,sizeof(as_rep->enctype) , 0) == -1){
					                   perror("send");}
	as_rep->kvno=htonl(as_rep->kvno);
			if (send(sockfd, &as_rep->kvno,sizeof(as_rep->kvno) , 0) == -1){
					                   perror("send");}

	send_krb5_data(sockfd,&as_rep->ciphertext);

}
void send_krb5_authdata(int sockfd,krb5_authdata *as_rep){
	as_rep->magic=htonl(as_rep->magic);
				if (send(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
				                   perror("send");}

	as_rep->ad_type=htonl(as_rep->ad_type);
				if (send(sockfd, &as_rep->ad_type,sizeof(as_rep->ad_type) , 0) == -1){
						           perror("send");}
	int len=as_rep->length;
	as_rep->length=htonl(as_rep->length);
				if (send(sockfd, &as_rep->length,sizeof(as_rep->length) , 0) == -1){
								perror("send");}

				if (send(sockfd, (char *) as_rep->contents,len , 0) == -1){
								perror("send");}

}
void send_krb5_keyblock(int sockfd,krb5_keyblock *as_rep){
	as_rep->magic=htonl(as_rep->magic);
	if (send(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
					                   perror("send");}
	as_rep->enctype=htonl(as_rep->enctype);
	if (send(sockfd, &as_rep->enctype,sizeof(as_rep->enctype) , 0) == -1){
									   perror("send");}
	int len=as_rep->length;
	as_rep->length=htonl(as_rep->length);
	if (send(sockfd, &as_rep->length,sizeof(as_rep->length) , 0) == -1){
									perror("send");}

	if (send(sockfd, (char *) as_rep->contents,len , 0) == -1){
										perror("send");}

}
void send_krb5_ticket_times(int sockfd,krb5_ticket_times *as_rep){
	as_rep->authtime=htonl(as_rep->authtime);
			if (send(sockfd, &as_rep->authtime,sizeof(as_rep->authtime) , 0) == -1){
			                   perror("send");}

			as_rep->starttime=htonl(as_rep->starttime);
			if (send(sockfd, &as_rep->starttime,sizeof(as_rep->starttime) , 0) == -1){
					                   perror("send");}
			as_rep->endtime=htonl(as_rep->endtime);
					if (send(sockfd, &as_rep->endtime,sizeof(as_rep->endtime) , 0) == -1){
					                   perror("send");}

					as_rep->renew_till=htonl(as_rep->renew_till);
					if (send(sockfd, &as_rep->renew_till,sizeof(as_rep->renew_till) , 0) == -1){
							                   perror("send");}



}
void send_krb5_transited(int sockfd,krb5_transited *as_rep){
	as_rep->magic=htonl(as_rep->magic);
		if (send(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
						                   perror("send");}
	as_rep->tr_type=htonl(as_rep->tr_type);
		if (send(sockfd, &as_rep->tr_type,sizeof(as_rep->tr_type) , 0) == -1){
							               perror("send");}
	send_krb5_data(sockfd,&as_rep->tr_contents);
}

void send_krb5_enc_tkt_part(int sockfd,krb5_enc_tkt_part *as_rep){
	as_rep->magic=htonl(as_rep->magic);
					if (send(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
					                   perror("send");}
	as_rep->flags=htonl(as_rep->flags);
					if (send(sockfd, &as_rep->flags,sizeof(as_rep->flags) , 0) == -1){
									   perror("send");}
	send_krb5_keyblock(sockfd,as_rep->session);
	send_principal_data(sockfd,as_rep->client);
	send_krb5_transited(sockfd,&as_rep->transited);
	send_krb5_ticket_times(sockfd,&as_rep->times);
	send_krb5_address(sockfd,as_rep->caddrs);
	send_krb5_authdata(sockfd,as_rep->authorization_data);
}


void send_krb5_ticket(int sockfd,krb5_ticket *as_rep){
	as_rep->magic=htonl(as_rep->magic);
				if (send(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
				                   perror("send");}
	send_principal_data(sockfd,as_rep->server);
	send_krb5_enc_data(sockfd,&as_rep->enc_part);
	send_krb5_enc_tkt_part(sockfd,as_rep->enc_part2);

}

void send_krb5_kdc_req(int sockfd,krb5_kdc_req *as_rep,char *FLAGS){


		as_rep->magic=htonl(as_rep->magic);
		if (send(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
		                   perror("send");}

		as_rep->msg_type=htonl(as_rep->msg_type);
		if (send(sockfd, &as_rep->msg_type,sizeof(as_rep->msg_type) , 0) == -1){
				                   perror("send");}


		send_padata(sockfd,as_rep->padata);
		as_rep->kdc_options=htonl(as_rep->kdc_options);

		if (send(sockfd, &as_rep->kdc_options,sizeof(as_rep->kdc_options) , 0) == -1){
						                   perror("send");}

		send_principal_data(sockfd,as_rep->client);
		send_principal_data(sockfd,as_rep->server);

		as_rep->from=htonl(as_rep->from);
				if (send(sockfd, &as_rep->from,sizeof(as_rep->from) , 0) == -1){
						                   perror("send");}

		as_rep->till=htonl(as_rep->till);
				if (send(sockfd, &as_rep->till,sizeof(as_rep->till) , 0) == -1){
								           perror("send");}
		as_rep->rtime=htonl(as_rep->rtime);
				if (send(sockfd, &as_rep->rtime,sizeof(as_rep->rtime) , 0) == -1){
										   perror("send");}

		as_rep->nonce=htonl(as_rep->nonce);
				if (send(sockfd, &as_rep->nonce,sizeof(as_rep->nonce) , 0) == -1){
										perror("send");}
		as_rep->nktypes=htonl(as_rep->nktypes);
				if (send(sockfd, &as_rep->nktypes,sizeof(as_rep->nktypes) , 0) == -1){
										perror("send");}
		*as_rep->ktype=htonl(*as_rep->ktype);
				if (send(sockfd, as_rep->ktype,sizeof(*as_rep->ktype) , 0) == -1){
										perror("send");}
		as_rep->nktypes=htonl(as_rep->nktypes);
				if (send(sockfd, &as_rep->nktypes,sizeof(as_rep->nktypes) , 0) == -1){
										perror("send");}
		as_rep->nktypes=htonl(as_rep->nktypes);
				if (send(sockfd, &as_rep->nktypes,sizeof(as_rep->nktypes) , 0) == -1){
										perror("send");}
		send_krb5_address(sockfd,as_rep->addresses);
		send_krb5_authdata(sockfd,as_rep->unenc_authdata);
		send_krb5_ticket(sockfd,as_rep->second_ticket);

}
