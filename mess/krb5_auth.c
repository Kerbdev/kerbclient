/*
 * krb5_auth.c
 *
 *  Created on: May 16, 2014
 *      Author: ivan
 */
#include "mess.h"
int krb5_auth(krb5_authenticator *auth,configuration *conf){
	time_t sys_time=time(NULL);
	auth->client->realm.data=conf->realm;
	auth->ctime=sys_time;
	auth->cusec=sys_time;
	return 0;
}
