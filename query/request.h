/*
 * request.h
 *
 *  Created on: Jan 10, 2014
 *      Author: ivan
 */

#ifndef REQUEST_H_
#define REQUEST_H_
#include "../krb/krb.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "request.h"
#define MAXDATASIZE 1024
#include <arpa/inet.h>
void Client_to_AS_REQ(int sockfd,char *date_time,char *user_name,krb5_kdc_req *as_rep,char *server_msg,char *FLAGS);
struct TGT{
	char sesion_key_client_TGS[MAXDATASIZE];
	char user_name[MAXDATASIZE];
	int time_live;
	char mark_time[MAXDATASIZE];
	char ip_client[MAXDATASIZE];
};
struct AUTH_CLIENT{
	char id_client[MAXDATASIZE];
	int time_data;
};
struct TICKET{
	char id_client[MAXDATASIZE];
	char ip_client[MAXDATASIZE];
	char time_data[MAXDATASIZE];
	int time_live;
	char sesion_key_client_service[MAXDATASIZE];

};
struct SERVICE_TICKET{
	char sesion_key_client_service[MAXDATASIZE];
	char id_service[MAXDATASIZE];
	int time_live;

};
int confirm(int sockfd,struct AUTH_CLIENT NEW_AUTH);
void Connect_to_service(int sockfd,struct AUTH_CLIENT NEW_AUTH,struct SERVICE_TICKET service_ticket);
void TGS_REP_RECV(int sockfd,struct TICKET ticket,struct SERVICE_TICKET service_ticket);
void TGS_REQ(int sockfd,char *id_service,struct TGT tgt,struct AUTH_CLIENT AUTH);
void AS_RECV(int sockfd,char *session_key_client_tgs_secret,char *id_server_secret,int time_live_secret,struct TGT *tgt);
#endif /* REQUEST_H_ */
