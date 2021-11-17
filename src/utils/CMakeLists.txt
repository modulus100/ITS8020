add_library(utils)

target_sources(utils
        PRIVATE
        example.c
        watch_options.c
        PUBLIC
        watch_options.h
        example.h
        )

target_include_directories(utils
        PUBLIC
        ..
        )

#add_executable(wa watch.c)

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if (CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(utils
            PUBLIC
            "--coverage"
            )
    target_link_options(utils
            INTERFACE
            "--coverage"
            )
endif ()
