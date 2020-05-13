#ifndef Iterator_H
#define Iterator_H

#include <memory>
#include "list.h"

using namespace std;


template <typename Type>
class Iterator : public std::iterator<std::input_iterator_tag, Type>
{
    friend class List<Type>;

public:
    Iterator(const Iterator &it) = default;

    Type current_info();
    Type next_info();

    bool operator!=(Iterator<Type> const& other) const;
    bool operator==(Iterator const& other) const;

    Type& operator*();
    const Type& operator*() const;
    Type* operator->();
    const Type* operator->() const;

    Iterator<Type>& operator++();
    Iterator<Type> operator++(int);

    operator bool() const;

private:
    Iterator(const shared_ptr<Node<Type>> &list) : containter_obj(list) {}

    weak_ptr<Node<Type>> containter_obj;
};

#endif // Iterator_H
