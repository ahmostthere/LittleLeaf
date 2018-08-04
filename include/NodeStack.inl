/*
FILE
-----------------------------------------------------------------------------------------------
NodeStack.cpp

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2018-01-10

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/

template <typename T>
NodeStack<T>::NodeStack() : m_size(0), m_top(nullptr) {
} 

template <typename T>
int NodeStack<T>::size() const {
    return m_size;
}

template <typename T>
bool NodeStack<T>::empty() const {
    return m_size == 0;
}

template <typename T>
const T& NodeStack<T>::top() const {
    return m_top->data();
}

template <typename T>
void NodeStack<T>::pop() {
    // assert m_top neq nullptr ... cannot pop empty list
    if (empty()) {
        std::cout << "Stack is empty";
    } else {
        Node<T>* temp = m_top;
        m_top = m_top->next();
        m_size--;
        delete temp;
    }
}

template <typename T>
void NodeStack<T>::push(const T& data) {
    Node<T>* pushed = new Node<T>(data);
    pushed->next(*m_top);
    m_top = pushed;
    m_size++;
}