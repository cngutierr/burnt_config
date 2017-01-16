//
// Created by Christopher Gutierrez on 1/13/17.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <BurntConfig.h>
class BurntCheckTest : public ::testing::Test {

public:
    BurntCheckTest() : Test()
    {
        config = new BurntConfig("config");
    }

    virtual ~BurntCheckTest() {
        delete config;
    }

    BurntConfig *config;
};

TEST_F(BurntCheckTest, check_ClassTree)
{
    EXPECT_STREQ(config->ClassTree->DecTypes[0], "BF");
    EXPECT_STREQ(config->ClassTree->DecTypes[1], "F");
    EXPECT_STREQ(config->ClassTree->DecTypes[2], "R");
    EXPECT_EQ(config->ClassTree->DecValues[0], 0.0023);
    EXPECT_EQ(config->ClassTree->DecValues[1], 0.9603);
    EXPECT_EQ(config->ClassTree->DecValues[2], 0.0009);
    EXPECT_EQ(config->ClassTree->RandTest, true);
}

TEST_F(BurntCheckTest, check_BuffSizes)
{
    EXPECT_EQ(config->BuffSizes->Min, 4096);
    EXPECT_EQ(config->BuffSizes->Max, 4096);
}

TEST_F(BurntCheckTest, check_DebugMessages)
{
    EXPECT_EQ(config->DebugMessages->PrintFilename, true);
    EXPECT_EQ(config->DebugMessages->PrintDebug, true);
    EXPECT_EQ(config->DebugMessages->PrintBuffer, false);
}

TEST_F(BurntCheckTest, check_Snapshot)
{
    EXPECT_EQ(config->Snapshot->Enable, true);
    EXPECT_EQ(config->Snapshot->Sync, true);
}