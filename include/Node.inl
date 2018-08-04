/*
FILE
-----------------------------------------------------------------------------------------------
Node.inl

AUTHOR
-----------------------------------------------------------------------------------------------
Thomas Tang

DATE
-----------------------------------------------------------------------------------------------
2018-01-07

DESCRIPTION
-----------------------------------------------------------------------------------------------

*/
template <typename T>
Node<T>::Node(const T& _data) : m_data(_data), m_next(nullptr) {
    
}

template <typename T>
Node<T>* Node<T>::next() const {
    return m_next;
}

template <typename T>
const T& Node<T>::data() const {
    return m_data;
}

template <typename T>
void Node<T>::next(Node<T>& _next) {
    m_next = &_next;
}

template <typename T>
void Node<T>::data(const T& _data) {
    m_data = _data;
}