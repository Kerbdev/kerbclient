/*
 * message.h
 *
 *  Created on: Feb 24, 2014
 *      Author: ivan
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_
#include <stdio.h>
#include "../krb/krb.h"
#include <time.h>
#include "../polarssl/entropy.h"
#include "../polarssl/ctr_drbg.h"
#include "../polarssl/aes.h"
#include "../parser/get_config_param.h"
#include "../usefull_func/usefull.h"
void KRB_AS_REQ(krb5_kdc_req *, krb5_pa_data *);
void krb_safe(krb5_safe *, krb5_kdc_rep *);
void krb_safe_check(krb5_safe *, krb5_kdc_rep *, krb5_error *);
void krb_priv (krb5_priv *, krb5_kdc_rep *);
void krb_priv_check (krb5_priv *, krb5_kdc_rep *, krb5_error *);
int krb_ap_rep_check(krb5_ap_rep *, krb5_error *, krb5_authenticator *, krb5_authenticator *);
void KRB_TGS_REQ_FORM (krb5_kdc_req *, krb5_kdc_req *,configuration *);
void KRB_TGS_REP_FORM(krb5_kdc_req *req, krb5_error *err, krb5_ticket *tkt, krb5_kdc_rep *rep);
void krb_error (krb5_error *, krb5_kdc_rep *);
void KRB_AS_REP(configuration ,krb5_kdc_rep *, krb5_kdc_req *, krb5_pa_data *, krb5_error *);
void KRB_AS_REP_CHECK(krb5_kdc_rep *, krb5_error *,krb5_kdc_req *kkk);
void krb_ap_req (krb5_ap_req *);
void krb_ap_req_check(krb5_kdc_req *, krb5_error *);
void AS_TGS_REP_CHECK(krb5_kdc_req *req, krb5_error *err, krb5_kdc_rep *resp, configuration config);
void auth_form(configuration *config, krb5_authenticator *auth);

#endif /* MESSAGE_H_ */
