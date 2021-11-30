#include <gtest/gtest.h>

extern "C" {
#include "utils/argument_parser.h"
}

//TEST(utils, parse_arguments_valid_result_for_simple_command) {
//    // Arrange
//    char **args = new char*[4];
//
//    args[0] = (char*)"path";
//    args[1] = (char*)"-n";
//    args[2] = (char*)"2";
//    args[3] = (char*)"pwd";
//
//    // Act
//    struct ParseResult result = get_arguments(4, args);
//
//    // Assert
//    ASSERT_FALSE(result.parse_failed);
//    ASSERT_EQ(result.interval, 2000);
//    ASSERT_EQ(result.args_length, 1);
//
//    free_parse_result(&result);
//}
//
//TEST(utils, parse_arguments_valid_result_for_complex_command) {
//    // Arrange
//    char **args = new char*[5];
//
//    args[0] = (char*)"path";
//    args[1] = (char*)"-n";
//    args[2] = (char*)"4";
//    args[3] = (char*)"echo";
//    args[4] = (char*)"test";
//
//    // Act
//    struct ParseResult result = get_arguments(5, args);
//
//    // Assert
//    ASSERT_FALSE(result.parse_failed);
//    ASSERT_EQ(result.interval, 4000);
//    ASSERT_EQ(result.args_length, 2);
//
//    free_parse_result(&result);
//}
//
//TEST(utils, parse_arguments_not_valid_result_missing_argument) {
//    // Arrange
//    char **args = new char*[3];
//
//    args[0] = (char*)"path";
//    args[1] = (char*)"-n";
//    args[2] = (char*)"2";
//
//    // Act
//    struct ParseResult result = get_arguments(3, args);
//
//    // Assert
//    ASSERT_TRUE(result.parse_failed);
//
//    free_parse_result(&result);
//}
