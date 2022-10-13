set(TESTNAME DataAnalysisTests)
SET(BASEPATH "${CMAKE_SOURCE_DIR}")
INCLUDE_DIRECTORIES("${BASEPATH}")
set(SOURCEFILES
        ${CMAKE_SOURCE_DIR}/DataAnalysis.cpp
        ${CMAKE_SOURCE_DIR}/unit_tests/DataAnalysisTests.cpp
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
