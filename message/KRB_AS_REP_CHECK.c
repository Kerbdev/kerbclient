#include "message.h"
#include "../error/error.h"
void KRB_AS_REP_CHECK(krb5_kdc_rep *resp, krb5_error *err, krb5_kdc_req *kkk)
{
	int ko = 10;
	char* db_client = "client";
	char* db_server = "server";
	time_t kdc_time = time(NULL);
	int pa_enc_timestamp_required = NULL;
	/* error filling */
	err->client->data->data = db_client;
	err->server->data->data = db_server;
	err->stime = kdc_time;
	err->error = KDC_ERR_NONE;
	/* end */
	//decode response into resp;
	if (resp->msg_type == KRB5_ERROR)
	{
		if (err->error == KDC_ERR_PREAUTH_REQUIRED)
		{
			pa_enc_timestamp_required = 1;
			resp->enc_part2->session->contents = NULL;
			KRB_AS_REQ(kkk, kkk ->padata);
		}
		return;
	}
}