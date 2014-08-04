/*
 * check_krb5_ap_rep.c
 *
 *  Created on: May 16, 2014
 *      Author: ivan
 */

#include "mess.h"
int check_krb5_ap_rep(krb5_ap_rep *as_rep,krb5_keyblock *session	){
	 if(as_rep->msg_type!=KRB5_AP_REP){
		perror("KRB_AP_ERR_MSG_TYPE");
		return KRB_AP_ERR_MSG_TYPE;
	}
	krb5_decrypt_ap_rep_enc_part(&as_rep->enc_part,session->contents);
	fprintf(stderr,"Key marsh:%s",as_rep->enc_part.subkey->contents);
	return 0;
}
