/*
 * check_krb5_as_rep.c
 *
 *  Created on: May 12, 2014
 *      Author: ivan
 */
#include "mess.h"
int check_krb5_as_rep(krb5_kdc_req *as_req,krb5_kdc_rep *as_rep,char *pass){
	krb5_decrypt_kdc_rep_part(as_rep->enc_part2,pass);
	if(as_rep->msg_type==KRB5_ERROR){
		perror("Error retries");
		return 1;}
/*	if( (strcmp(as_req->client->data->data,as_rep->client->data->data)) ||
		(strcmp(as_req->client->realm.data,as_rep->client->realm.data)) ||
		(strcmp(as_req->server->data->data,as_rep->enc_part2->server->data->data)) ||
	    (strcmp(as_req->server->realm.data,as_rep->enc_part2->server->realm.data)) ){
		perror("Error");
		return KRB_AP_ERR_MODIFIED;
	} */
	if(as_rep->enc_part2->flags!=as_req->kdc_options){
		return KRB_AP_ERR_MODIFIED;
	}
	if(as_req->from==0){
		return KRB_AP_ERR_MODIFIED;
	}
	if((as_req->from!=0) && (as_req->from!=as_rep->enc_part2->times.starttime)){
		return KRB_AP_ERR_MODIFIED;
	}
	if((as_req->till!=0) && (as_rep->enc_part2->times.renew_till > as_req->rtime)){
		return KRB_AP_ERR_MODIFIED;
	}
	if (int_to_bit(as_req->kdc_options, RENEWABLE) &&
		(as_req->rtime!=0) &&
		(as_rep->enc_part2->times.renew_till > as_req->rtime ) ){
		return KRB_AP_ERR_MODIFIED;
	}
	if( int_to_bit(as_req->kdc_options, RENEWABLE_OK) &&
		int_to_bit(as_rep->enc_part2->flags, RENEWABLE) &&
		(as_req->till!=0) &&
		(as_rep->enc_part2->times.renew_till > as_req->till) ){
		return KRB_AP_ERR_MODIFIED;
	}
	return 0;


}

