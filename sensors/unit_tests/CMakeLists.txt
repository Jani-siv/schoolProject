set(TESTNAME sensorTests)
SET(BASEPATH "${CMAKE_SOURCE_DIR}")
INCLUDE_DIRECTORIES("${BASEPATH}")
set(SOURCEFILES
        ${CMAKE_SOURCE_DIR}/sensors/unit_tests/AggregatorTests.cpp
        ${CMAKE_SOURCE_DIR}/sensors/unit_tests/AirQualityTests.cpp
        ${CMAKE_SOURCE_DIR}/sensors/unit_tests/GpsTests.cpp
        ${CMAKE_SOURCE_DIR}/sensors/Aggregator.cpp
        ${CMAKE_SOURCE_DIR}/sensors/AirQuality.cpp
        ${CMAKE_SOURCE_DIR}/sensors/Gps.cpp
        ${CMAKE_SOURCE_DIR}/communication/Command.cpp
        ${CMAKE_SOURCE_DIR}/communication/CommandBase.cpp
        ${CMAKE_SOURCE_DIR}/communication/Uart.cpp
        ${CMAKE_SOURCE_DIR}/debug/Debug.cpp
        )

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(
        ${TESTNAME}
        ${SOURCEFILES}
)

target_link_libraries(
        ${TESTNAME}
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(
        ${TESTNAME}
)
