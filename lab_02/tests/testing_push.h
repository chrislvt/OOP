#ifndef TESTING_PUSH_H
#define TESTING_PUSH_H

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


TEST(ListPushMethodsSuite, AppendNode)
{
    // beginner size = 0
    List<int> list_1;

    ASSERT_NO_THROW(list_1.push_back(10));

    ASSERT_EQ(list_1.get_length(), 1);

    ASSERT_EQ(list_1.get_front(), 10);
    ASSERT_EQ(list_1.get_back(), 10);


    // beginner size = 1
    List<int> list_2{10};
    auto it_2 = list_2.begin();

    ASSERT_NO_THROW(list_2.push_back(20));

    ASSERT_EQ(list_2.get_length(), 2);

    ASSERT_EQ(list_2.get_front(), 10);
    ASSERT_EQ(list_2.get_back(), 20);
    ASSERT_EQ(it_2, list_2.begin());
}


TEST(ListPushMethodsSuite, AppendList)
{
    // append full list
    List<int> list_1;
    List<int> full_list{10, 20, 30};

    ASSERT_NO_THROW(list_1.push_back(full_list));

    ASSERT_EQ(list_1.get_length(), 3);

    ASSERT_EQ(list_1.get_front(), 10);
    ASSERT_EQ(list_1.get_back(), 30);

    auto it = list_1.begin();
    list_1.push_back(full_list);
    ASSERT_EQ(it, list_1.begin());


    // append empty list
    List<int> list_2{10, 20};
    List<int> empty_list;

    ASSERT_NO_THROW(list_2.push_back(empty_list));
    ASSERT_EQ(list_2.get_length(), 2);
}

#endif // TESTING_PUSH_H
