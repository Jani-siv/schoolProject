#include "DataAnalysis.hpp"
#include <gtest/gtest.h>

namespace analysis {
namespace test {

class DataAnalysisTest : public testing::Test
{
    void SetUp() override
    {

    }
    void TearDown() override
    {}
};

TEST_F(DataAnalysisTest, integrationTest)
{
    DataAnalysis testable;
    std::vector<double> data = testable.StartAnalysis(5);
    EXPECT_TRUE(data.at(0) == 123456.123);
    EXPECT_TRUE(data.at(1) == 0.1235);
    EXPECT_TRUE(data.at(2) == 24826.4023);
}

} // namespace test
} // namespace analysis