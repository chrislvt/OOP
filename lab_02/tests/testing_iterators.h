#ifndef TESTING_ITERATORS_H
#define TESTING_ITERATORS_H

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


TEST(ListIteratorsSuite, OutOfRangeAccess)
{
    List<int> list{1, 2};
    Iterator<int>it_1 = list.begin();
    Iterator<int>it_2 = list.begin();
    list.pop_front();

    ASSERT_THROW(++it_1, BadObjectPtr);

    // How I can catch BadObjectPtr? :")
    // ASSERT_THROW(it_2++, BadObjectPtr);
}


TEST(ListIteratorSuite, AssignIterator)
{
    // size = 0
    List<int> list_0;
    ASSERT_NO_THROW(Iterator<int> it = list_0.begin());
    ASSERT_NO_THROW(Iterator<int> it = list_0.end());

    // size = 3
    List<int> list_3{1, 2, 3};
    ASSERT_NO_THROW(Iterator<int> it = list_3.begin());
    ASSERT_NO_THROW(Iterator<int> it = list_3.end());
}

#endif // TESTING_ITERATORS_H
