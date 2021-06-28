
# /*******************************************************************************
# ** Toolbox-qt-utility                                                         **
# ** MIT License                                                                **
# ** Copyright (c) [2018] [Florian Lance]                                       **
# **                                                                            **
# ** Permission is hereby granted, free of charge, to any person obtaining a    **
# ** copy of this software and associated documentation files (the "Software"), **
# ** to deal in the Software without restriction, including without limitation  **
# ** the rights to use, copy, modify, merge, publish, distribute, sublicense,   **
# ** and/or sell copies of the Software, and to permit persons to whom the      **
# ** Software is furnished to do so, subject to the following conditions:       **
# **                                                                            **
# ** The above copyright notice and this permission notice shall be included in **
# ** all copies or substantial portions of the Software.                        **
# **                                                                            **
# ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR **
# ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   **
# ** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    **
# ** THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER **
# ** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    **
# ** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        **
# ** DEALINGS IN THE SOFTWARE.                                                  **
# **                                                                            **
# ********************************************************************************/

####################################### TARGET
TARGET = qt-utility

####################################### PRI
# defines projects settings
include(../projects.pri)
# defines compiling options
include(../settings.pri)
# generate paths
include(../paths.pri)
# defines thirdparty includes and libs
include(../thirdparty.pri)

####################################### TEMPLATE
equals(QT_UTILITY_T, "lib"){
    TEMPLATE = lib
    CONFIG += staticlib
    CONFIG -= console
}
equals(QT_UTILITY_T, "app"){
    TEMPLATE = app
    CONFIG += console
}

OBJECTS_DIR = $$QT_UTILITY_OBJ
MOC_DIR     = $$QT_UTILITY_MOC
RCC_DIR     = $$QT_UTILITY_RCC
UI_DIR      = $$QT_UTILITY_UI
DESTDIR     = $$QT_UTILITY_DEST


####################################### CONFIG

CONFIG += qt
QT += core gui opengl widgets printsupport network

####################################### INCLUDES

INCLUDEPATH += \    
    # local
    widgets \
    # base
    $$BASE_INCLUDES \
    # opengl-utility
    $$OPENGL_UTILITY_INCLUDES \
    # thirdparty
    $$SIGNALS_INCLUDES \
    $$SFML_INCLUDES \
    $$GLEW_INCLUDES \
    $$GLM_INCLUDES \



####################################### LIBRAIRIES

LIBS +=  \
    # base
    $$BASE_LIB\
    # opengl-utility
    $$OPENGL_UTILITY_LIB \
    # third party
    $$WINDOWS_LIBS \
    $$SFML_LIBS \
    $$GLEW_LIBS \
    $$GLM_LIBS\

####################################### PROJECT FILES

SOURCES += \
    qt_logger.cpp \
    qt_str.cpp \
    qt_ui.cpp \
    qt_utility_main.cpp \
    widgets/grabber_parameters_widget.cpp \
    widgets/image_viewer.cpp \
    widgets/list_widget.cpp \
    widgets/rich_text_edit.cpp \
    widgets/sfmlqt_gl_widget.cpp \

HEADERS += \
    qt_io.hpp \
    qt_logger.hpp \
    qt_process.hpp \
    qt_str.hpp \
    qt_types.hpp \
    qt_ui.hpp \
    qt_convertors.hpp \
    widgets/custom_combobox_w.hpp \
    widgets/grabber_parameters_widget.hpp \
    widgets/list_widget.hpp \
    widgets/image_viewer.hpp \
    widgets/rich_text_edit.hpp \
    widgets/sfmlqt_gl_widget.hpp \
    wrapper/qt_gl_wrapper.hpp \

RESOURCES += \
    $$TOOLBOX_CPP_RESOURCES_DIR"/resources.qrc" \

FORMS += \
    ui/grabber_parameters.ui \



#DISTFILES += \
