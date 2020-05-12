#ifndef ConstIterator_H
#define ConstIterator_H

#include <memory>
#include "list.h"

using namespace std;


template <typename Type>
class ConstIterator : public std::iterator<std::output_iterator_tag, Type>
{
    friend class List<Type>;

public:
    ConstIterator(const ConstIterator &it) = default;

    Type current_info();
    Type next_info();

    bool operator!=(ConstIterator<Type> const& other) const noexcept;
    bool operator==(ConstIterator const& other) const noexcept;

    const Type& operator*() const;
    const Type* operator->() const;

    ConstIterator<Type>& operator++();
    ConstIterator<Type> operator++(int) noexcept;

    operator bool() const noexcept;

private:
    ConstIterator(const shared_ptr<Node<Type>> &list) : containter_obj(list) {}

    weak_ptr<Node<Type>> containter_obj;
};

#endif // ConstIterator_H
