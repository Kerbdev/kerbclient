#ifndef GET_CONF_H_
#define GET_CONG_H_
typedef struct _config
{
    int max_life;
    int max_renewable_life;
    int timeout;
    int retries;
    int ticket_lifetime;
    char *realm;
    char *server_realm;
    char *server_name;

} configuration;
int get_config_param(configuration *config);



#endif
