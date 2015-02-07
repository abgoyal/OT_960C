LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_WHOLE_STATIC_LIBRARIES := \
	libomx_mp3_component_lib \
 	libpvmp3

LOCAL_MODULE := libomx_mp3dec_sharedlibrary

ifneq ($(BUILD_PV_AUDIO_DEC_ONLY),1)
-include $(PV_TOP)/Android_platform_extras.mk
endif

# To include lpthread to LOCAL_LDLIBS and Simulator related libs
-include $(PV_TOP)/Android_system_extras.mk

LOCAL_SHARED_LIBRARIES +=   libomx_sharedlibrary libopencore_common

include $(BUILD_SHARED_LIBRARY)
include   $(PV_TOP)/codecs_v2/omx/omx_mp3/Android.mk
include   $(PV_TOP)/codecs_v2/audio/mp3/dec/Android.mk

