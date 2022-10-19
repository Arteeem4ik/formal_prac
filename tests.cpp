#include "LongestSubstr.h"
#include "gtest/gtest.h"
#include <stdexcept>

TEST(LongestSubstrTest, BaseCase0) {
  ASSERT_EQ(LongestSubstr::get_longest_substr_length("ab+c.aba.*.bac.+.+*", "abacb"), 4);
}

TEST(LongestSubstrTest, BaseCase1) {
  ASSERT_EQ(LongestSubstr::get_longest_substr_length("acb..bab.c.*.ab.ba.+.+*a.", "cb"), 0);
}

TEST(LongestSubstrTest, BaseCase2) {
  ASSERT_EQ(LongestSubstr::get_longest_substr_length("ac1..", "ackba"), 2);
}

TEST(LongestSubstrTest, BaseCase3) {
  ASSERT_EQ(LongestSubstr::get_longest_substr_length("ab1+.c.", "abcasj"), 3);
}

TEST(LongestSubstrTest, BaseCase4) {
  ASSERT_EQ(LongestSubstr::get_longest_substr_length("ab1+.c.", "a"), 0);
}

TEST(LongestSubstrTest, BaseCase5) {
  ASSERT_EQ(LongestSubstr::get_longest_substr_length("11.", "ackba"), 0);
}

TEST(LongestSubstrTest, BaseCase6) {
  ASSERT_THROW(LongestSubstr::get_longest_substr_length("abcd", "abcd"), std::logic_error);
}

TEST(LongestSubstrTest, BaseCase7) {
  ASSERT_THROW(LongestSubstr::get_longest_substr_length("a++", "abcd"), std::logic_error);
}

TEST(LongestSubstrTest, BaseCase8) {
  ASSERT_THROW(LongestSubstr::get_longest_substr_length("", "abcd"), std::logic_error);
}

TEST(LongestSubstrTest, BaseCase9) {
  ASSERT_THROW(LongestSubstr::get_longest_substr_length("+", "abcd"), std::logic_error);
}