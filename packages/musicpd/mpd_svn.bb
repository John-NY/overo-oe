DESCRIPTION = "Music Player Daemon (mpd)"
HOMEPAGE = "http://www.musicpd.org"
LICENSE = "GPLv2"
SECTION = "console/multimedia"
DEPENDS = "libvorbis libogg libid3tag libao zlib libmikmod libmad flac audiofile virtual/libiconv faad2"
SRCDATE = "20070120"
PV = "0.12.1+svn${SRCDATE}"
PR = "r0"

SRC_URI = "svn://svn.musicpd.org/mpd;module=trunk;proto=https"
#           file://save-volume-state.patch;patch=1"
S = "${WORKDIR}/trunk"

inherit autotools

# Setting --enable-mpd-{mad,id3tag} causes local caches of the libraries to
# be built, instead we use the OE built versions which should be installed
# in staging - remove the --with and replace with --enable to use the local
# versions.

EXTRA_OECONF = "--enable-ogg \
		--with-id3tag-libraries=${STAGING_LIBDIR} \
		--with-id3tag-includes=${STAGING_INCDIR} \
		--with-mad-libraries=${STAGING_LIBDIR} \
		--with-mad-includes=${STAGING_INCDIR} \
        --with-faad-libraries=${STAGING_LIBDIR} \
		--with-faad-includes=${STAGING_INCDIR} \
        --disable-jack \
        --disable-pulse \
        --enable-mod \
        --disable-oggflac"

do_compile_prepend() {
    find -name Makefile | xargs sed -i 's~-I/usr/include~-I${STAGING_INCDIR}~g'
}