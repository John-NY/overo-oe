# Upgraded
# use newer version then preferred by default
PREFERRED_VERSION_dbus ?= "1.3.0"
PREFERRED_VERSION_autoconf = "2.63"
PREFERRED_VERSION_autoconf-native = "2.63"
PREFERRED_VERSION_libmikmod ?= "3.2.0-beta2"
PREFERRED_VERSION_mtd-utils-native ?= "1.2.0+git"
PREFERRED_VERSION_strace ?= "4.5.15"

# we need new headers for libc, now OLDEST_KERNEL_linux-gnueabi = "2.6.24"
PREFERRED_VERSION_linux-libc-headers = "2.6.29"

# upgrades used in Angstrom
PREFERRED_VERSION_gtk+          = "2.18.3"
PREFERRED_VERSION_hal           = "0.5.13"
PREFERRED_VERSION_libtool       = "2.2.6a"
PREFERRED_VERSION_libtool-native = "2.2.6a"
PREFERRED_VERSION_libtool-cross = "2.2.6a"
PREFERRED_VERSION_libtool-sdk   = "2.2.6a"
PREFERRED_VERSION_udev          = "141"
PREFERRED_VERSION_usbutils = "0.82"
PREFERRED_VERSION_wpa-supplicant = "0.6.9"
UDEV_GE_141 = "1"

# Downgraded
# python-pygtk_2.16.0 is accessing non-existent /usr/share/pygobject/2.0/codegen/codegen.py
PREFERRED_VERSION_python-pygtk ?= "2.10.4"
PREFERRED_VERSION_gpe-gallery ?= "0.97"
PREFERRED_VERSION_boost ?= "1.33.1"
PREFERRED_VERSION_man-pages ?= "2.41"
PREFERRED_VERSION_xchat ?= "2.8.4"
PREFERRED_VERSION_x11vnc ?= "0.9.3"