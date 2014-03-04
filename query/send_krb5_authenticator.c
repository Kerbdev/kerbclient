/*
 * send_krb5_authenticator.c
 *
 *  Created on: Feb 17, 2014
 *      Author: ivan
 */
#include "request.h"
void send_krb5_checksum(int sockfd,krb5_checksum *check){
	check->magic=htonl(check->magic);
	if (send(sockfd, &check->magic,sizeof(check->magic) , 0) == -1){
			                   perror("send");}
	check->checksum_type=htonl(check->checksum_type);
	if (send(sockfd, &check->checksum_type,sizeof(check->checksum_type) , 0) == -1){
			                   perror("send");}
	int len=check->length;
	check->length=htonl(check->length);
	if (send(sockfd, &check->length,sizeof(check->length) , 0) == -1){
									perror("send");}

	if (send(sockfd, (char *) check->contents,len , 0) == -1){
										perror("send");}
}
void send_krb5_authenticator(int sockfd,krb5_authenticator *auth){
	auth->magic=htonl(auth->magic);
	if (send(sockfd, &auth->magic,sizeof(auth->magic) , 0) == -1){
			                   perror("send");}
	send_principal_data(sockfd,*auth->client);
	send_krb5_checksum(sockfd,auth->checksum);
	auth->cusec=htonl(auth->cusec);
	if (send(sockfd, &auth->cusec,sizeof(auth->cusec) , 0) == -1){
				               perror("send");}
	auth->ctime=htonl(auth->ctime);
	if (send(sockfd, &auth->ctime,sizeof(auth->ctime) , 0) == -1){
				               perror("send");}
	send_krb5_keyblock(sockfd,*auth->subkey);
	auth->seq_number=htonl(auth->seq_number);
	if (send(sockfd, &auth->seq_number,sizeof(auth->seq_number) , 0) == -1){
			                   perror("send");}
	send_krb5_authdata(sockfd,*auth->authorization_data);
}

