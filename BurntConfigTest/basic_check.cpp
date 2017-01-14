//
// Created by Christopher Gutierrez on 1/13/17.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "BurntConfig.h"
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

TEST_F(BurntCheckTest, check_file)
{

    EXPECT_EQ(config->Snapshot->Enable, 1);
}