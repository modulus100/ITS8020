include(FetchContent)
FetchContent_Declare(gtest
  QUIET
  URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz
)
# configure build of googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)

add_executable(unit_tests
        utils/example_add_tests.cpp
        utils/example_subtract_tests.cpp
        utils/watch_utils_get_usage_tests.cpp
        utils/watch_utils_contains_argument_tests.cpp
        utils/string_utils_join_tests.cpp
        utils/string_utils_string_to_milliseconds_tests.cpp
        utils/argument_parser_parse_arguments_tests.cpp
        utils/string_utils_length_tests.cpp
        )

target_link_libraries(unit_tests
  PRIVATE
        utils
    gtest_main
        )

# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(unit_tests
  PROPERTIES
    LABELS "unit"
  DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
    240
  )
