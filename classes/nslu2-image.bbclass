nslu2_pack_image () {
	install -d ${DEPLOY_DIR_IMAGE}/slug
	install -m 0644 ${STAGING_LIBDIR}/nslu2-binaries/RedBoot \
			${STAGING_LIBDIR}/nslu2-binaries/Trailer \
			${STAGING_LIBDIR}/nslu2-binaries/SysConf \
			${DEPLOY_DIR_IMAGE}/slug/
	install -m 0644 ${DEPLOY_DIR_IMAGE}/zImage-nslu2${SITEINFO_ENDIANESS} \
		${DEPLOY_DIR_IMAGE}/slug/vmlinuz
	install -m 0644 ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.rootfs.jffs2 \
		${DEPLOY_DIR_IMAGE}/slug/flashdisk.jffs2
	install -m 0644 ${STAGING_FIRMWARE_DIR}/NPE-B ${DEPLOY_DIR_IMAGE}/slug/
	cd ${DEPLOY_DIR_IMAGE}/slug
	slugimage -p -b RedBoot -s SysConf -k vmlinuz \
		-r Ramdisk:1,Flashdisk:flashdisk.jffs2 -m NPE-B -t Trailer \
		-o ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}-nslu2.bin
	rm -rf ${DEPLOY_DIR_IMAGE}/slug
}

EXTRA_IMAGEDEPENDS += 'slugimage-native nslu2-linksys-firmware ixp4xx-npe upslug2-native'
IMAGE_POSTPROCESS_COMMAND += "nslu2_pack_image; "