
#include "message.h"
#include "../error/error.h"
void KRB_TGS_REQ_FORM (krb5_kdc_req *req,krb5_kdc_req *body, configuration *config)
{
	/* recieving structure req;
	req->msg_type = KRB5_TGS_REQ;
	*/
	body->kdc_options = 10; //user preferences;
	body->server->data->data = "server";
	body->server->realm.data = "realm";
	if (int_to_bit(req->kdc_options, POSTDATED))
	{
		body->from = time(NULL);
	}
	else
	{
		body->from = 0;
	}
	req->till = req->from + config->max_life;
	if (int_to_bit(req->kdc_options, RENEWABLE))
	{
		body->rtime = config->max_renewable_life;
	}
	body->nonce = 0; //random nonce
	body->ktype = 1; //requested etypes
	/*
	if (user supplied addresses) then
                body.addresses := user's addresses;
        else
                omit body.addresses;
        endif
	*/
	//body->authorization_data = user-supplied data;
	if (int_to_bit(req->kdc_options, ENC_TKT_IN_SKEY))
	{
		/* body.additional-tickets_ticket := second TGT;*/
	}
	/* request.req-body := body; */
	/* check := generate_checksum (req.body,checksumtype);*/
	req->padata->pa_type = 1; //PA-TGS-REQ
	req->padata->contents = 0; //create a KRB_AP_REQ using the TGT and checksum

	/*
	kerberos := lookup(name of local kerberose server (or servers));
        send(packet,kerberos);

        wait(for response);
        if (timed_out) then
                retry or use alternate server;
        endif

		*/

}
