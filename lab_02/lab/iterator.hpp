#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator.h"
#include "errors.h"
#include <ctime>


template <typename Type>
Type Iterator<Type>::current_info()
{
    try
    {
        shared_ptr<Node<Type>> current(containter_obj);
        return containter_obj.lock()->getData();
    }
    catch (const bad_weak_ptr &exc)
    {
        time_t t = time(NULL);
        throw BadObjectPtr(__FILE__, __LINE__, ctime(&t));
    }
}


template <typename Type>
Type Iterator<Type>::next_info()
{
    try
    {
        shared_ptr<Node<Type>> current(containter_obj);
        return containter_obj.lock()->getNext->getData();
    }
    catch (const bad_weak_ptr &exc)
    {
        time_t t = time(NULL);
        throw BadObjectPtr(__FILE__, __LINE__, ctime(&t));
    }
}


template <typename Type>
bool Iterator<Type>::operator!=(Iterator<Type> const& other) const noexcept
{
    return containter_obj.lock() != other.containter_obj.lock();
}


template <typename Type>
bool Iterator<Type>::operator==(Iterator const& other) const noexcept
{
    return containter_obj.lock() == other.containter_obj.lock();
}


template <typename Type>
Type& Iterator<Type>::operator*()
{
    try
    {
        shared_ptr<Node<Type>> current(containter_obj);
        return containter_obj.lock()->getData();
    }
    catch (const bad_weak_ptr &exc)
    {
        time_t t = time(NULL);
        throw BadObjectPtr(__FILE__, __LINE__, ctime(&t));
    }
}


template <typename Type>
const Type& Iterator<Type>::operator*() const
{
    try
    {
        shared_ptr<Node<Type>> current(containter_obj);
        return containter_obj.lock()->getData();
    }
    catch (const bad_weak_ptr &exc)
    {
        time_t t = time(NULL);
        throw BadObjectPtr(__FILE__, __LINE__, ctime(&t));
    }
}


template <typename Type>
Type* Iterator<Type>::operator->()
{
    try
    {
        shared_ptr<Node<Type>> current(containter_obj);
        return &(containter_obj.lock()->getData());
    }
    catch (const bad_weak_ptr &exc)
    {
        time_t t = time(NULL);
        throw BadObjectPtr(__FILE__, __LINE__, ctime(&t));
    }
}


template <typename Type>
const Type* Iterator<Type>::operator->() const
{
    try
    {
        shared_ptr<Node<Type>> current(containter_obj);
        return &(containter_obj.lock()->getData());
    }
    catch (const bad_weak_ptr &exc)
    {
        time_t t = time(NULL);
        throw BadObjectPtr(__FILE__, __LINE__, ctime(&t));
    }
}


template <typename Type>
Iterator<Type>& Iterator<Type>::operator++()
{
    try
    {
        shared_ptr<Node<Type>> current(containter_obj);
        containter_obj = current->getNext();
        return *this;
    }
    catch (const bad_weak_ptr &exc)
    {
        time_t t = time(NULL);
        throw BadObjectPtr(__FILE__, __LINE__, ctime(&t));
    }
}


template <typename Type>
Iterator<Type> Iterator<Type>::operator++(int) noexcept
{
    Iterator<Type> it(*this);
    ++(*this);
    return it;
}


template<typename Type>
Iterator<Type>::operator bool() const noexcept
{
    return !containter_obj.expired();
}

// expiried - true, если объект удален, иначе false
// bool() - true, если объект существует, иначе false

#endif // ITERATOR_HPP
