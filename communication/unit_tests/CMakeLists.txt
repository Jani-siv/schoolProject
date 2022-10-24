set(TESTNAME CommandTests)
SET(BASEPATH "${CMAKE_SOURCE_DIR}")
INCLUDE_DIRECTORIES("${BASEPATH}")
set(SOURCEFILES
        ${CMAKE_SOURCE_DIR}/communication/unit_tests/CommandTests.cpp
        ${CMAKE_SOURCE_DIR}/communication/Command.cpp
        ${CMAKE_SOURCE_DIR}/communication/CommandBase.cpp
        ${CMAKE_SOURCE_DIR}/communication/Uart.cpp
        ${CMAKE_SOURCE_DIR}/communication/AirQualityInterface.cpp
        )

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(
        ${TESTNAME}
        ${SOURCEFILES}
)

target_link_libraries(${TESTNAME} PRIVATE
        GTest::GTest
)

add_test(CommandGTests ${TESTNAME})
