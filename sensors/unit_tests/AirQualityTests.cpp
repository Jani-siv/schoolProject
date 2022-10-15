#include "sensors/AirQuality.hpp"
#include <gtest/gtest.h>

namespace sensors {
namespace tests {

class AirQualityTest : public testing::Test
{
public:
    void SetUp() override {}
    void TearDown() override {
    }
};

TEST_F(AirQualityTest, AirQuality)
{
    std::shared_ptr<communication::Command> command = std::make_shared<communication::Command>();
    AirQuality airQuality(command);
    airQuality.ReadAirQuality();
    std::string data = airQuality.GetAirQuality();
    EXPECT_EQ(data,"123.123");
}

}// namespace tests
}// namespace sensors
