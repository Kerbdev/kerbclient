/*
 * recv_krb5_kdc_rep.c
 *
 *  Created on: Feb 17, 2014
 *      Author: ivan
 */
#include "request.h"
void recv_krb5_enc_data(int sockfd,krb5_enc_data *as_rep){

			if (recv(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
			                   perror("recv");}
			as_rep->magic=ntohl(as_rep->magic);

			if (recv(sockfd, &as_rep->enctype,sizeof(as_rep->enctype) , 0) == -1){
					                   perror("recv");}
			as_rep->enctype=ntohl(as_rep->enctype);

			if (recv(sockfd, &as_rep->kvno,sizeof(as_rep->kvno) , 0) == -1){
					                   perror("recv");}
			as_rep->kvno=ntohl(as_rep->kvno);
	recv_krb5_data(sockfd,&as_rep->ciphertext);

}
void recv_krb5_transited(int sockfd,krb5_transited *as_rep){

		if (recv(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
						                   perror("recv");}
		as_rep->magic=ntohl(as_rep->magic);

		if (recv(sockfd, &as_rep->tr_type,sizeof(as_rep->tr_type) , 0) == -1){
							               perror("recv");}
		as_rep->tr_type=ntohl(as_rep->tr_type);
	recv_krb5_data(sockfd,&as_rep->tr_contents);
}
void recv_krb5_authdata(int sockfd,krb5_authdata *as_rep){
				if (recv(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
				                   perror("recv");}
				as_rep->magic=ntohl(as_rep->magic);

				if (recv(sockfd, &as_rep->ad_type,sizeof(as_rep->ad_type) , 0) == -1){
						           perror("recv");}
				as_rep->ad_type=ntohl(as_rep->ad_type);

				if (recv(sockfd, &as_rep->length,sizeof(as_rep->length) , 0) == -1){
								perror("recv");}
				as_rep->length=ntohl(as_rep->length);
				if (recv(sockfd, (char *) as_rep->contents,as_rep->length , 0) == -1){
								perror("recv");}

}
void recv_krb5_enc_tkt_part(int sockfd,krb5_enc_tkt_part *as_rep){
	if (recv(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
					                   perror("recv");}
	as_rep->magic=ntohl(as_rep->magic);

	if (recv(sockfd, &as_rep->flags,sizeof(as_rep->flags) , 0) == -1){
									   perror("recv");}
	as_rep->flags=ntohl(as_rep->flags);
	recv_krb5_keyblock(sockfd,as_rep->session);
	recv_principal_data(sockfd,as_rep->client);
	recv_krb5_transited(sockfd,&as_rep->transited);
	recv_krb5_ticket_times(sockfd,&as_rep->times);
	recv_krb5_address(sockfd,as_rep->caddrs);
	recv_krb5_authdata(sockfd,as_rep->authorization_data);
}
void recv_krb5_ticket(int sockfd,krb5_ticket *as_rep){

	if (recv(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
				                   perror("recv");}
	as_rep->magic=ntohl(as_rep->magic);
	recv_principal_data(sockfd,as_rep->server);
	recv_krb5_enc_data(sockfd,&as_rep->enc_part);
	recv_krb5_enc_tkt_part(sockfd,as_rep->enc_part2);

}
void recv_padata(int new_fd,krb5_pa_data *as_rep){
	if (recv(new_fd, &as_rep->length,sizeof(as_rep->length) , 0) == -1){
			                   perror("recv");}
	as_rep->length=ntohl(as_rep->length);

	if (recv(new_fd, (char *) as_rep->contents,as_rep->length , 0) == -1){
		                   perror("recv");}
	if (recv(new_fd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
			                   perror("recv");}
	as_rep->magic=ntohl(as_rep->magic);
	if (recv(new_fd, &as_rep->pa_type,sizeof(as_rep->pa_type) , 0) == -1){
			                   perror("recv");}
	as_rep->pa_type=ntohl(as_rep->pa_type);

}
void recv_krb5_keyblock(int sockfd,krb5_keyblock *as_rep){

	if (recv(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
					                   perror("recv");}
	as_rep->magic=ntohl(as_rep->magic);

	if (recv(sockfd, &as_rep->enctype,sizeof(as_rep->enctype) , 0) == -1){
									   perror("recv");}
	as_rep->enctype=ntohl(as_rep->enctype);

	if (recv(sockfd, &as_rep->length,sizeof(as_rep->length) , 0) == -1){
									perror("recv");}
	as_rep->length=ntohl(as_rep->length);

	if (recv(sockfd, (char *) as_rep->contents,as_rep->length , 0) == -1){
										perror("recv");}

}
void recv_krb5_last_req_entry(int new_fd,krb5_last_req_entry *req){

	if (recv(new_fd, &req->magic,sizeof(req->magic) , 0) == -1){
					                   perror("recv");}
	req->magic=ntohl(req->magic);

	if (recv(new_fd, &req->lr_type,sizeof(req->lr_type) , 0) == -1){
							           perror("recv");}

	req->lr_type=ntohl(req->lr_type);

	if (recv(new_fd, &req->lr_type,sizeof(req->value) , 0) == -1){
							           perror("recv");}
	req->value=ntohl(req->value);




}
void recv_krb5_ticket_times(int sockfd,krb5_ticket_times *as_rep){

	if (recv(sockfd, &as_rep->authtime,sizeof(as_rep->authtime) , 0) == -1){
			                   perror("recv");}
	as_rep->authtime=ntohl(as_rep->authtime);


	if (recv(sockfd, &as_rep->starttime,sizeof(as_rep->starttime) , 0) == -1){
					                   perror("recv");}
	as_rep->starttime=ntohl(as_rep->starttime);

	if (recv(sockfd, &as_rep->endtime,sizeof(as_rep->endtime) , 0) == -1){
					                   perror("recv");}
	as_rep->endtime=ntohl(as_rep->endtime);
	if (recv(sockfd, &as_rep->renew_till,sizeof(as_rep->renew_till) , 0) == -1){
							            perror("recv");}
	as_rep->renew_till=ntohl(as_rep->renew_till);
}
void recv_krb5_address(int sockfd,krb5_address *as_rep){
		if (recv(sockfd, &as_rep->magic,sizeof(as_rep->magic) , 0) == -1){
						                   perror("recv");}
		as_rep->magic=ntohl(as_rep->magic);

		if (recv(sockfd, &as_rep->addrtype,sizeof(as_rep->addrtype) , 0) == -1){
							               perror("recv");}
		as_rep->addrtype=ntohl(as_rep->addrtype);
		if (recv(sockfd, &as_rep->length,sizeof(as_rep->length) , 0) == -1){
					                   perror("recv");}
		as_rep->length=ntohl(as_rep->length);

		if (recv(sockfd, (char *) as_rep->contents,as_rep->length , 0) == -1){
				                   perror("recv");}
}
void recv_krb5_enc_kdc_rep_part(int new_fd,krb5_enc_kdc_rep_part *req){

	if (recv(new_fd, &req->magic,sizeof(req->magic) , 0) == -1){
				                   perror("recv");}
	req->magic=ntohl(req->magic);
	if (recv(new_fd, &req->msg_type,sizeof(req->msg_type) , 0) == -1){
						           perror("recv");}
	req->msg_type=ntohl(req->msg_type);
	recv_krb5_keyblock(new_fd,req->session);
	recv_krb5_last_req_entry(new_fd,req->last_req);

	if (recv(new_fd, &req->nonce,sizeof(req->nonce) , 0) == -1){
			                   perror("recv");}
	req->nonce=ntohl(req->nonce);
	if (recv(new_fd, &req->key_exp,sizeof(req->key_exp) , 0) == -1){
					           perror("recv");}
	req->key_exp=ntohl(req->key_exp);
	if (recv(new_fd, &req->flags,sizeof(req->flags) , 0) == -1){
			                   perror("recv");}
	req->flags=ntohl(req->flags);

	recv_krb5_ticket_times(new_fd,&req->times);
	recv_principal_data(new_fd,req->server);
	recv_krb5_address(new_fd,req->aaddrs);
}

void recv_krb5_kdc_rep(int new_fd,krb5_kdc_rep *req){

	if (recv(new_fd, &req->magic,sizeof(req->magic) , 0) == -1){
			                   perror("recv");}
	req->magic=ntohl(req->magic);


	if (recv(new_fd, &req->msg_type,sizeof(req->msg_type) , 0) == -1){
					           perror("recv");}
	req->msg_type=ntohl(req->msg_type);
	recv_padata(new_fd,req->padata);
	recv_principal_data(new_fd,req->client);
	recv_krb5_ticket(new_fd,req->ticket);
	recv_krb5_enc_data(new_fd,&req->enc_part);
	recv_krb5_enc_kdc_rep_part(new_fd,req->enc_part2);

}

