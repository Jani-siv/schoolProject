#include "sensors/AirQuality.hpp"
#include <gtest/gtest.h>

namespace sensors {
namespace tests {

class AirQualityTest : public testing::Test
{
public:
    void SetUp() override {}
    void TearDown() override {}
    std::shared_ptr<communication::Command> command = std::make_shared<communication::Command>();
};

TEST_F(AirQualityTest, testSuiteTest)
{
    AirQuality airQuality(command);
    airQuality.ReadAirQuality();
    EXPECT_EQ(airQuality.GetAirQuality(),"123.123");
}

}// namespace tests
}// namespace sensors
