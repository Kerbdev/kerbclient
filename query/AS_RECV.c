#include "request.h"
void AS_RECV(int sockfd,char *session_key_client_tgs_secret,char *id_server_secret,int time_live_secret,struct TGT *tgt){
	//client recv session key Client/TGS
	if ((recv(sockfd, session_key_client_tgs_secret, MAXDATASIZE, 0)) == -1) {
			perror("recv");
			exit(1);
		}
	//client recv id server
	if ((recv(sockfd, id_server_secret, MAXDATASIZE, 0)) == -1) {
				perror("recv");
				exit(1);
			}
	//recv time live
	if ((recv(sockfd, (int *)&time_live_secret, sizeof time_live_secret, 0)) == -1) {
				perror("recv");
				exit(1);
			}
	//rcv tgt copy session key Client/TGS
	if ((recv(sockfd, tgt->sesion_key_client_TGS, MAXDATASIZE, 0)) == -1) {
				perror("recv");
				exit(1);
			}
	//recv tgt id client
	if ((recv(sockfd, tgt->user_name, MAXDATASIZE, 0)) == -1) {
				perror("recv");
				exit(1);
			}
	//recv tgt mark time
	if ((recv(sockfd, tgt->mark_time, MAXDATASIZE, 0)) == -1) {
					perror("recv");
					exit(1);
				}
	//recv time live
	if ((recv(sockfd, (int *) &tgt->time_live, sizeof tgt->time_live, 0)) == -1) {
					perror("recv");
					exit(1);
				}
	//recv tgt ip
	if ((recv(sockfd, (int *) tgt->ip_client, MAXDATASIZE, 0)) == -1) {
						perror("recv");
						exit(1);
					}}
