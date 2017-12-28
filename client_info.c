#include "client_info.h"

#include "cJson/cJSON.h"
#include <stdio.h>

typedef struct {
    char *IP;
    int TPYE;
    char *account;
    char *passwd;
    char *t;
}LOGIN_INFO;

void get_client_info(char *json) {
    cJSON *item;
    LOGIN_INFO login_info;
    cJSON *root= cJSON_Parse(json);

    item=cJSON_GetObjectItem(root,"IP");
    login_info.IP = item->valuestring;

    item = cJSON_GetObjectItem(root,"TYPE");
    login_info.TPYE = item->valueint;

    item = cJSON_GetObjectItem(root,"account");
    login_info.account = item->valuestring;

    item = cJSON_GetObjectItem(root,"passwd");
    login_info.passwd = item->valuestring;

    item = cJSON_GetObjectItem(root,"time");
    login_info.t = item->valuestring;

    printf("%s\n",login_info.IP);
    printf("%s\n",login_info.account);
    printf("%s\n",login_info.passwd);
    printf("%s\n",login_info.t);


    cJSON_Delete(root);
}
