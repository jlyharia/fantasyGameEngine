PROJECT(TEST)

# -------
MACRO(ADD_TEST_CASE TESTCASE_NAME)
    add_executable(${TESTCASE_NAME} ${TESTCASE_NAME}.cpp)
    target_link_libraries(${TESTCASE_NAME} myLib ${LIBRARIES} ${GTEST_BOTH_LIBRARIES})

ENDMACRO()
# -------
find_package(GTest REQUIRED)
message("-- TEST_SOURCE_DIR " ${TEST_SOURCE_DIR})
message("-- GTEST_INCLUDE_DIRS " ${GTEST_INCLUDE_DIRS})

include_directories(${TEST_SOURCE_DIR}
        ${GTEST_INCLUDE_DIRS}/include
        ${GTEST_INCLUDE_DIRS}
        )

add_test(NAME testName
        COMMAND -test)
#		WORKcING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test.cpp)