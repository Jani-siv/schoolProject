cmake_minimum_required(VERSION 3.24)
project(schoolProject)

set(BASEPATH "${CMAKE_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 17)

set(SOURCEFILES
        ${CMAKE_SOURCE_DIR}/main.cpp
        ${CMAKE_SOURCE_DIR}/DataAnalysis.cpp
        ${CMAKE_SOURCE_DIR}/communication/Command.cpp
        ${CMAKE_SOURCE_DIR}/communication/CommandBase.cpp
        ${CMAKE_SOURCE_DIR}/communication/Uart.cpp
        ${CMAKE_SOURCE_DIR}/sensors/Aggregator.cpp
        ${CMAKE_SOURCE_DIR}/sensors/AirQuality.cpp
        ${CMAKE_SOURCE_DIR}/sensors/Gps.cpp
        ${CMAKE_SOURCE_DIR}/debug/Debug.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCEFILES})

if(DEFINED UT_TEST)
    add_subdirectory(${CMAKE_SOURCE_DIR}/sensors/unit_tests)
    add_subdirectory(${CMAKE_SOURCE_DIR}/unit_tests)
    add_subdirectory(${CMAKE_SOURCE_DIR}/communication/unit_tests)
endif()
