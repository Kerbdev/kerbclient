#include "request.h"
int confirm(int sockfd,struct AUTH_CLIENT NEW_AUTH){
	int b=++(NEW_AUTH.time_data);
	if (recv(sockfd, (int *) &NEW_AUTH.time_data,4 , 0) == -1)
		                        perror("send");
	return (b==NEW_AUTH.time_data);


}
