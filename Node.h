/**
*	@file : Nodet.h
*	@author : Ethan Ward
*	@date : 2015.02.26
*	@brief: Creates Nodes and returns/sets their values.
*/
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {

public:
/**
	*  @pre None
	*  @post Initializes a Node instance of the templated type T with the next and previous set to nullptr and the value set to T().
	*  @return None
	*/
	Node();
/**
	*  @pre None
	*  @post None
	*  @return Returns the value of the Node.
	*/
	int getValue();
/**
	*  @pre None
	*  @post Changes the value of the node to the taken in value.
	*  @return None
	*/
	void setValue(int value);
/**
	*  @pre None
	*  @post None
	*  @return Returns the previous pointer of the node. 
	*/
	Node<T>* getPrevious();
/**
	*  @pre None
	*  @post Changes the previous pointer of the node to the taken in pointer.
	*  @return None
	*/
	void setPrevious(Node<T>* previous);
/**
	*  @pre None
	*  @post None
	*  @return Returns the next pointer of the node.
	*/
	Node<T>* getNext();
/**
	*  @pre None
	*  @post Changes the next pointer of the node to the taken in pointer.
	*  @return None
	*/
	void setNext(Node<T>* next);	
private:
	T m_value;
	Node<T>* m_previous;
	Node<T>* m_next;

};

#include "Node.hpp"
#endif
