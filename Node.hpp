/**
*	@file : Node.hpp
*	@author : Ethan Ward
*	@date : 2015.02.26
*	@brief: Implements the functionality of Node.h.
*/
template <typename T>
Node<T>::Node() {

m_previous = nullptr;
m_next = nullptr;
m_value = T();

}

template <typename T>
int Node<T>::getValue() {

return(m_value);

}

template <typename T>
void Node<T>::setValue(int value) {

m_value = value;

}

template <typename T>
Node<T>* Node<T>::getPrevious() {

return(m_previous);

}

template <typename T>
void Node<T>::setPrevious(Node<T>* previous) {

m_previous = previous;

}

template <typename T>
Node<T>* Node<T>::getNext() {

return(m_next);

}

template <typename T>
void Node<T>::setNext(Node<T>* next) {

m_next = next;

}

