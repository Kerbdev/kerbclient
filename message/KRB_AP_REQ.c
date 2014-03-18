#include "message.h"
#include "../error/error.h"
void krb_ap_req (krb5_ap_req *req)
{
	/*obtain ticket and session_key from cache;*/
	int kvno = 5;
	/* */
	req->authenticator.kvno = kvno;
}