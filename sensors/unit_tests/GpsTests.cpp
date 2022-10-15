#include "sensors/Gps.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <fstream>
#include "sensors/dataStructure.hpp"
#include "debug/Debug.hpp"

namespace sensors {
namespace tests {

class Gpstest : public testing::Test
{
public:
    void SetUp() override {}
    void TearDown() override {}
    std::shared_ptr<communication::Command> command = std::make_shared<communication::Command>();
    std::shared_ptr<Debug> debugger = std::make_shared<Debug>(command);
};

TEST_F(Gpstest, correctData)
{
    Gps testable(command,debugger);
    EXPECT_TRUE(testable.readUart());
    data_msg testableStruct = testable.GetGpsData();
    EXPECT_EQ(testableStruct.longitude,1231.2941);
    EXPECT_EQ(testableStruct.latitude,5540.3244);
    EXPECT_EQ(testableStruct.timestamp,134732.000);
}

TEST_F(Gpstest, WrongData)
{
    Gps testable(command,debugger);
    testable.readUart();
    testable.readUart();
    data_msg testableStruct = testable.GetGpsData();
    EXPECT_EQ(testableStruct.longitude,21231.2941);
    EXPECT_EQ(testableStruct.latitude,19940.3244);
    EXPECT_EQ(testableStruct.timestamp,0);
    std::ifstream fd("/tmp/unit_test",std::ios_base::in);
    EXPECT_TRUE(fd.is_open());
    std::string line;
    std::getline(fd,line);
    EXPECT_EQ(line,"123456");
    fd.close();
    remove("/tmp/unit_test");
}

}// namespace tests
}// namespace sensors
