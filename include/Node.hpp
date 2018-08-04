/*
FILE
-----------------------------------------------------------------------------------------------
Node.cpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2018-01-07

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
template <typename T>
class Node {
public:
    Node(const T& _data);

    Node<T>* next() const;

    const T& data() const;

    void next(Node<T>& _next);

    void data(const T& _data);

    friend std::ostream& operator<< (std::ostream& os, const Node<T>& _node) {
        os << "[" <<  _node.data() << "]";
        os << "-->";
        if (_node.next() == nullptr) {
            os << "[/]";
        } else {
            os << *_node.next();
        }
        return os;
    }

private:
    T m_data;
    Node* m_next;
};

#include "Node.inl"

#endif // NODE_HPP