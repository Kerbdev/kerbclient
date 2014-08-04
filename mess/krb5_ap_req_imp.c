/*
 * krb5_ap_req.c
 *
 *  Created on: May 16, 2014
 *      Author: ivan
 */
#include "mess.h"
int krb5_ap_req_imp(krb5_ap_req *ap_req,krb5_authenticator *auth,krb5_ticket *ticket,krb5_keyblock *session,char *name){
	ap_req->msg_type=KRB5_AP_REQ;
	ap_req->ticket=ticket;
	ap_req->authenticator=auth;
	ap_req->authenticator->authorization_data->contents=realloc(ap_req->authenticator->authorization_data->contents,strlen(name)+1);
	strcpy(ap_req->authenticator->authorization_data->contents,name);
	krb5_crypt_authenticator(ap_req->authenticator,session->contents);
	return 0;
}

