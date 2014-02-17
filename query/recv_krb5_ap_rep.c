/*
 * recv_krb5_ap_rep.c
 *
 *  Created on: Feb 17, 2014
 *      Author: ivan
 */
#include "request.h"
void recv_krb5_ap_rep(int sockfd,krb5_ap_rep *req){
	if (recv(sockfd, &req->magic,sizeof(req->magic) , 0) == -1){
			                   perror("recv");}
	req->magic=ntohl(req->magic);
	recv_krb5_enc_data(sockfd,&req->enc_part);

}

