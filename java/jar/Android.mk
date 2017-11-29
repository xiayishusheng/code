LOCAL_PATH := $(call my-dir)

#构建共享库
include $(CLEAR_VARS)
LOCAL_MODULE := str
LOCAL_SRC_FILES := JniTest.c
include $(BUILD_SHARED_LIBRARY)

