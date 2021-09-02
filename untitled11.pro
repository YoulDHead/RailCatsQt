#-------------------------------------------------
#
# Project created by QtCreator 2012-10-29T15:37:59
#
#-------------------------------------------------

QT       += core gui

TARGET = untitled11
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logwindow.cpp \
    includes/railcats_settings.cpp \
    includes/railcats_service.cpp \
    includes/railcats_queue.cpp \
    includes/railcats_logic_objects.cpp \
    includes/railcats_connector_p50.cpp \
    includes/railcats_protocols_p50.cpp \
    decoderprog.cpp \
    loco_mangement.cpp \
    loco_new.cpp \
    tinyxml/tinyxml.cpp \
    tinyxml/tinystr.cpp \
    tinyxml/tinyxmlparser.cpp \
    tinyxml/tinyxmlerror.cpp

HEADERS  += mainwindow.h \
    logwindow.h \
    includes/railcats_settings.h \
    includes/railcats_service.h \
    includes/railcats_queue.h \
    includes/railcats_logic_objects.h \
    includes/railcats_connector_p50.h \
    includes/railcats_protocols_p50.h \
    includes/globalsettings.h \
    decoderprog.h \
    loco_mangement.h \
    loco_new.h \
    includes/build_settings.h \
    tinyxml/tinyxml.h \
    tinyxml/tinystr.h

FORMS    += mainwindow.ui \
    logwindow.ui \
    decoderprog.ui \
    loco_mangement.ui \
    loco_new.ui

unix:!macx:!symbian: LIBS += -L$$PWD/../../../../usr/lib64/ -ltinyxml

LIBS+= -ltinyxml -LC:\temp\railcats-code\RailCatsQt\tinyxml\Debugtinyxml

INCLUDEPATH += $$PWD/../../../../usr/lib64

DEPENDPATH += $$PWD/../../../../usr/lib64
