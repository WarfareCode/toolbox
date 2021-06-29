
# /*******************************************************************************
# ** tool-test                                                                  **
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
TARGET = tool-test

####################################### PRI
# defines projects settings
include(../projects.pri)
# defines compiling options
include(../settings.pri)
# generate paths
include(../paths.pri)
# defines thirdparty includes and libs
include(../thirdparty.pri)

####################################### TARGET
equals(CFG, "debug"){
    TARGET = tool-testd
}
equals(CFG, "release"){
    TARGET = tool-test
}

####################################### TEMPLATE
equals(TOOl_TEST_TARGET, "app"){
    TEMPLATE = app
    CONFIG += console
}

####################################### BUILD FILES
OBJECTS_DIR = $$TOOL_TEST_OBJ
DESTDIR     = $$TOOL_TEST_DEST

####################################### CONFIG
CONFIG -= qt

####################################### INCLUDES
INCLUDEPATH += \
    # base
    $$BASE_INCLUDES\
    # opengl-utility
    $$OPENGL_UTILITY_INCLUDES\
    # qt-utility
#    $$QT_UTILITY_INCLUDES\
    # thirdparty
    $$GLEW_INCLUDES\
    $$GLFW_INCLUDES\
    $$SFML_INCLUDES\
    $$ASSIMP_INCLUDES\
    $$GLM_INCLUDES\
    $$CATCH_INCLUDES\

####################################### LIBRAIRIES

LIBS +=\
    # base
    $$BASE_LIB\
    # opengl-utility
    $$OPENGL_UTILITY_LIB \
    # qt-utility
#    $$QT_UTILITY_LIB \
    # thirdparty
    $$GLEW_LIBS \
    $$GLFW_LIBS \
    $$SFML_LIBS \
    $$ASSIMP_LIBS\
    $$GLM_LIBS\

####################################### PROJECT FILES

SOURCES += \
    main.cpp \       
    geometry_tests.cpp \

HEADERS += \
   geometry_tests.hpp \

DISTFILES += \
    CREDITS.md \
    LICENSE \




