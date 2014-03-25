#include "message.h"
#include "../error/error.h"
void krb_ap_req (krb5_ap_req *packet,)
{
	/*obtain ticket and session_key from cache;*/
	//packet->ap_options = 10; // for example
	/* */
	packet->authenticator.kvno = pvno;
	/*packet.msg-type := message type; */
	if (MUTUAL_AUTH)
		packet->ap_opt.mutual_required = 1;
	else
		packet->ap_opt.mutual_required = NULL;
	if (/*using session key for ticket*/1)
		packet->ap_opt.use_session_key = 1;
	else packet->ap_opt.use_session_key = 0;
	/*packet.ticket := ticket; /* ticket
    generate authenticator;
    encode authenticator into OCTET STRING;
    encrypt OCTET STRING into packet.authenticator
                             using session_key;
	*/

}