project(spl
    VERSION 0.0.1
    DESCRIPTION "Simple Pixel Library"
    LANGUAGES C ASM)

add_library(${PROJECT_NAME} STATIC)
add_subdirectory(generic)
