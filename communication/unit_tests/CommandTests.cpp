#include "communication/Command.hpp"
#include <gtest/gtest.h>

namespace communication {
namespace tests {

class CommandTest : public testing::Test
{
public:
    void SetUp() override {}
    void TearDown() override {}
    Command testable;
};


TEST_F(CommandTest, WrongCommand)
{
    std::string test = testable.Execute("Communication not found");
    EXPECT_EQ(test,"Communication not found");
}

TEST_F(CommandTest, RecvUartConnection)
{
    std::string test = testable.Execute("gpsRecv");
    EXPECT_EQ(test,"recv");
    test = testable.Execute("debugRecv");
    EXPECT_EQ(test,"recv");
}

TEST_F(CommandTest, GpsFileMock)
{
    std::string test = testable.Execute("gpsFileMock");
    EXPECT_EQ(test,"$GPGGA,134732.000,5540.3244,N,01231.2941,E");
}

TEST_F(CommandTest, SendTest)
{
    testable.setUartMessage("debugSend", "message");
    EXPECT_EQ(testable.Execute("debugSend"),"message");
    testable.setUartMessage("gpsSend", "message");
    EXPECT_EQ(testable.Execute("gpsSend"),"message");
}

TEST_F(CommandTest, AirQuality)
{
    std::string test = testable.Execute("recvAirFileMock");
    EXPECT_EQ(test, "123.123");
    test = testable.Execute("recvAirFileMock");
    EXPECT_EQ(test, "321.321");
    test = testable.Execute("recvAirFileMock");
    EXPECT_EQ(test, "231.321");
    test = testable.Execute("recvAirFileMock");
    EXPECT_EQ(test, "0.1235");
    test = testable.Execute("recvAirFileMock");
    EXPECT_EQ(test, "123456.123");
    test = testable.Execute("recvAirFileMock");
    EXPECT_EQ(test, "123.123");
}

}
}
