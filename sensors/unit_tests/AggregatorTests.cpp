#include "sensors/Aggregator.hpp"
#include <gtest/gtest.h>
#include <thread>

namespace sensors {
namespace tests {

class AggregatorTest : public testing::Test
{
public:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(AggregatorTest, testSuiteTest)
{
    Aggregator testable;
    data_msg data = testable.GetDataFromSensors();
    EXPECT_EQ(data.sensorValue,123.123);
    EXPECT_EQ(data.timestamp,134732.000);
}

}// namespace tests
}// namespace sensors
