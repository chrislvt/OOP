#ifndef LIST_HPP
#define LIST_HPP

#include "list.h"
#include "errors.h"

#include <iostream>
#include <ctime>

using namespace std;


template <typename Type>
List<Type>::List() : BaseList()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}


template <typename Type>
List<Type>::List(const List<Type>& list)
{
    if (list.is_empty())
    {
        time_t t = time(NULL);
        throw ConstructorBadArguments(__FILE__, __LINE__, ctime(&t));
    }

    try
    {
        head.reset(new Node<Type>(list.get_front()));

        shared_ptr<Node<Type>> new_node, current_node = head;
        auto it = list.begin();

        it++;
        for (; it != list.end(); it++)
        {
            new_node.reset(new Node<Type>(*it));
            current_node->setNext(new_node);
            current_node = current_node->getNext();
        }
        tail = current_node;;
        count = list.count;
    }
    catch (const bad_alloc &exc)
    {
        time_t t = time(NULL);
        throw ErrorBadAlloc(__FILE__, __LINE__, ctime(&t));
    }
}


template <typename Type>
List<Type>::List(initializer_list<Type> list)
{
    if (!list.size())
    {
        time_t t = time(NULL);
        throw ConstructorBadArguments(__FILE__, __LINE__, ctime(&t));
    }

    try
    {
        head.reset(new Node<Type>(*list.begin()));

        shared_ptr<Node<Type>> new_node, current_node = head;
        auto it = list.begin();

        it++;
        for(; it != list.end(); it++)
        {
            new_node.reset(new Node<Type>(*it));
            current_node->setNext(new_node);
            current_node = current_node->getNext();
        }
        tail = current_node;
        count = list.size();
    }
    catch (const bad_alloc &exc)
    {
        time_t t = time(NULL);
        throw ErrorBadAlloc(__FILE__, __LINE__, ctime(&t));
    }
}


template <typename Type>
List<Type>::List(Type* array, int size) : List()
{
    if (size < 1)
    {
        time_t t = time(NULL);
        throw ConstructorBadArguments(__FILE__, __LINE__, ctime(&t));
    }

    try
    {
        head.reset(new Node<Type>(array[0]));

        shared_ptr<Node<Type>> new_node, current_node = head;
        for (int i = 1; i < size; i++)
        {
            new_node.reset(new Node<Type>(array[i]));
            current_node->setNext(new_node);
            current_node = current_node->getNext();
        }
        tail = current_node;
        count = size;
    }
    catch (const bad_alloc &exc)
    {
        time_t t = time(NULL);
        throw ErrorBadAlloc(__FILE__, __LINE__, ctime(&t));
    }
}


template <typename Type>
List<Type>::List(List<Type>&& list) noexcept
{
    head = list.head;
    tail = list.tail;
    count = list.count;

    list.head.reset();
    list.tail.reset();
}


template <typename Type>
List<Type>::List(Iterator<Type> it_begin)
{
    if (!it_begin)
    {
        time_t t = time(NULL);
        throw ConstructorBadArguments(__FILE__, __LINE__, ctime(&t));
    }


    try
    {
        count = 1;
        head.reset(new Node<Type>(*it_begin));
        shared_ptr<Node<Type>> new_node, current_node = head;
        auto it = it_begin;

        it++;
        while(it)
        {
            new_node.reset(new Node<Type>(*it));
            current_node->setNext(new_node);
            current_node = current_node->getNext();
            count++;
            it++;
        }
        tail = current_node;
    }
    catch (const bad_alloc &exc)
    {
        time_t t = time(NULL);
        throw ErrorBadAlloc(__FILE__, __LINE__, ctime(&t));
    }
}


template <typename Type>
Type& List<Type>::get_front() const
{
    if (!head)
    {
        time_t t = time(NULL);
        throw ErrorProdigalAlias(__FILE__, __LINE__, ctime(&t));
    }

    return head->getData();
}


template <typename Type>
Type& List<Type>::get_back() const
{
    if (!tail)
    {
        time_t t = time(NULL);
        throw ErrorProdigalAlias(__FILE__, __LINE__, ctime(&t));
    }

    return tail->getData();
}


template <typename Type>
bool List<Type>::is_empty() const noexcept
{
    return count == 0;
}


template <typename Type>
int List<Type>::get_length() const noexcept
{
    return count;
}


template <typename Type>
void List<Type>::push_back(const Type& value)
{
    try
    {
        if (is_empty())
        {
           head.reset(new Node<Type>(value));
           tail = head;
           count = 1;
           return;
        }

        auto new_node = shared_ptr<Node<Type>>(new Node<Type>(value));
        tail->setNext(new_node);
        tail = tail->getNext();
        count += 1;
    }
    catch (const bad_alloc &exc)
    {
        time_t t = time(NULL);
        throw ErrorBadAlloc(__FILE__, __LINE__, ctime(&t));
    }
}


template <typename Type>
void List<Type>::push_back(const List<Type> &list) noexcept
{
    for(auto it = list.begin(); it != list.end(); it++)
        push_back(*it);
}


template <typename Type>
void List<Type>::push_front(const Type& value)
{
    try
    {
        if (is_empty())
        {
           head.reset(new Node<Type>(value));
           tail = head;
           count = 1;
           return;
        }
        auto new_node = shared_ptr<Node<Type>>(new Node<Type>(value));
        new_node->setNext(head);
        head = new_node;
        count += 1;
    }
    catch (const bad_alloc &exc)
    {
        time_t t = time(NULL);
        throw ErrorBadAlloc(__FILE__, __LINE__, ctime(&t));
    }
}


template <typename Type>
void List<Type>::push_front(const List<Type> &list) noexcept
{
    List<Type> front_list(list);

    front_list.tail->setNext(head);
    head = front_list.head;
    count += list.count;
}


template <typename Type>
void List<Type>::push_front(Type* array, int size) noexcept
{
    for (int i = size - 1; i >= 0; i--)
        push_front(array[i]);
}


// Yeah... Ich weiß... das ist schlecht (pop_back() und pop_front()).
template <typename Type>
void List<Type>::pop_back()
{
    auto current_node = head;

    int i = 0;
    while(i < count - 2)
    {
        current_node = current_node->getNext();
        i++;
    }

    current_node->removeNext();
    tail = current_node;
}


template <typename Type>
void List<Type>::pop_front()
{
    head = head->getNext();
}



template <typename Type>
List<Type>& List<Type>::combine(const List<Type>& list) noexcept
{
    push_back(list);
    return (*this);
}


template <typename Type>
Type* List<Type>::to_array()
{
    Type* array = new Type[count];
    if (!array)
    {
        time_t t = time(NULL);
        throw ErrorBadAlloc(__FILE__, __LINE__, ctime(&t));
    }

    int i = 0;
    for (auto &element : *this)
    {
        array[i] = element;
        i++;
    }
    return array;
}


template <typename Type>
void List<Type>::clear() noexcept
{
    for (auto &element : *this)
        element = 0;
}


template <typename Type>
Iterator<Type> List<Type>::begin() const noexcept
{
    return Iterator<Type>(head);
}


template <typename Type>
Iterator<Type> List<Type>::end() const noexcept
{
    return Iterator<Type>(nullptr);
}


template <typename Type>
ConstIterator<Type> List<Type>::cbegin() const noexcept
{
    return ConstIterator<Type>(head);
}


template <typename Type>
ConstIterator<Type> List<Type>::cend() const noexcept
{
    return ConstIterator<Type>(nullptr);
}


template <typename Type>
List<Type>& List<Type>::operator=(const List<Type>& list)
{
    if (count > list.count)
    {
        shared_ptr<Node<Type>> prev_node, cur_node = head;
        for (auto it = list.begin(); it != end(); it++)
        {
            prev_node = cur_node;
            cur_node->setData(*it);
            cur_node = cur_node->getNext();
        }
        prev_node->setNext(nullptr);
        tail = prev_node;
        count = list.count;
    }
    else if (count < list.count)
    {
        auto list_it = list.begin();
        for (auto this_it = begin(); this_it != end(); this_it++)
        {
            (*this_it) = (*list_it);
            list_it++;
        }
        shared_ptr<Node<Type>> new_node, cur_node = tail;
        for (; list_it != list.end(); list_it++)
        {
            new_node.reset(new Node<Type>(*list_it));
            cur_node->setNext(new_node);
            cur_node = cur_node->getNext();
        }
        tail = cur_node;
        count = list.count;
    }
    else
    {
        auto this_it = begin();
        for (auto list_it = list.begin(); list_it != list.end(); list_it++)
        {
            (*this_it) = (*list_it);
            this_it++;
        }
    }
    return *this;
}



template <typename Type>
List<Type>& List<Type>::operator=(List<Type>&& list)
{
    head = list.head;
    tail = list.tail;
    count = list.count;

    list.head.reset();
    list.tail.reset();

    return *this;
}


template <typename Type>
List<Type> List<Type>::operator=(const initializer_list<Type> &init_list)
{
    List new_list(*this);
    new_list.push_back(init_list);
    return new_list;
}


template <typename Type>
List<Type> List<Type>::operator+(const List<Type>& list)
{
    List new_list(*this);
    new_list.push_back(list);
    return new_list;
}


template <typename Type>
List<Type>& List<Type>::operator+=(const List<Type>& list)
{
    (*this) = (*this).combine(list);
    return (*this);
}


template <typename Type>
List<Type>& List<Type>::operator+=(const initializer_list<Type> &init_list)
{
    List new_list(init_list);
    (*this) = (*this).combine(new_list);
    return (*this);
}


template <typename Type>
ostream& operator<<(ostream& os, List<Type>& list)
 {
    os << "List: ";
    if (!list.get_length())
        return os << "null";

    for (auto &element: list)
        os << element << " ";

    return os;
}

#endif // LIST_HPP
