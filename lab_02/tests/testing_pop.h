#ifndef TESTING_POP_H
#define TESTING_POP_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "list.h"
#include "list.hpp"
#include "baselist.h"
#include "baselist.cpp"
#include "errors.h"
#include "iterator.h"
#include "iterator.hpp"

using namespace testing;

TEST(ListPopMethodsSuite, PopBack)
{
    // empty list
    List<int> empty_list;
    ASSERT_THROW(empty_list.pop_back(), EmptyList);


    // list size = 1
    List<int> list_1{1};
    ASSERT_NO_THROW(list_1.pop_back());
    ASSERT_EQ(list_1.get_length(), 0);


    // list size = 2
    List<int> list_2{1, 2};
    ASSERT_NO_THROW(list_2.pop_back());
    ASSERT_EQ(list_2.get_length(), 1);
    ASSERT_EQ(list_2.get_front(), 1);
    ASSERT_EQ(list_2.get_back(), 1);


    // list size = 3
    List<int> list_3{1, 2, 3};
    ASSERT_NO_THROW(list_3.pop_back());
    ASSERT_EQ(list_3.get_length(), 2);
    ASSERT_EQ(list_3.get_front(), 1);
    ASSERT_EQ(list_3.get_back(), 2);
}


TEST(ListPopMethodsSuite, PopFront)
{
    // empty list
    List<int> empty_list;
    ASSERT_THROW(empty_list.pop_front(), EmptyList);


    // list size = 1
    List<int> list_1{1};
    ASSERT_NO_THROW(list_1.pop_front());
    ASSERT_EQ(list_1.get_length(), 0);


    // list size = 2
    List<int> list_2{1, 2};
    ASSERT_NO_THROW(list_2.pop_front());
    ASSERT_EQ(list_2.get_length(), 1);
    ASSERT_EQ(list_2.get_front(), 2);
    ASSERT_EQ(list_2.get_back(), 2);


    // list size = 3
    List<int> list_3{1, 2, 3};
    ASSERT_NO_THROW(list_3.pop_front());
    ASSERT_EQ(list_3.get_length(), 2);
    ASSERT_EQ(list_3.get_front(), 2);
    ASSERT_EQ(list_3.get_back(), 3);
}

#endif // TESTING_POP_H
