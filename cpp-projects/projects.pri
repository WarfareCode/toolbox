

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

# sub dir
TOOLBOX_CPP_PROJECTS_DIR    = $$TOOLBOX_REPOSITORY_DIR"/cpp-projects"
TOOLBOX_CPP_BIN_DIR         = $$TOOLBOX_CPP_PROJECTS_DIR"/_build/bin"
TOOLBOX_CPP_TEMP_DIR        = $$TOOLBOX_CPP_PROJECTS_DIR"/_build/temp"
TOOLBOX_CPP_THIRDPARTY_DIR  = $$TOOLBOX_CPP_PROJECTS_DIR"/_thirdparty"
TOOLBOX_CPP_RESOURCES_DIR   = $$TOOLBOX_CPP_PROJECTS_DIR"/_resources"

# compilation directories
TOOLBOX_CPP_OBJ_DIR         = $$TOOLBOX_CPP_TEMP_DIR"/obj"
TOOLBOX_CPP_MOC_DIR         = $$TOOLBOX_CPP_TEMP_DIR"/moc"
TOOLBOX_CPP_RCC_DIR         = $$TOOLBOX_CPP_TEMP_DIR"/rcc"
TOOLBOX_CPP_UI_DIR          = $$TOOLBOX_CPP_TEMP_DIR"/ui"

# define functions
defineTest(generate_variables) {

    # include
    eval($${1}_INCLUDES = $$TOOLBOX_CPP_PROJECTS_DIR/$${2})
    eval(export($${1}_INCLUDES))

    # objects files
    eval($${1}_OBJ = $${TOOLBOX_CPP_OBJ_DIR}/$${CFG}/$${2})
    eval(export($${1}_OBJ))

    # moc
    eval($${1}_MOC = $${TOOLBOX_CPP_MOC_DIR}/$${CFG}/$${2})
    eval(export($${1}_MOC))

    # rcc
    eval($${1}_RCC = $${TOOLBOX_CPP_RCC_DIR}/$${CFG}/$${2})
    eval(export($${1}_RCC))

    # ui generated files
    eval($${1}_UI = $${TOOLBOX_CPP_UI_DIR}/$${CFG}/$${2})
    eval(export($${1}_UI))

    # destination
    eval($${1}_DEST = $${TOOLBOX_CPP_BIN_DIR}/$${2})
    eval(export($${1}_DEST))

    # lib
    equals(CFG, "debug"){
        eval($${1}_LIB = "-L"$${TOOLBOX_CPP_BIN_DIR}/$${2} "-l"$${3})
    }
    equals(CFG, "release"){
        eval($${1}_LIB = "-L"$${TOOLBOX_CPP_BIN_DIR}/$${2} "-l"$${2})
    }
    eval(export($${1}_LIB))
}

# generate projects directory variables
for(project_dir, TOOLBOX_CPP_PROJECTS):{
    generate_variables($$section(project_dir, :, 0, 0), $$section(project_dir, :, 1, 1), $$section(project_dir, :, 2, 2))
}
