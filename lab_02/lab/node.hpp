#ifndef NODE_HPP
#define NODE_HPP

#include "node.h"
#include <stdio.h>


template <typename Type>
Node<Type>::Node()
{
    next = nullptr;
}


template <typename Type>
Node<Type>::Node(const Type &data)
{
    next = nullptr;
    this->data = data;
}


template <typename Type>
Node<Type>::Node(Node<Type> &node)
{
    data = node.data;
    next = node.next;
}


template <typename Type>
Node<Type>::~Node()
{
    next = nullptr;
}


template <typename Type>
void Node<Type>::setData(Type data)
{
    this->data = data;
}


template <typename Type>
Type& Node<Type>::getData()
{
    return data;
}


template <typename Type>
void  Node<Type>::setNext(shared_ptr<Node<Type>> node)
{
    next = node;
}


template <typename Type>
 shared_ptr<Node<Type>> Node<Type>::getNext()
{
    return next;
}


template <typename Type>
void Node<Type>::removeNext()
{
    next = nullptr;
}


template <typename Type>
Node<Type> Node<Type>::operator+(Node<Type> op)
{
    return Node(data + op.data);
}


template <typename Type>
bool Node<Type>::operator ==(const Node<Type>& op) const
{
    return data == op.data;
}


template <typename Type>
bool Node<Type>::operator !=(const Node<Type>& op) const
{
    return data != op.data;
}

#endif // NODE_HPP
