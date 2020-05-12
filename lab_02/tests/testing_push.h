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


TEST(ListPushMethodsSuite, PushBackData)
{
    // empty list + data
    List<int> list_1;

    ASSERT_NO_THROW(list_1.push_back(10));

    ASSERT_EQ(list_1.get_length(), 1);

    ASSERT_EQ(list_1.get_front(), 10);
    ASSERT_EQ(list_1.get_back(), 10);


    // full list + data
    List<int> list_2{10};
    auto it_2 = list_2.begin();

    ASSERT_NO_THROW(list_2.push_back(20));

    ASSERT_EQ(list_2.get_length(), 2);

    ASSERT_EQ(list_2.get_front(), 10);
    ASSERT_EQ(list_2.get_back(), 20);
    ASSERT_EQ(it_2, list_2.begin());
}


TEST(ListPushMethodsSuite, PushBackList)
{
    // empty list + empty list
    List<int> empty_list_1, empty_list_2;

    ASSERT_NO_THROW(empty_list_1.push_back(empty_list_2));
    ASSERT_EQ(empty_list_1.get_length(), 0);


    // empty + full list
    List<int> list_1;
    List<int> full_list{10, 20, 30};

    ASSERT_NO_THROW(list_1.push_back(full_list));

    ASSERT_EQ(list_1.get_length(), 3);

    ASSERT_EQ(list_1.get_front(), 10);
    ASSERT_EQ(list_1.get_back(), 30);

    auto it = list_1.begin();
    list_1.push_back(full_list);
    ASSERT_EQ(it, list_1.begin());


    // full list + empty
    List<int> list_2{10, 20};
    List<int> empty_list;

    ASSERT_NO_THROW(list_2.push_back(empty_list));
    ASSERT_EQ(list_2.get_length(), 2);


    // full + full list
    List<int> list_3{10, 20, 30};
    List<int> list_4{40, 50, 60};

    ASSERT_NO_THROW(list_3.push_back(list_4));

    ASSERT_EQ(list_3.get_length(), 6);

    ASSERT_EQ(list_3.get_front(), 10);
    ASSERT_EQ(list_3.get_back(), 60);
}


TEST(ListPushMethodsSuite, PushFrontData)
{
    // empty list + data
    List<int> list_1;

    ASSERT_NO_THROW(list_1.push_front(10));

    ASSERT_EQ(list_1.get_length(), 1);

    ASSERT_EQ(list_1.get_front(), 10);
    ASSERT_EQ(list_1.get_back(), 10);


    // full list + data
    List<int> list_2{10};
    auto it_2 = list_2.begin();

    ASSERT_NO_THROW(list_2.push_front(20));

    ASSERT_EQ(list_2.get_length(), 2);

    ASSERT_EQ(list_2.get_front(), 20);
    ASSERT_EQ(list_2.get_back(), 10);
    ASSERT_NE(it_2, list_2.begin());
}


TEST(ListPushMethodsSuite, PushFrontList)
{
    // empty + empty list
    List<int> empty_list_1, empty_list_2;

    ASSERT_NO_THROW(empty_list_1.push_front(empty_list_2));
    ASSERT_EQ(empty_list_1.get_length(), 0);


    // empty + full list
    List<int> list_1;
    List<int> full_list{10, 20, 30};

    ASSERT_NO_THROW(list_1.push_front(full_list));

    ASSERT_EQ(list_1.get_length(), 3);

    ASSERT_EQ(list_1.get_front(), 10);
    ASSERT_EQ(list_1.get_back(), 30);


    // full + empty list
    List<int> list_2{10, 20, 30};
    List<int> empty_list;

    ASSERT_NO_THROW(list_2.push_front(empty_list));

    ASSERT_EQ(list_2.get_length(), 3);

    ASSERT_EQ(list_2.get_front(), 10);
    ASSERT_EQ(list_2.get_back(), 30);


    // full + full list
    List<int> list_3{10, 20, 30};
    List<int> list_4{40, 50, 60};

    ASSERT_NO_THROW(list_4.push_front(list_3));

    ASSERT_NE(list_3.begin(), list_4.begin());

    ASSERT_EQ(list_4.get_length(), 6);

    ASSERT_EQ(list_4.get_front(), 10);
    ASSERT_EQ(list_4.get_back(), 60);
}

#endif // TESTING_PUSH_H
