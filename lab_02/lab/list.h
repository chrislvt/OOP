#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <memory>
#include <initializer_list>

#include "baselist.h"
#include "node.hpp"

using namespace std;

template <typename Type> class Iterator;
template <typename Type> class ConstIterator;

template <typename Type>
class List : public BaseList
{
public:
    List();
    explicit List(const List<Type>& list);
    List(initializer_list<Type> list);
    List(Type* array, int size);
    List(List<Type>&& list) noexcept;
    List(Iterator<Type> it_begin);

    ~List() = default;

    Type& get_front() const;
    Type& get_back() const;

    bool is_empty() const noexcept;
    int get_length() const noexcept;
    void clear() noexcept;

    void push_back(const Type& value);
    void push_back(const List<Type> &list) noexcept;

    void push_front(const Type& value);
    void push_front(const List<Type> &list) noexcept;

    void pop_back();
    void pop_front();

    List<Type>& combine(const List<Type>& list) noexcept;

    Type* to_array();

    Iterator<Type> begin() const noexcept;
    Iterator<Type> end() const noexcept;
    ConstIterator<Type> cbegin() const noexcept;
    ConstIterator<Type> cend() const noexcept;

    List<Type>& operator=(const List<Type>& list);
    List<Type>& operator=(const initializer_list<Type> &init_list);

    List<Type>& operator=(List<Type>&& list);

    List<Type> operator+(const List<Type>& list);

    List<Type>& operator+=(const List<Type>& list);
    List<Type>& operator+=(const initializer_list<Type> &init_list);

private:
    shared_ptr<Node<Type>> head;
    shared_ptr<Node<Type>> tail;
    int count;
};

#endif // LIST_H
