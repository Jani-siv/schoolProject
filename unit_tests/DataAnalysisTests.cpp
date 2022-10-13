#include "DataAnalysis.hpp"
#include <gtest/gtest.h>

class DataAnalysisTest : public testing::Test
{
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(DataAnalysisTest, testSuiteTest)
{
    EXPECT_TRUE(true);
}
