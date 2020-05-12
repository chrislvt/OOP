#ifndef NODE_H
#define NODE_H

#include <memory>

using namespace std;

template <typename Type>
class Node
{
public:
    Node();
    Node(const Type &data);
    explicit Node(Node<Type> &node);

    ~Node();

    void setData(Type data);
    Type& getData();

    void setNext(shared_ptr<Node<Type>> node);
    shared_ptr<Node<Type>> getNext();

    void removeNext();

    Node<Type> operator+(Node<Type> op);

    bool operator ==(const Node<Type>& op) const;
    bool operator !=(const Node<Type>& op) const;

private:
    shared_ptr<Node<Type>> next;
    Type data;
};

#endif // NODE_H
