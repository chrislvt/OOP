#ifndef TESTING_CONSTRUCTORS_H
#define TESTING_CONSTRUCTORS_H

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


TEST(ListBaseSuite, DefaultConstrucor)
{
    List<int> list;
    ASSERT_TRUE(list.is_empty());
}


TEST(ListBaseSuite, CreationFromInitializerList)
{
    // size = 0
    initializer_list<int> empty_initializer_list{};
    ASSERT_THROW(List<int> empty_list{empty_initializer_list}, ConstructorBadArguments);


    // size = 1
    ASSERT_NO_THROW(List<int> list_1({1}));

    List<int> list_1{1};
    ASSERT_EQ(list_1.get_length(), 1);
    ASSERT_EQ(list_1.get_front(), list_1.get_back());


    // size = 2
    ASSERT_NO_THROW(List<int> list_2({1, 2}));

    List<int> list_2{1, 2};
    ASSERT_EQ(list_2.get_length(), 2);
    ASSERT_EQ(list_2.get_front(), 1);
    ASSERT_EQ(list_2.get_back(), 2);


    // size = 3
    ASSERT_NO_THROW(List<int> list_3({1, 2, 3}));

    List<int> list_3{1, 2, 3};
    ASSERT_EQ(list_3.get_length(), 3);
    ASSERT_EQ(list_3.get_front(), 1);
    ASSERT_EQ(list_3.get_back(), 3);
}


TEST(ListBaseSuite, CopyConstructor)
{
    // size = 0
    List<int> list_0;
    ASSERT_THROW(List<int> empty_list(list_0), ConstructorBadArguments);


    // size = 1
    List<int> list_1{1};
    ASSERT_NO_THROW(List<int> list(list_1));

    List<int> list_10(list_1);
    ASSERT_EQ(list_10.get_length(), 1);
    ASSERT_EQ(list_10.get_front(), list_10.get_back());

    ASSERT_NE(list_1.begin(), list_10.begin());


    // size = 2
    List<int> list_2{1, 2};
    ASSERT_NO_THROW(List<int> list(list_2));

    List<int> list_20(list_2);
    ASSERT_EQ(list_20.get_length(), 2);
    ASSERT_EQ(list_20.get_front(), 1);
    ASSERT_EQ(list_20.get_back(), 2);

    ASSERT_NE(list_2.begin(), list_20.begin());


    // size = 3
    List<int> list_3{1, 2, 3};
    ASSERT_NO_THROW(List<int> list(list_3));

    List<int> list_30(list_3);
    ASSERT_EQ(list_30.get_length(), 3);
    ASSERT_EQ(list_30.get_front(), 1);
    ASSERT_EQ(list_30.get_back(), 3);

    ASSERT_NE(list_3.begin(), list_30.begin());
}

TEST(ListBaseSuite, CreationFromIterator)
{
    // size = 0
    List<int> list_0;
    Iterator<int> it = list_0.begin();
    ASSERT_THROW(List<int> empty_list(it), ConstructorBadArguments);

    // size = 1
    List<int> list_1{1};
    it = list_1.begin();

    ASSERT_NO_THROW(List<int> list(it));

    List<int> list_10(it);
    ASSERT_EQ(list_10.get_length(), 1);
    ASSERT_EQ(list_10.get_front(), list_10.get_back());

    ASSERT_NE(list_1.begin(), list_10.begin());


    // size = 2
    List<int> list_2{1};
    it = list_1.begin();

    ASSERT_NO_THROW(List<int> list(it));

    List<int> list_20(it);
    ASSERT_EQ(list_20.get_length(), 1);
    ASSERT_EQ(list_20.get_front(), list_20.get_back());

    ASSERT_NE(list_2.begin(), list_20.begin());
}


TEST(ListBaseSuite, CreationFromArray)
{
    int array[5] = {1, 2, 3, 4, 5};

    // Invalid data (incorrect index)
    ASSERT_THROW(List<int> list(array, 0), ConstructorBadArguments);
    ASSERT_THROW(List<int> list(array, -1), ConstructorBadArguments);

    // What I must to do with memory?..

    //___________________________________________________________
    // Array size = 5.
    ASSERT_NO_THROW(List<int> list(array, 5));

    List<int> list(array, 5);
    ASSERT_EQ(list.get_length(), 5);

    int i = 0;
    for (auto it = list.begin(); it != list.end(); it++)
    {
        ASSERT_EQ(*it, array[i]);
        i++;
    }
    //___________________________________________________________
}


#endif // TESTING_CONSTRUCTORS_H
