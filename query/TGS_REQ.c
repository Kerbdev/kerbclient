#include "request.h"
void TGS_REQ(int sockfd,char *id_service,struct TGT tgt,struct AUTH_CLIENT AUTH){
	//send ID service
	if(send(sockfd, id_service, MAXDATASIZE, 0) == -1)
			    	    	perror("recv");


	//send tgt copy session key Client/TGS
		    if(send(sockfd, tgt.sesion_key_client_TGS, MAXDATASIZE, 0) == -1)
		    	    	perror("recv");

		    //send tgt id client
		    	    if(send(sockfd, tgt.user_name, MAXDATASIZE, 0) == -1)
		    	    	    	perror("recv");
		    	    //send tgt mark time
		    	    	    if(send(sockfd, tgt.mark_time, MAXDATASIZE, 0) == -1)
		    	    	    	    	perror("recv");
		    	    	    //send tgt copy session key Client/TGS
		    	    	    	    if(send(sockfd, (int *) &tgt.time_live, sizeof tgt.time_live , 0) == -1)
		    	    	    	    	    	perror("recv");
		    	    	    	    //send tgt ip
		    	    	    	    	    if(send(sockfd, tgt.ip_client, MAXDATASIZE, 0) == -1)
		    	    	    	    	    	    	perror("recv");

	 //send auth information
	if(send(sockfd, AUTH.id_client, MAXDATASIZE, 0) == -1)
	perror("send");
	//send auth information
		if(send(sockfd, (int *) &AUTH.time_data, 4, 0) == -1)
		perror("send");



}
