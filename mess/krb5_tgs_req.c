/*
 * krb5_tgs_req.c
 *
 *  Created on: May 12, 2014
 *      Author: ivan
 */
#include "mess.h"
//tgs_req- request to tgs service
//as_rep - recive data from as server
void krb5_tgs_req(krb5_kdc_req *tgs_req,krb5_kdc_rep *as_rep,int kdc_options,configuration *config){
	tgs_req->msg_type=KRB5_TGS_REQ;
	tgs_req->kdc_options=kdc_options;
	tgs_req->server->data->data=config->server_name;
	tgs_req->server->realm.data=config->server_realm;
	if (int_to_bit(tgs_req->kdc_options, POSTDATED))
		tgs_req->from=as_rep->enc_part2->times.starttime;
	tgs_req->till=as_rep->enc_part2->times.endtime;
	if(int_to_bit(tgs_req->kdc_options, RENEWABLE))
		tgs_req->rtime=as_rep->enc_part2->times.renew_till;
	//if(int_to_bit(tgs_req->kdc_options, ENC_TKT_IN_SKEY))
	//	tgs_req->
	tgs_req->padata->pa_type=KRB5_AP_REQ;
	tgs_req->second_ticket=as_rep->ticket;

}
