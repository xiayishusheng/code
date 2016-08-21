LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := libutils libcutils libdl
LOCAL_C_INCLUDES:=
LOCAL_CFLAGS:= -g -c -W -Wall -O2 -D_POSIX_SOURCE
LOCAL_SRC_FILES := netlink_tester.c
LOCAL_MODULE := netlink_tester
LOCAL_MODULE_TAGS:= optional eng
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := libutils libcutils libdl
LOCAL_C_INCLUDES:=
LOCAL_CFLAGS:= -g -c -W -Wall -O2 -D_POSIX_SOURCE
LOCAL_SRC_FILES := genl_user.c
LOCAL_MODULE := genl_user
LOCAL_MODULE_TAGS:= optional eng
include $(BUILD_EXECUTABLE)