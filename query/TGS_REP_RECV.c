#include "request.h"
void TGS_REP_RECV(int sockfd,struct TICKET ticket,struct SERVICE_TICKET service_ticket){

		if (recv(sockfd, ticket.id_client,MAXDATASIZE , 0) == -1)
	                        perror("recv");

	        if (recv(sockfd, ticket.ip_client, MAXDATASIZE , 0) == -1)
	            perror("recv");


		    if (recv(sockfd, (int *) &ticket.time_live,sizeof ticket.time_live , 0) == -1)
		                perror("recv");

		    if(recv(sockfd, ticket.sesion_key_client_service, MAXDATASIZE, 0) == -1)
		    	    	perror("recv");

		    	    if(recv(sockfd, ticket.time_data, MAXDATASIZE, 0) == -1)
		    	    	    	perror("recv");

		    	    	    if(recv(sockfd, service_ticket.id_service, MAXDATASIZE, 0) == -1)
		    	    	    	    	perror("recv");

		    	    	    	    if(recv(sockfd, (int *) &service_ticket.time_live, sizeof service_ticket.time_live , 0) == -1)
		    	    	    	    	    	perror("recv");

		    	    	    	    	    if(recv(sockfd, service_ticket.sesion_key_client_service, MAXDATASIZE, 0) == -1)
		    	    	    	    	    	    	perror("recv");}
