#include "client_info.h"
#include "cJson/cJSON.h"

void send_client_login_info(LOGIN_INFO *login_info,char *json) {
    cJSON *item;
    cJSON *root= cJSON_Parse(json);

    item=cJSON_GetObjectItem(root,"IP");
    login_info->IP = item->valuestring;

    item = cJSON_GetObjectItem(root,"ACTION");
    login_info->ACTION = item->valueint;

    item = cJSON_GetObjectItem(root,"account");
    login_info->account = item->valuestring;

    item = cJSON_GetObjectItem(root,"password");
    login_info->passwd = item->valuestring;

    item = cJSON_GetObjectItem(root,"time");
    login_info->t = item->valuestring;
}

void getAction(CHAT_INFO *info,char *json){
    cJSON *item;
    cJSON *root= cJSON_Parse(json);

    item = cJSON_GetObjectItem(root,"ACTION");
    info->ACTION = item->valueint;
}

void send_client_logout_info(LOGOUT_INFO *logout_info,char *json) {
    cJSON *item;
    cJSON *root= cJSON_Parse(json);

    item=cJSON_GetObjectItem(root,"IP");
    logout_info->IP = item->valuestring;

    item = cJSON_GetObjectItem(root,"ACTION");
    logout_info->ACTION = item->valueint;

    item = cJSON_GetObjectItem(root,"account");
    logout_info->account = item->valuestring;

    item = cJSON_GetObjectItem(root,"time");
    logout_info->t = item->valuestring;
}

void send_client_chat_info(CHAT_INFO *chat_info,char *json) {
    cJSON *item;
    cJSON *root= cJSON_Parse(json);

    item=cJSON_GetObjectItem(root,"IP");
    chat_info->IP = item->valuestring;

    item = cJSON_GetObjectItem(root,"ACTION");
    chat_info->ACTION = item->valueint;

    item = cJSON_GetObjectItem(root,"account");
    chat_info->account = item->valuestring;

    item = cJSON_GetObjectItem(root,"time");
    chat_info->t = item->valuestring;
}

void send_add_chat_info(ADD_INFO *chat_info,char *json) {
    cJSON *item;
    cJSON *root= cJSON_Parse(json);

    item = cJSON_GetObjectItem(root,"ACTION");
    chat_info->ACTION = item->valueint;

    item = cJSON_GetObjectItem(root,"account");
    chat_info->account = item->valuestring;
}


//反悔好友信息
char* re_friend_info(FRIEND *aFriend , int len){
    cJSON * cRoot = NULL;
    cJSON * cFriend = NULL;
    cJSON * cFriArray = NULL;

    if((cRoot = cJSON_CreateObject()) == NULL || (cFriend = cJSON_CreateObject()) == NULL || (cFriArray = cJSON_CreateArray()) == NULL)
    {
        return NULL;
    }
    //好友列表
    for (int i = 0; i < len; ++i) {
        cJSON_AddStringToObject(cFriend, "u_name", aFriend->u_name);
        cJSON_AddStringToObject(cFriend, "IP", aFriend->IP);
        cJSON_AddItemToObject(cFriArray, "FRIEND", cFriend);
        cFriend = cJSON_CreateObject();
        aFriend++;
    }

    //数组添加到最外层JsonObject
    cJSON_AddItemToObject(cRoot, "FRIEND", cFriArray);

    char * pJson = cJSON_Print(cRoot);
    if(NULL == pJson)
    {
        cJSON_Delete(cRoot);
        cJSON_Delete(cFriend);
        return NULL;
    }

    return pJson;
}
//反悔状态信息 7成功，0失败
char* re_status_info(RE_INFO *re_info){
    cJSON * cRoot = NULL;

    if((cRoot = cJSON_CreateObject()) == NULL)
    {
        return NULL;
    }

    //添加状态码 成功：7 失败：0
    cJSON_AddNumberToObject(cRoot, "STATUS",re_info->STATUS);
    //时间戳
    cJSON_AddStringToObject(cRoot, "TIME", re_info->t);

    char * pJson = cJSON_Print(cRoot);
    if(NULL == pJson)
    {
        cJSON_Delete(cRoot);
        return NULL;
    }

    return pJson;
}
