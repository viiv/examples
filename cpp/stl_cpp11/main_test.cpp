#include <gtest/gtest.h>

#include <iostream>

using namespace std;

class FooEvironment : public testing::Environment {
public:
  virtual void SetUp() { cout << "setup test" << endl; }

  virtual void TearDown() { cout << "teardown test" << endl; }
};

class FooTest : public testing::Test {
public:
  static void SetUpTestCase() { cout << "setup testcase" << endl; }

  static void TearDownTestCase() { cout << "teardown testcase" << endl; }

  virtual void SetUp() { name_ = "viivwang"; }

  virtual void TearDown() {}

  string name_;
};

TEST_F(FooTest, expect_test) {
  EXPECT_TRUE(true);
  EXPECT_FALSE(false);
  EXPECT_EQ(true, true);
  EXPECT_NE(1, 10);
  EXPECT_LT(1, 10);
  EXPECT_LE(1, 1);
  EXPECT_GT(10, 1);
  EXPECT_GE(10, 10);

  EXPECT_STREQ("viiv", "viiv");
  EXPECT_STRNE("viiv", "Viiv");
  EXPECT_STRCASEEQ("viiv", "ViiV");
  EXPECT_STRCASENE("viiv", "Viiiv");

  EXPECT_STREQ(name_.c_str(), "viivwang");
}

TEST_F(FooTest, assert_test) {}
