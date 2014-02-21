#include <stdio.h>
#include <krb.h>
//#include <error.h>
#include <time.h>
#include <polarssl\entropy.h>
#include <polarssl\ctr_drbg.h>
#include <polarssl\aes.h>
#include "parser\get_config_param.h"
#include "usefull_func\usefull.h"
const char* clientpass = "12345"; // pass
ctr_drbg_context ctr_drbg;
entropy_context entropy;
unsigned char key[32];
unsigned char iv[16];
int ret;
krb5_preauthtype padatatype;
int is_pa_enc_timestamp_required = 0;
int chk;
aes_context aes;
unsigned char* input;
unsigned char output[128];
size_t input_len = 40;
size_t output_len = 0;
struct tm *ptr;
char str[80];
int ko = 10; // kdc-options
configuration conf;
time_t starttime = time(NULL);
time_t endtime = starttime + conf.max_life * 3600;
void KRB_AS_REQ(krb5_kdc_req *kkk, krb5_pa_data *ppp)
	{   kkk->msg_type=10;
		int pver = pvno; // Kerb ver
		kkk->msg_type = 10; // Msg type
		if (is_pa_enc_timestamp_required)
			ppp->pa_type = 0; // Pre-auth type check
				/* generating client key */
		entropy_init( &entropy );
		if((ret = ctr_drbg_init(&ctr_drbg, entropy_func, &entropy,
			(unsigned char *)clientpass, strlen(clientpass))) != 0 )
			printf(" failed\n ! ctr_drbg_init returned -0x%04x\n", -ret);
		if((ret = ctr_drbg_random(&ctr_drbg, key, 32)) != 0)
			printf(" failed\n ! ctr_drbg_random returned -0x%04x\n", -ret);
		/* end */

		/* generating iv */
		entropy_init( &entropy );
		if((ret = ctr_drbg_init(&ctr_drbg, entropy_func, &entropy,
			(unsigned char*)clientpass, strlen(clientpass))) != 0)
			printf(" failed\n ! ctr_drbg_init returned -0x%04x\n", -ret);
		if((ret = ctr_drbg_random(&ctr_drbg, iv, 16)) != 0)
			printf(" failed\n ! ctr_drbg_random returned -0x%04x\n", -ret);
		/* end */

		/* encrypting */
		time_t clienttime = time(NULL);
		ptr = localtime(&clienttime);
		strftime(str, 100, "%d%m%Y%H%M", ptr);
		input = (unsigned char*)str;
		aes_setkey_enc(&aes, key, 256);
		aes_crypt_cbc(&aes, AES_ENCRYPT, 12, iv, input, output);
		/* end */
		kkk->client->data->data = "client";
		kkk->server->data->data = "server";
		//kkk->client->realm = "realm";
		if (int_to_bit(ko, POSTDATED))
			kkk->from = starttime;
		time_t till = endtime;
		if (int_to_bit(ko, RENEWABLE))
			kkk->rtime = conf.max_renewable_life;
		kkk->nonce = 13243;
		kkk->ktype = 0;
	}
