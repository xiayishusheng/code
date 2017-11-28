LOCAL_PATH := $(call my-dir)

#构建静态库
include $(CLEAR_VARS)
LOCAL_MODULE := demo
LOCAL_SRC_FILES := ../../../../linux/study/demo.c
LOCAL_LDFLAGS   += -llog
LOCAL_CFLAGS    += -fPIE
LOCAL_LDFLAGS   += -fPIE -pie
#include $(BUILD_STATIC_LIBRARY)
include $(BUILD_EXECUTABLE)

#构建共享库
include $(CLEAR_VARS)
LOCAL_MODULE := chengfa
LOCAL_SRC_FILES := ../../../../linux/study/chengfa.c
LOCAL_LDFLAGS   += -llog
LOCAL_CFLAGS    += -fPIE
LOCAL_LDFLAGS   += -fPIE -pie
#include $(BUILD_SHARED_LIBRARY)
include $(BUILD_EXECUTABLE)

