vcpkg_check_linkage(ONLY_DYNAMIC_LIBRARY)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO KDE/kirigami
    REF "v${VERSION}"
    SHA512 89bd4131bb92804c45f1db095df27e79121aebd5054efea60605f590b64f9e6b718037f800d5133ac78f2dfb6fbd22e694e5fa266f61ef57b375154b5b098cda
    HEAD_REF master
)

vcpkg_replace_string("${SOURCE_PATH}/CMakeLists.txt" "configure_file(qmllint.ini.in" "#configure_file(qmllint.ini.in")

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS
        -DBUILD_EXAMPLES=OFF
        -DCMAKE_PREFIX_PATH="$ENV{Qt6_Path}"
)

vcpkg_cmake_install()

vcpkg_cmake_config_fixup(PACKAGE_NAME KF6Kirigami CONFIG_PATH lib/cmake/KF6Kirigami DO_NOT_DELETE_PARENT_CONFIG_PATH)
vcpkg_cmake_config_fixup(PACKAGE_NAME KF6Kirigami2 CONFIG_PATH lib/cmake/KF6Kirigami2 DO_NOT_DELETE_PARENT_CONFIG_PATH)
vcpkg_cmake_config_fixup(PACKAGE_NAME KF6KirigamiPlatform CONFIG_PATH lib/cmake/KF6KirigamiPlatform)

# Remove debug files
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/share")

if(VCPKG_LIBRARY_LINKAGE STREQUAL "static")
  file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/bin")
endif()

# Handle copyright
vcpkg_install_copyright(FILE_LIST
    "${SOURCE_PATH}/LICENSES/BSD-2-Clause.txt"
    "${SOURCE_PATH}/LICENSES/BSD-3-Clause.txt"
    "${SOURCE_PATH}/LICENSES/CC0-1.0.txt"
    "${SOURCE_PATH}/LICENSES/FSFAP.txt"
    "${SOURCE_PATH}/LICENSES/GPL-2.0-or-later.txt"
    "${SOURCE_PATH}/LICENSES/LGPL-2.0-or-later.txt"
    "${SOURCE_PATH}/LICENSES/LGPL-2.1-only.txt"
    "${SOURCE_PATH}/LICENSES/LGPL-3.0-only.txt"
    "${SOURCE_PATH}/LICENSES/LicenseRef-KDE-Accepted-LGPL.txt"
    "${SOURCE_PATH}/LICENSES/MIT.txt"
)
