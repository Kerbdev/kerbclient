/*
 * KRB_AS_REQ.c
 *
 *  Created on: May 6, 2014
 *      Author: ivan
 */
#include "mess.h"
//without pre_authentication
void krb5_as_req(krb5_kdc_req *as_req,int kdc_options,configuration *config,char *name,char *passs){

	as_req->msg_type=KRB5_AS_REQ;
	//pre_authentication
	time_t start=time(NULL);
	as_req->padata->pa_type=start;
	krb5_crypt_pa_data(as_req->padata,passs);
	as_req->kdc_options=kdc_options;
	as_req->client->data->data=malloc(strlen(name)+1);
	strcpy(as_req->client->data->data,name);
	as_req->client->realm.data=config->realm;
	as_req->server->realm.data=config->server_name;
	if (int_to_bit(as_req->kdc_options, POSTDATED))
		as_req->from=start;
	else as_req->from=0;
	as_req->till=start+config->max_life*3600;
	if (int_to_bit(as_req->kdc_options, RENEWABLE))
		as_req->rtime=config->max_renewable_life;
}

