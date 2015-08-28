LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := JNIDemo
LOCAL_SRC_FILES := JNIDemo.cpp
LOCAL_LDLIBS += -lm -llog

include $(BUILD_SHARED_LIBRARY)
