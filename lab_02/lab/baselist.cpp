#include "baselist.h"
#include <iostream>

BaseList::BaseList() noexcept
{
    count = 0;
}


BaseList::BaseList(const BaseList &baselist) noexcept
{
    count = baselist.count;
}


BaseList::~BaseList() {}


bool BaseList::is_empty() const noexcept
{
    return count == 0;
}


int BaseList::get_length() const noexcept
{
    return count;
}
