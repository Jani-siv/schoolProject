set(AIRTEST airTests)
set(GPSTEST gpsTests)
set(AGGTEST aggeratorTests)

SET(BASEPATH "${CMAKE_SOURCE_DIR}")
INCLUDE_DIRECTORIES("${BASEPATH}")

set(SOURCEFILESCOMMON
        ${CMAKE_SOURCE_DIR}/communication/Command.cpp
        ${CMAKE_SOURCE_DIR}/communication/CommandBase.cpp
        ${CMAKE_SOURCE_DIR}/communication/Uart.cpp
        ${CMAKE_SOURCE_DIR}/debug/Debug.cpp
        )

set(AIRSOURCE
        ${CMAKE_SOURCE_DIR}/sensors/unit_tests/AirQualityTests.cpp
        ${CMAKE_SOURCE_DIR}/communication/AirQualityInterface.cpp
        ${CMAKE_SOURCE_DIR}/sensors/AirQuality.cpp
        )
set(GPSSOURCE
        ${CMAKE_SOURCE_DIR}/sensors/unit_tests/GpsTests.cpp
        ${CMAKE_SOURCE_DIR}/sensors/Gps.cpp
        )

set(AGGSOURCE
        ${CMAKE_SOURCE_DIR}/sensors/unit_tests/AggregatorTests.cpp
        ${CMAKE_SOURCE_DIR}/sensors/Aggregator.cpp
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
#AIR TEST
add_executable(
        ${AIRTEST}
        ${SOURCEFILECOMMON}
        ${AIRSOURCE}
)

target_link_libraries(
        ${AIRTEST}
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(
        ${AIRTEST}
)
#GPS TEST
add_executable(
        ${GPSTEST}
        ${SOURCEFILECOMMON}
        ${GPSSOURCE}
)

target_link_libraries(
        ${GPSTEST}
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(
        ${GPSTEST}
)
#AGGERATOR TEST
add_executable(
        ${AGGTEST}
        ${SOURCEFILECOMMON}
        ${AGGSOURCE}
)

target_link_libraries(
        ${AGGTEST}
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(
        ${AGGTEST}
)