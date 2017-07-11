#include <gtest/gtest.h>

using namespace std;

struct AlgorithmTest : public testing::Test {
  static void SetUpTestCase() {}

  static void TearDownTestCase() {}

  virtual void SetUp() {
    foo = {{3, 5, 7, 9, 11, 13, 15, 163}};
    bar = {{1, 2, 3, 4, 5, 6, 7, 8}};
  }

  virtual void TearDown() {}

  array<int, 8> foo;
  array<int, 8> bar;
};

TEST_F(AlgorithmTest, test_non_modifying_sequence_operations) {
  EXPECT_TRUE(all_of(begin(foo), end(foo), [](int i) { return i % 2; }));
  EXPECT_TRUE(all_of(begin(foo), begin(foo), [](int i) { return false; }));

  EXPECT_TRUE(any_of(begin(foo), end(foo), [](int i) { return i >= 3; }));
  EXPECT_FALSE(any_of(begin(foo), begin(foo), [](int i) { return false; }));

  EXPECT_TRUE(none_of(begin(foo), end(foo), [](int i) { return i < 3; }));
  EXPECT_TRUE(none_of(begin(foo), end(foo), [](int i) { return false; }));

  int index = 0;
  for_each(begin(foo), end(foo), [&](int i) {
    EXPECT_EQ(i, foo[index]);
    ++index;
  });

  auto itor = find(begin(foo), end(foo), 11);
  EXPECT_NE(itor, end(foo));
  EXPECT_EQ(*itor, 11);

  itor = find(itor + 1, end(foo), 163);
  EXPECT_NE(itor, end(foo));
  EXPECT_EQ(*itor, 163);
  EXPECT_EQ(itor + 1, end(foo));

  itor = find(begin(foo), end(foo), 2);
  EXPECT_EQ(itor, end(foo));

  itor = find_if(begin(foo), end(foo), [&](int i) { return i > 100; });
  EXPECT_EQ(*itor, 163);

  itor = find_if_not(begin(foo), end(foo), [&](int i){return i==3;});
  EXPECT_EQ(*itor, 5);
  itor = find_if_not(itor, end(foo), [&](int i){return i==3;});
  EXPECT_EQ(*itor, 5);
}
