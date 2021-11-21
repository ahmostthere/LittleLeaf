#ifndef TEST_STACK
#define TEST_STACK

#include <iostream>
#include <stdexcept>


template <typename T>
class Stack
{
private:
    class Node
    {
    private:
        T m_data;
        Node *m_next;

    public:
        Node(const T &_data) : m_data(_data), m_next(nullptr) {}

        Node *next() const
        {
            return m_next;
        }

        const T &data() const
        {
            return m_data;
        }

        void next(Node &_next)
        {
            m_next = &_next;
        }

        void data(const T &_data)
        {
            m_data = _data;
        }

        friend std::ostream &operator<<(std::ostream &os, const Node &_node)
        {
            os << "[" << _node.data() << "]";
            os << "-->";
            // if (_node.next() == nullptr)
            // {
            //     os << "[/]";
            // }
            // else
            // {
            //     os << *_node.next();
            // }
            return os;
        }
    };

    int m_size;
    Node *m_top;

public:
    Stack() : m_size(0), m_top(nullptr) {}

    int size() const
    {
        return m_size;
    }

    bool empty() const
    {
        return m_size == 0;
    }

    const T &top() const
    {
        return m_top->data();
    }

    void pop()
    {
        if (!empty())
        {
            Node *nodeToRemove = m_top;
            m_top = m_top->next();
            m_size--;
            delete nodeToRemove;
        }
    }

    void popAt(int index)
    {
        if (index >= 0 && index < m_size)
        {
            if (!empty())
            {
                if (index == 0)
                {
                    pop();
                } 
                else 
                {
                    Node *prevNode = m_top;
                    Node *nodeToRemove = m_top->next();

                    for (int i = 1; i < index; i++)
                    {
                        prevNode = prevNode->next();
                        nodeToRemove = nodeToRemove->next();
                    }
                    prevNode->next(*nodeToRemove->next());
                    m_size--;
                    delete nodeToRemove;
                }
            }
        }
        else
        {
            // throw std::out_of_range();
            std::cout << "index [" << index << "] out of range" << std::endl;
        }
    }

    const T &operator[](int index) 
    {
        if (empty() || index < 0 || index >= m_size)
        {
            throw std::out_of_range("index out of range");
        } 
        else
        {
            Node *nodeValueToReturn = m_top;
            for (int i = 0; i < index; i++)
            {
                nodeValueToReturn = nodeValueToReturn->next();
            }
            return nodeValueToReturn->data();
        }
    }

    void push(const T &data)
    {
        Node *nodeToAdd = new Node(data);
        nodeToAdd->next(*m_top);
        m_top = nodeToAdd;
        m_size++;
    }

    bool contains(T data)
    {
        for (Node *nodeToCheck = m_top; nodeToCheck != nullptr; nodeToCheck = nodeToCheck->next())
        {   
            if (nodeToCheck->data() == data) 
            {
                return true;
            }
        }
        return false;
    }

    bool remove(const T& data)
    {
        if (empty()) return false;
        Node *prevNode = m_top;
        if (prevNode->data() == data)
        {
            std::cout << "Remove" << std::endl;
            pop();
            return true;
        }
        for (Node *nodeToRemove = prevNode->next(); nodeToRemove != nullptr; nodeToRemove = nodeToRemove->next())
        {
            if (nodeToRemove->data() == data)
            {
                std::cout << "Remove" << std::endl;
                prevNode->next(*nodeToRemove->next());
                m_size--;
                delete nodeToRemove;
                return true;
            }
            prevNode = prevNode->next();
        }
        return false;
    }

    void clear()
    {
        while (!empty())
        {
            pop();
        }
    }

    // used only for testing purposes
    friend std::ostream &operator<<(std::ostream &os, const Stack<T> &_stack)
    {
        os << "[top]-->";
        if (!_stack.empty())
        {
            Node *nodeToPrint = _stack.m_top;
            while (nodeToPrint != nullptr)
            {
                os << *nodeToPrint;
                nodeToPrint = nodeToPrint->next();
            }
        }
        os << "[/]";
        return os;
    }
};

typedef Stack<int> Stack_i;

#endif