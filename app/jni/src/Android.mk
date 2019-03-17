LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include $(LOCAL_PATH)/../SDL2_image/ $(LOCAL_PATH)/../SDL2_ttf/


# Add your application source files here...
LOCAL_SRC_FILES := main.cpp game.cpp scorepickup.cpp timer.cpp video.cpp sprite.cpp button.cpp animatedsprite.cpp player.cpp pickup.cpp

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_ttf

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
