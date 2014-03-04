/*
 * send_krb5_ap_req.c
 *
 *  Created on: Feb 17, 2014
 *      Author: ivan
 */
#include "request.h"
void send_krb5_ap_req(int sockfd,krb5_ap_req *req){
	req->magic=htonl(req->magic);
	if (send(sockfd, &req->magic,sizeof(req->magic) , 0) == -1){
			                   perror("send");}

	req->ap_options=htonl(req->ap_options);
	if (send(sockfd, &req->ap_options,sizeof(req->ap_options) , 0) == -1){
					                   perror("send");}
	send_krb5_ticket(sockfd,*req->ticket);
	send_krb5_enc_data(sockfd,req->authenticator);

}

