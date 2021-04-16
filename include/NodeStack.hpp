/*
FILE
-----------------------------------------------------------------------------------------------
NodeStack.hpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2018-01-10

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
#ifndef NODE_STACK_HPP
#define NODE_STACK_HPP
#include <iostream>
#include "Node.hpp"

template <typename T>
class NodeStack
{
private:
    int m_size;
    Node<T> *m_top;

public:
    NodeStack();

    int size() const;

    bool empty() const;

    const T &top() const;

    void pop();

    void push(const T &data);

    void clear();

    // used only for testing purposes
    friend std::ostream &operator<<(std::ostream &os, const NodeStack<T> &_stack)
    {
        os << "[top]-->";
        if (!_stack.empty())
        {
            os << *_stack.m_top;
        }
        else
        {
            os << "[/]";
        }
        return os;
    }
};

#include "NodeStack.inl"

#endif // NODE_STACK_HPP