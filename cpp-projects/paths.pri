

# repo
TOOLBOX_REPOSITORY_DIR      = $$PWD"/.."
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

