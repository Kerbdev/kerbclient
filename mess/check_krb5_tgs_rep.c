/*
 * check_krb5_tgs_rep.c
 *
 *  Created on: May 16, 2014
 *      Author: ivan
 */
#include "mess.h"
int check_krb5_tgs_rep(krb5_kdc_rep *tgs_rep,krb5_keyblock *session){
	krb5_decrypt_kdc_rep_part(tgs_rep->enc_part2,session->contents);
	if(tgs_rep->enc_part2->session->contents==NULL){
		perror("ERROR");
		return 1;}
	return 0;


}

