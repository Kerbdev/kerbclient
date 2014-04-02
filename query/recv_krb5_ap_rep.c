/*
 * recv_krb5_ap_rep.c
 *
 *  Created on: Feb 17, 2014
 *      Author: ivan
 */
#include "request.h"
void recv_krb5_ap_rep_enc_part(int sockfd,krb5_ap_rep_enc_part *req){
	if (recv(sockfd, &req->magic,sizeof(req->magic) , 0) == -1){
				                   perror("recv");}
		req->magic=ntohl(req->magic);
		if (recv(sockfd, &req->ctime,sizeof(req->ctime) , 0) == -1){
				                   perror("recv");}
		req->ctime=ntohl(req->ctime);

		if (recv(sockfd, &req->cusec,sizeof(req->cusec) , 0) == -1){
						                   perror("recv");}
				req->cusec=ntohl(req->cusec);


		recv_krb5_keyblock(sockfd,req->subkey);

		if (recv(sockfd, &req->seq_number,sizeof(req->seq_number) , 0) == -1){
						                   perror("recv");}
				req->seq_number=ntohl(req->seq_number);
}


void recv_krb5_ap_rep(int sockfd,krb5_ap_rep *req){
	if (recv(sockfd, &req->magic,sizeof(req->magic) , 0) == -1){
			                   perror("recv");}

	req->magic=ntohl(req->magic);
	fprintf(stderr,"%d",req->magic);
	if (recv(sockfd, &req->msg_type,sizeof(req->msg_type) , 0) == -1){
			                   perror("recv");}
	req->msg_type=ntohl(req->msg_type);
	recv_krb5_ap_rep_enc_part(sockfd,&req->enc_part);

}

