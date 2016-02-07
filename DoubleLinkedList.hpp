/**
*	@file : DoubleLinkedList.hpp
*	@author : Ethan Ward
*	@date : 2015.02.26
*	@brief: Implements the functionality of DoubleLinkedList.h
*/
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() { 

m_front = nullptr;
m_back = nullptr;
m_size = 0;

}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
	
Node<T>* temp = m_front;
Node<T>* temp2 = temp;

if(size() == 1) {
	delete m_front;
	m_front = nullptr;
	m_back = nullptr;
	temp = nullptr;
	temp2 = nullptr;
}

while(temp != nullptr) {
	temp = temp->getNext();
	delete temp2;
	temp2 = temp;	
}

}

template <typename T>
bool DoubleLinkedList<T>::isEmpty() const {

if(size() == 0) {
	return(true);
} 

else {
	return(false);
}

}

template <typename T>
int DoubleLinkedList<T>::size() const {

return(m_size);

}

template <typename T>
void DoubleLinkedList<T>::pushFront(T value) {

Node<T>* temp = new Node<T>();
temp->setValue(value);

if(isEmpty()) {
	m_front = temp;
	m_back = temp;
	m_size++;
}

else if(size() == 1) {
	temp->setNext(m_front);
	m_front = temp;
	m_back->setPrevious(m_front);
	m_size++;
}

else {
	temp->setNext(m_front);
	m_front->setPrevious(temp);
	m_front = temp;
	m_size++;
}

}

template <typename T>
void DoubleLinkedList<T>::pushBack(T value) {

Node<T>* temp = new Node<T>();
temp->setValue(value);

if(isEmpty()) {
	m_front = temp;
	m_back = temp;
	m_size++;
}

else if(size() == 1) {
	temp->setPrevious(m_back);
	m_back = temp;
	m_front->setNext(m_back);
	m_size++;
}

else {
	temp->setPrevious(m_back);
	m_back->setNext(temp);
	m_back = temp;
	m_size++;
}

}

template <typename T>
bool DoubleLinkedList<T>::remove(T value){

Node<T>* temp = find(value);

if(isEmpty() || temp == nullptr) {
	return(false);
}

else if(size() == 1) {
	delete m_front;
	m_front = nullptr;
	m_back = nullptr;
	m_size --;
	return(true);
}

else if(temp == m_front) {
	temp = m_front->getNext();
	delete m_front;
	temp->setPrevious(nullptr);

	if(size() == 2) {
		m_front = m_back;
	}

	else {
		m_front = temp;
	}	

	m_size --;
	return(true);
}

else if(temp == m_back) {

	temp = m_back->getPrevious();
	delete m_back;
	temp->setNext(nullptr);
	
	if(size() == 2) {
		m_back = m_front;
	}
	
	else {	
		m_back = temp;
	}

	m_size --;
	return(true);
}

else {
	
	Node<T>* tempPrev = temp->getPrevious();
	Node<T>* tempNext = temp->getNext();
	tempNext->setPrevious(tempPrev);
	tempPrev->setNext(tempNext);
	
	delete temp; 
	m_size --;
	return(true);
}

}

template <typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue) throw (std::runtime_error) {

Node<T>* temp = find(listValue);
Node<T>* temp2;
Node<T>* newNode = new Node<T>();
newNode->setValue(newValue);

if(temp == nullptr) {
	throw std::runtime_error("Value not found");
}

else if(temp == m_front) {
	m_front->setPrevious(newNode);
	newNode->setNext(m_front);
	m_front = newNode;

	std::cout << newValue << " inserted ahead of " << listValue;
	
	m_size++;
}

else {
	temp2 = temp->getPrevious();
	newNode->setNext(temp);
	newNode->setPrevious(temp2);
	temp2->setNext(newNode);
	temp->setPrevious(newNode);

	std::cout << newValue << " inserted ahead of " << listValue;
	
	m_size++;
}

newNode = nullptr;
delete newNode;

}

template <typename T>
void DoubleLinkedList<T>::insertBehind(T listValue, T newValue) throw (std::runtime_error) {

Node<T>* temp = find(listValue);
Node<T>* temp2;
Node<T>* newNode = new Node<T>();
newNode->setValue(newValue);


if(temp == nullptr) {
	throw std::runtime_error("Value not found");
}

else if(temp == m_back) {
	m_back->setNext(newNode);
	newNode->setPrevious(m_back);
	m_back = newNode;

	std::cout << newValue << " inserted behind " << listValue;

	m_size++;
}

else {
	temp2 = temp->getNext();
	newNode->setNext(temp2);
	newNode->setPrevious(temp);
	temp->setNext(newNode);
	temp2->setPrevious(newNode);

	std::cout << newValue << " inserted behind " << listValue;

	m_size++;
}

newNode = nullptr;
delete newNode;

}

template <typename T>
Node<T>* DoubleLinkedList<T>::find(T value) const {

Node<T>* temp;
temp = m_front;

while(temp != nullptr) {

	if(temp->getValue() == value) {
		return(temp);
	}

	temp = temp->getNext();
}

return(nullptr);

}

template <typename T>
void DoubleLinkedList<T>::printList() const {

Node<T>* temp;
temp = m_front;

while(temp != nullptr) {
	std::cout << temp->getValue() << " ";
	temp = temp->getNext();
}

}


