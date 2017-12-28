cmake_minimum_required(VERSION 3.9)
project(IMprotocol C)

set(CMAKE_C_STANDARD 99)

add_library(IMprotocol client_info.c client_info.h cJson/cJSON_Utils.c cJson/cJSON_Utils.h cJson/cJSON.c cJson/cJSON.h)