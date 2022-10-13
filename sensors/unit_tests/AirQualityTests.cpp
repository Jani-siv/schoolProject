#include "sensors/AirQuality.hpp"
#include <gtest/gtest.h>

namespace sensors {
namespace tests {

class AirQualityTest : public testing::Test
{
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(AirQualityTest, testSuiteTest)
{
    EXPECT_TRUE(true);
}

}// namespace tests
}// namespace sensors
