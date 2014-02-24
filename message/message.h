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
void KRB_AS_REQ(krb5_kdc_req *kkk, krb5_pa_data *ppp);


#endif /* MESSAGE_H_ */
