set(KDEWebEngine_LIB_SRCS
    kwebenginepage.cpp
    kwebengineview.cpp
)

add_library(KF5WebEngine ${KDEWebEngine_LIB_SRCS})
generate_export_header(KF5WebEngine BASE_NAME KDEWebEngine)
add_library(KF5::WebEngine ALIAS KF5WebEngine)

target_include_directories(KF5WebEngine INTERFACE "$<INSTALL_INTERFACE:${KDE_INSTALL_INCLUDEDIR_KF5}/KDEWebEngine>")

target_link_libraries(KF5WebEngine PUBLIC Qt5::WebEngineWidgets
                                PRIVATE KF5::CoreAddons KF5::Wallet KF5::KIOWidgets KF5::Parts)

set_target_properties(KF5WebEngine PROPERTIES VERSION   ${KDEWEBENGINE_VERSION_STRING}
                                           SOVERSION ${KDEWEBENGINE_SOVERSION}
                                           EXPORT_NAME WebEngine
)

ecm_generate_headers(KDEWebEngine_HEADERS
  HEADER_NAMES
  KWebEnginePage
  KWebEngineView

  REQUIRED_HEADERS KDEWebEngine_HEADERS
)

install(TARGETS KF5WebEngine EXPORT KF5WebEngineTargets ${KF5_INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/kdewebengine_export.h
  ${KDEWebEngine_HEADERS}
  DESTINATION ${KDE_INSTALL_INCLUDEDIR_KF5}/KDEWebEngine COMPONENT Devel
)


include(ECMGeneratePriFile)
ecm_generate_pri_file(BASE_NAME KDEWebEngine LIB_NAME KF5WebEngine DEPS "webenginewidgets" FILENAME_VAR PRI_FILENAME INCLUDE_INSTALL_DIR ${KDE_INSTALL_INCLUDEDIR_KF5}/KDEWebEngine)
install(FILES ${PRI_FILENAME} DESTINATION ${ECM_MKSPECS_INSTALL_DIR})
