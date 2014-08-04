/*
 * mess.h
 *
 *  Created on: May 6, 2014
 *      Author: ivan
 */

#ifndef MESS_H_
#define MESS_H_
#include "../krb/krb.h"
#include "../parser/get_config_param.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../error/error.h"
#include "../usefull_func/usefull.h"
#include "limits.h"
#define KEY_LENGHT 32
int check_krb5_tgs_rep(krb5_kdc_rep *tgs_rep,krb5_keyblock *session);
int check_krb5_tgs_req_and_imp_krb5_tgs_rep(krb5_kdc_req *tgs_req,krb5_kdc_rep *tgs_rep,configuration *conf);
void krb5_as_req(krb5_kdc_req *as_req,int kdc_options,configuration *config,char *name,char *passs);
int check_krb5_as_rep(krb5_kdc_req *as_req,krb5_kdc_rep *as_rep,char *pass);
void krb5_tgs_req(krb5_kdc_req *tgs_req,krb5_kdc_rep *as_rep,int kdc_options,configuration *config);
int krb5_auth(krb5_authenticator *auth,configuration *conf);
int krb5_ap_req_imp(krb5_ap_req *ap_req,krb5_authenticator *auth,krb5_ticket *ticket,krb5_keyblock *session,char *);
int check_krb5_ap_req(krb5_ap_req *ap_req,char *pass);
int check_krb5_as_req_and_imp_krb5_as_rep(krb5_kdc_req *as_req,krb5_kdc_rep *as_rep,configuration *config );
int check_krb5_ap_rep(krb5_ap_rep *as_rep,krb5_keyblock *session);
int krb5_ap_rep_imp(krb5_ap_rep *ap_rep,krb5_ap_req *ap_req);
int check_krb5_ap_req(krb5_ap_req *ap_req,char *pass);
#endif /* MESS_H_ */
