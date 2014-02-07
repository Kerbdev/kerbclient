#include "request.h"
void Connect_to_service(int sockfd,struct AUTH_CLIENT NEW_AUTH,struct SERVICE_TICKET service_ticket){
	//AC send to client session key Client/TGS
		if (send(sockfd, NEW_AUTH.id_client,MAXDATASIZE , 0) == -1)
	                        perror("send");

	            //send ID client
	        if (send(sockfd, (int *) &NEW_AUTH.time_data, 4 , 0) == -1)
	            perror("send");

		    	    //send tgt mark time
		    	    	    if(send(sockfd, service_ticket.id_service, MAXDATASIZE, 0) == -1)
		    	    	    	    	perror("send");
		    	    	    //send tgt copy session key Client/TGS
		    	    	    	    if(send(sockfd, (int *) &service_ticket.time_live, sizeof service_ticket.time_live , 0) == -1)
		    	    	    	    	    	perror("send");
		    	    	    	    //send tgt ip
		    	    	    	    	    if(send(sockfd, service_ticket.sesion_key_client_service, MAXDATASIZE, 0) == -1)
		    	    	    	    	    	    	perror("send");}
