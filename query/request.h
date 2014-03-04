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
void recv_krb5_checksum(int,krb5_checksum *);
void send_krb5_data(int ,krb5_data);
void send_padata(int,krb5_pa_data );
void send_krb5_checksum(int ,krb5_checksum *);
void send_principal_data(int,krb5_principal_data );
void send_krb5_address(int,krb5_address );
void send_krb5_enc_data(int ,krb5_enc_data );
void send_krb5_authdata(int ,krb5_authdata );
void send_krb5_authenticator(int,krb5_authenticator *);
void send_krb5_keyblock(int ,krb5_keyblock );
void send_krb5_ticket_times(int ,krb5_ticket_times );
void send_krb5_transited(int ,krb5_transited );
void send_krb5_enc_tkt_part(int ,krb5_enc_tkt_part );
void send_krb5_ticket(int new_fd,krb5_ticket as_rep);
void recv_principal_data(int,krb5_principal_data *);
void recv_krb5_enc_data(int ,krb5_enc_data *);
void recv_krb5_data(int ,krb5_data *);
void send_krb5_kdc_req(int sockfd,krb5_kdc_req as_rep,char *FLAGS);
void recv_padata(int,krb5_pa_data *);
void recv_principal_data(int,krb5_principal_data *);
void recv_krb5_enc_data(int,krb5_enc_data *);
void recv_krb5_ticket(int ,krb5_ticket *);
void recv_krb5_keyblock(int,krb5_keyblock *);
void recv_krb5_ticket_times(int,krb5_ticket_times *);
void recv_krb5_address(int ,krb5_address *);
void recv_krb5_enc_kdc_rep_part(int,krb5_enc_kdc_rep_part *);
void recv_krb5_kdc_rep(int,krb5_kdc_rep *);
void recv_krb5_enc_tkt_part(int,krb5_enc_tkt_part *);
void recv_krb5_transited(int,krb5_transited *);
void recv_krb5_authdata(int,krb5_authdata *);
void send_krb5_ap_req(int,krb5_ap_req *);
void recv_krb5_kdc_rep(int,krb5_kdc_rep *);
void send_krb5_safe(int ,krb5_safe *);
void recv_krb5_safe(int,krb5_safe *);
void recv_krb5_cred_enc_part(int,krb5_cred_enc_part *);
void send_krb5_cred_enc_part(int,krb5_cred_enc_part *);
void send_krb5_cred_info(int,krb5_cred_info *);
void recv_krb5_cred_info(int,krb5_cred_info *);
//end func
void send_krb5_priv(int,krb5_priv *);
void recv_krb5_priv(int ,krb5_priv *);
void recv_krb5_cred(int,krb5_cred *);
void send_krb5_cred(int,krb5_cred *);
#endif /* REQUEST_H_ */
