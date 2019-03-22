LOCAL_PATH := $(call my-dir)

#构建共享库
include $(CLEAR_VARS)
LOCAL_MODULE := str
LOCAL_SRC_FILES := JniTest.c
#LOCAL_LDFLAGS := -Wl,-hash-style=gnu
LOCAL_LDFLAGS := -Wl,-hash-style=sysv
LOCAL_LDFLAGS += -fPIE -shared
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := reg
LOCAL_SRC_FILES := JniRegister.c
LOCAL_LDFLAGS := -Wl,-hash-style=sysv
LOCAL_LDFLAGS += -fPIE -shared
include $(BUILD_SHARED_LIBRARY)

