DESCRIPTION = "Meta package for ensuring the build directory contains all appropriate packages and env for using qt4e app develop"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/LICENSE;md5=3f40d7994397109285ec7b81fdeb3b58 \
                    file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

DEPENDS = "qt4-embedded"
PR = "r3"

require recipes-core/meta/meta-ide-support.bb

toolchain_create_tree_env_script_append() {
    echo 'export OE_QMAKE_CFLAGS="$CFLAGS"' >> $script
    echo 'export OE_QMAKE_CXXFLAGS="$CXXFLAGS"' >> $script
    echo 'export OE_QMAKE_LDFLAGS="$LDFLAGS"' >> $script
    echo 'export OE_QMAKE_CC=$CC' >> $script
    echo 'export OE_QMAKE_CXX=$CXX' >> $script
    echo 'export OE_QMAKE_LINK=$CXX' >> $script
    echo 'export OE_QMAKE_AR=$AR' >> $script
    echo 'export OE_QMAKE_LIBDIR_QT=${STAGING_LIBDIR}' >> $script
    echo 'export OE_QMAKE_INCDIR_QT=${STAGING_INCDIR}/${QT_DIR_NAME}' >> $script
    echo 'export OE_QMAKE_MOC=${STAGING_BINDIR_NATIVE}/moc4' >> $script
    echo 'export OE_QMAKE_UIC=${STAGING_BINDIR_NATIVE}/uic4' >> $script
    echo 'export OE_QMAKE_UIC3=${STAGING_BINDIR_NATIVE}/uic34' >> $script
    echo 'export OE_QMAKE_RCC=${STAGING_BINDIR_NATIVE}/rcc4' >> $script
    echo 'export OE_QMAKE_QDBUSCPP2XML=$${STAGING_BINDIR_NATIVE}/qdbuscpp2xml4' >> $script
    echo 'export OE_QMAKE_QDBUSXML2CPP=${STAGING_BINDIR_NATIVE}/qdbusxml2cpp4' >> $script
    echo 'export OE_QMAKE_QT_CONFIG=${STAGING_DATADIR}/${QT_DIR_NAME}/mkspecs/qconfig.pri' >> $script
    echo 'export QMAKESPEC=${STAGING_DATADIR}/${QT_DIR_NAME}/mkspecs/${TARGET_OS}-oe-g++' >> $script
}
