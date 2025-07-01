project(test_convert
    VERSION 0.0.1
    DESCRIPTION "test 'libspl' for convert"
    LANGUAGES C ASM)

list(APPEND test_src main.c)

add_executable(${PROJECT_NAME} ${test_src})
target_link_libraries(${PROJECT_NAME} spl)
