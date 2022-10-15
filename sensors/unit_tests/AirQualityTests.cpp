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
    communication::Command command;
    AirQuality airQuality(command);
    airQuality.ReadAirQuality();
    EXPECT_EQ(airQuality.GetAirQuality(),"123.123");
}

}// namespace tests
}// namespace sensors
