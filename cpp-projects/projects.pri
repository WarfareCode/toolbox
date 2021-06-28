

# lib
## base
#BASE_T             = "app" # debug
BASE_T              = "lib"
## opengl-utility
#OPENGL_UTILITY_T    = "app" # debug
OPENGL_UTILITY_T    = "lib"
## 3d-engine
#3D_ENGINE_T         = "app" # debug
3D_ENGINE_T         = "lib"
## nodes
#NODES_T             = "app" # debug
NODES_T             = "lib"
## qt-utility
#QT_UTILITY_T        = "app" # debug
QT_UTILITY_T        = "lib"

# app
## tool-test
TOOl_TEST_T         = "app"
## demos
DEMOS_T             = "app"

# projects list
TOOLBOX_CPP_PROJECTS +=\
    BASE:base \
    OPENGL_UTILITY:opengl-utility \
    3D_ENGINE:3d-engine \
    DEMOS:demos \
    QT_UTILITY:qt-utility \
    NODES:nodes \
    TOOL_TEST:tool-test \
