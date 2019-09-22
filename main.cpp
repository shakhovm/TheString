#include <gtest/gtest.h>
#include "MyString.h"


class StringFixture : public :: testing::Test{


};

TEST_F(StringFixture, str_cat)
{
    String str1 = from_cstring("simple");
    String str2 = from_cstring("example");

    str_cat(&str1, &str2);
    EXPECT_EQ(str_len(&str1), 13);
    String str3 = from_cstring("simpleexample");
    EXPECT_EQ(str_cmp(&str1, &str3), 0);
    strn_cat(&str1, &str2, 2);
    EXPECT_EQ(str_len(&str1), 15);

    EXPECT_EQ(strcmp(to_cstring(&str1), "simpleexampleex"), 0);
}

TEST_F(StringFixture, str_cmp)
{
    String str1 = from_cstring("abcddd");
    String str2 = from_cstring("abcde");
    EXPECT_EQ(str_cmp(&str1, &str2), -1);
    EXPECT_EQ(strn_cmp(&str1, &str2, 4), 0);
    EXPECT_EQ(cstrcmp(&str1, "abcddd"), 0);
    str_upr(&str1);
    EXPECT_EQ(cstrcmp(&str1, "ABCDDD"), 0);
    EXPECT_EQ(search_char(&str1, 'D'), 3);
}

TEST_F(StringFixture, str_cpy)
{
    String str1 = from_cstring("example");
    String str2 = strkn_cpy(&str1, 2, 5);
    EXPECT_EQ(cstrcmp(&str2, "amp"), 0);
    String str3 = strn_cpy(&str1, 5);
    EXPECT_EQ(cstrcmp(&str3, "examp"), 0);
    String str4 = str_cpy(&str1);
    EXPECT_EQ(str_cmp(&str1, &str4), 0);
}

TEST_F(StringFixture, sub_strings)
{
    String str1 = from_cstring("example");
    String sub_str1 = from_cstring("am");
    EXPECT_EQ(search_substr(&str1, &sub_str1), 2);
    delete_substr(&str1, &sub_str1);
    EXPECT_EQ(cstrcmp(&str1, "exple"), 0);
}