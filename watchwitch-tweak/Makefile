TARGET := iphone:clang:latest:7.0
#THEOS_PACKAGE_SCHEME=rootless
#INSTALL_TARGET_PROCESSES = SpringBoard


include $(THEOS)/makefiles/common.mk

TWEAK_NAME = WatchWitch

$(TWEAK_NAME)_FRAMEWORKS = Network

WatchWitch_FILES = Tweak.x
WatchWitch_CFLAGS = -fobjc-arc
WatchWitch_EXTRA_FRAMEWORKS += Cephei

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 terminusd"
	install.exec "killall -9 identityservicesd"
