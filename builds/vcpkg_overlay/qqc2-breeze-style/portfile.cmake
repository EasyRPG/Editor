set(VCPKG_POLICY_EMPTY_INCLUDE_FOLDER enabled)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO KDE/qqc2-breeze-style
    REF "v${VERSION}"
    SHA512 3109fa7c0b85ba1c9d0fc4440f4afeb23967de7c0359474740e75f925ccfee72c7e832a14301cc478a122699215f992f4299b3236a67b0eb06c9d9edab937a81
    HEAD_REF master
	PATCHES
		no-plasma-integration.patch
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS
        -DCMAKE_PREFIX_PATH="$ENV{Qt6_Path}"
)

vcpkg_cmake_install()

vcpkg_cmake_config_fixup(PACKAGE_NAME QQC2BreezeStyle CONFIG_PATH "lib/cmake/QQC2BreezeStyle")

# Remove debug files
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/share")

if(VCPKG_LIBRARY_LINKAGE STREQUAL "static")
  file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/bin")
endif()

# Handle copyright
vcpkg_install_copyright(FILE_LIST
    "${SOURCE_PATH}/LICENSES/CC0-1.0.txt"
    "${SOURCE_PATH}/LICENSES/GPL-2.0-or-later.txt"
    "${SOURCE_PATH}/LICENSES/LGPL-2.0-or-later.txt"
    "${SOURCE_PATH}/LICENSES/LGPL-2.1-only.txt"
    "${SOURCE_PATH}/LICENSES/LGPL-3.0-only.txt"
    "${SOURCE_PATH}/LICENSES/LicenseRef-KDE-Accepted-LGPL.txt"
    "${SOURCE_PATH}/LICENSES/LicenseRef-KFQF-Accepted-GPL.txt"
)
