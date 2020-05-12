#ifndef CONSTITERATOR_HPP
#define CONSTITERATOR_HPP

#include "constiterator.h"
#include "errors.h"
#include <ctime>


template <typename Type>
Type ConstIterator<Type>::current_info()
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
Type ConstIterator<Type>::next_info()
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
bool ConstIterator<Type>::operator!=(ConstIterator<Type> const& other) const noexcept
{
    return containter_obj.lock() != other.containter_obj.lock();
}


template <typename Type>
bool ConstIterator<Type>::operator==(ConstIterator const& other) const noexcept
{
    return containter_obj.lock() == other.containter_obj.lock();
}


template <typename Type>
const Type& ConstIterator<Type>::operator*() const
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
const Type* ConstIterator<Type>::operator->() const
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
ConstIterator<Type>& ConstIterator<Type>::operator++()
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
ConstIterator<Type> ConstIterator<Type>::operator++(int) noexcept
{
    ConstIterator<Type> it(*this);
    ++(*this);
    return it;
}


template<typename Type>
ConstIterator<Type>::operator bool() const noexcept
{
    return !containter_obj.expired();
}

// expiried - true, если объект удален, иначе false
// bool() - true, если объект существует, иначе false

#endif // CONSTITERATOR_HPP
