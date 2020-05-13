#ifndef TESTING_OPERATORS_H
#define TESTING_OPERATORS_H

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

TEST(ListOperatorsSuite, EqualityListOperator)
{
    // empty list = empty list
    List<int> l1;
    List<int> l2;
    ASSERT_NO_THROW(l1 = l2);


    // empty list = full list
    List<int> list_1{1, 2, 3, 4};
    List<int> list_2;

    ASSERT_NO_THROW(list_2 = list_1);
    ASSERT_NE(list_1.begin(), list_2.begin());

    ASSERT_EQ(list_2.get_length(), 4);


    // full list = empty list
    List<int> list_3{1, 2, 3, 4};
    List<int> list_4;

    ASSERT_NO_THROW(list_3 = list_4);

    ASSERT_EQ(list_3.get_length(), 0);


    // full list = full list
    List<int> list_5{1, 2, 3, 4};
    List<int> list_6{7, 8, 9};

    ASSERT_NO_THROW(list_5 = list_6);
    ASSERT_NE(list_5.begin(), list_6.begin());

    ASSERT_EQ(list_5.get_length(), 3);
}


TEST(ListOperatorsSuite, EqualityInitListOperator)
{
    // empty list = empty init list
    List<int> l1;
    initializer_list<int> i_list = {};
    ASSERT_NO_THROW(l1 = i_list);

    // empty list = full init list
    List<int> list_1;

    ASSERT_NO_THROW((list_1 = {1, 2, 3, 4}));
    ASSERT_EQ(list_1.get_length(), 4);


    // full list = empty init list
    List<int> list_2{1, 2, 3, 4};
    initializer_list<int> init_list = {};

    ASSERT_NO_THROW(list_2 = init_list);

    ASSERT_EQ(list_2.get_length(), 0);


    // full list = full init list
    List<int> list_5{1, 2, 3, 4};

    ASSERT_NO_THROW((list_5 = {7, 8, 9}));

    ASSERT_EQ(list_5.get_length(), 3);
}

#endif // TESTING_OPERATORS_H
