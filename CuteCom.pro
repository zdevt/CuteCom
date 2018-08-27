#-------------------------------------------------
#
# This is the qmake build file mainly provided
# to ease development with Qt Creator.
# Since the version number is maintained within
# the CMakeLists.txt, cmake should have been
# called at least once.
# Otherwise the necessary version.h file will
# not have been generated.
# If for whatever reason cmake is not an option
# create the version.h from version.h.in manually
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4){
  QT += widgets network
  CONFIG += c++11
}

TARGET = CuteCom
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settings.cpp \
    devicecombo.cpp \
    serialdevicelistmodel.cpp \
    statusbar.cpp \
    sessionmanager.cpp \
    datadisplay.cpp \
    datahighlighter.cpp \
    searchpanel.cpp \
    timeview.cpp \
    ctrlcharacterspopup.cpp \
    plugin.cpp \
    pluginmanager.cpp \
    macroplugin.cpp \
    macrosettings.cpp \
    netproxyplugin.cpp \
    netproxysettings.cpp \
    counterplugin.cpp \
    controlpanel.cpp

HEADERS  += mainwindow.h \
    controlpanel.h \
    settings.h \
    devicecombo.h \
    serialdevicelistmodel.h \
    statusbar.h \
    sessionmanager.h \
    datadisplay.h \
    datahighlighter.h \
    searchpanel.h \
    timeview.h \
    ctrlcharacterspopup.h \
    plugin.h \
    pluginmanager.h \
    macroplugin.h \
    macrosettings.h \
    netproxyplugin.h \
    netproxysettings.h \
    counterplugin.h \
    counterplugin.h


FORMS    += mainwindow.ui \
    controlpanel.ui \
    statusbar.ui \
    sessionmanager.ui \
    searchpanel.ui \
    macroplugin.ui \
    netproxyplugin.ui \
    macrosettings.ui \
    netproxysettings.ui \
    counterplugin.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    qt.astylerc

RC_ICONS = images/cutecom.ico
