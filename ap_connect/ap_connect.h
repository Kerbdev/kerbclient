/*
 * ap_connect.h
 *
 *  Created on: Apr 11, 2014
 *      Author: ivan
 */

#ifndef AP_CONNECT_H_
#define AP_CONNECT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
void *get_in_addr(struct sockaddr *sa);
void ap_connect();
#endif /* AP_CONNECT_H_ */
