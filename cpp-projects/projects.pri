

# lib
## base
#BASE_TARGET          = "app" # debug
BASE_TARGET          = "lib"
## opengl-utility
#OPENGL_UTILITY_TARGET = "app" # debug
OPENGL_UTILITY_TARGET = "lib"
## 3d-engine
#3D_ENGINE_TARGET     = "app" # debug
3D_ENGINE_TARGET     = "lib"
## nodes
#NODES_TARGET         = "app" # debug
NODES_TARGET         = "lib"
## qt-utility
#QT_UTILITY_TARGET    = "app" # debug
QT_UTILITY_TARGET    = "lib"

# app
## tool-test
TOOl_TEST_TARGET     = "app"
## demos
DEMOS_TARGET         = "app"

# projects list
TOOLBOX_CPP_PROJECTS +=\
    BASE:base:based \
    OPENGL_UTILITY:opengl-utility:opengl-utilityd \
    3D_ENGINE:3d-engine:3d-engined \
    DEMOS:demos:demosd \
    QT_UTILITY:qt-utility:qt-utilityd \
    NODES:nodes:nodesd \
    TOOL_TEST:tool-test:tool-testd \
