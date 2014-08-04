/*
 * krb5_ap_rep.c
 *
 *  Created on: May 16, 2014
 *      Author: ivan
 */

#include "mess.h"
int krb5_ap_rep_imp(krb5_ap_rep *ap_rep,krb5_ap_req *ap_req){
	ap_rep->msg_type=KRB5_AP_REP;
	ap_rep->enc_part.subkey->contents="as_dasd";
	krb5_crypt_ap_rep_enc_part(&ap_rep->enc_part,ap_req->ticket->enc_part2->session->contents);
	return 0;

}
