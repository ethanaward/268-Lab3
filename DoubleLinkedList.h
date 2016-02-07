/**
*	@file : DoubleLinkedList.h
*	@author : Ethan Ward
*	@date : 2015.02.26
*	@brief: Creates double-linked lists, pushs values to the front and back of them, inserts values behind and ahead of other values, removes specific values, and prints the entire list.
*/

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdexcept>
#include <iostream>
#include "Node.h"

template <typename T>
class DoubleLinkedList {
public:
/**
	*  @pre None
	*  @post Initializes a DoubleLinkedList instance of the templated type T, with the front and back set to nullptr and the size set to 0.
	*  @return None
	*/
	DoubleLinkedList();
/**
	*  @pre A DoubleLinkedList exists.
	*  @post Deletes all of the nodes in the list.
	*  @return None
	*/
	~DoubleLinkedList();
/**
	*  @pre None
	*  @post None
	*  @return Returns true if the list is empty, false if it isn't.
	*/
	bool isEmpty() const;
/**
	*  @pre None
	*  @post None
	*  @return Returns the size of the list.
	*/
	int size() const;
/**
	*  @pre None
	*  @post Pushes a node with the taken in value to the front of the list, making sure to set m_front to the new node.
	*  @return None
	*/
	void pushFront(T value);
/**
	*  @pre None
	*  @post Pushes a node with the taken in value to the back of the list, making sure to set m_back to the new node.
	*  @return None
	*/
	void pushBack(T value);
/**
	*  @pre None
	*  @post Removes a node in the list with the taken in value, if possible.
	*  @return Returns true if the node is successfully removed, false if it isn't.
	*/
	bool remove(T value);
/**
	*  @pre None
	*  @post Inserts a node in the list with the value newValue ahead of the first node in the list with the value listValue, if possible. Throws an exception if there is no node with listValue in the list.
	*  @return None
	*/
	void insertAhead(T listValue, T newValue) throw(std::runtime_error);
/**
	*  @pre None
	*  @post Inserts a node in the list with the value newValue behind the first node in the list with the value listValue, if possible. Throws an exception if there is no node with listValue in the list.
	*  @return None
	*/
	void insertBehind(T listValue, T newValue) throw(std::runtime_error);
/**
	*  @pre None
	*  @post None
	*  @return Returns a pointer to the first node in the list with the taken in value.
	*/
	Node<T>* find(T value) const;
/**
	*  @pre None
	*  @post Prints the list from front to back.
	*  @return None
	*/
	void printList() const;
private:
	Node<T>* m_front;
	Node<T>* m_back;
	int m_size;
};

#include "DoubleLinkedList.hpp"
#endif
