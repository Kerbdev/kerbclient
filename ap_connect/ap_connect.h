/*
 * ap_connect.h
 *
 *  Created on: Apr 11, 2014
 *      Author: ivan
 */

#ifndef AP_CONNECT_H_
#define AP_CONNECT_H_

#include "../query/request.h"
void *get_in_addr(struct sockaddr *sa);
void ap_connect(krb5_ticket *ticket,krb5_keyblock *session);
#endif /* AP_CONNECT_H_ */
