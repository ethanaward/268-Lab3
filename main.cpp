/**
*	@file : main.cpp
*	@author : Ethan Ward
*	@date : 2015.02.26
*	@brief: Creates a double-linked list, then prints a menu to allow the user to interact with that list as long as needed.
*/
#ifndef MAIN_CPP
#define MAIN_CPP

#include "DoubleLinkedList.h"
#include "Node.h"
#include <iostream>


void printMenu()
{

	std::cout << 	"\n\nMake choice\n"
		<<	"1) Push a value onto front\n"
		<<	"2) Push a value onto back\n"
		<<	"3) Insert behind a value\n"
		<<	"4) Insert ahead of a value\n"
		<<	"5) Remove a value\n"
		<<	"6) Print list\n"
		<<	"7) Quit\n"
		<< 	"Your choice: ";

}

int main() {
DoubleLinkedList<int>* list = new DoubleLinkedList<int>();

int choice = 0;
int value = 0;
int value2 = 0;

while(choice != 7) {
	printMenu();
	std::cin >> choice;
	std::cout << "You chose: " << choice << "\n";
	
	if(choice == 1) {
		std::cout << "Give a value ";

		std::cin >> value;
		list->pushFront(value);

		std::cout << "\n" << value << " added to front of list";
	}
	
	if(choice == 2) {
		std::cout << "Give a value ";

		std::cin >> value;
		list->pushBack(value);

		std::cout << value << " added to back of list";
	}

	if(choice == 3) {
		std::cout << "Give a value to insert. ";
		std::cin >> value;

		std::cout << "Pick a value to insert behind. ";
		std::cin >> value2;

		std::cout << "\n" << "Attempting to insert " << value << " behind " << value2 << 			std::endl;

		try {
			list->insertBehind(value2,value);
		}
		
		catch(std::runtime_error& e) {
			std::cout << "\n" << e.what() << std::endl;
		}

	}

	if(choice == 4) {
		std::cout << "Give a value to insert. ";
		std::cin >> value;

		std::cout << "Pick a value to insert ahead of. ";
		std::cin >> value2;

		std::cout << "\n" << "Attempting to insert " << value << " ahead of " << value2 << 			std::endl;;

		try {
				list->insertAhead(value2,value);
		}
		
		catch(std::runtime_error& e) {
			std::cout << "\n" << e.what() << std::endl;
		}
	}

	if(choice == 5) {
		std::cout << "Give a value to remove. ";
		std::cin >> value;

		std::cout << "You gave " << value << std::endl;

		if(list->remove(value)) {
			std::cout << value << " removed from list.";
		}
		
		else {
			std::cout << value << " could not be removed from list.";
		}		
	}

	if(choice == 6) {
		list->printList();
	}

	if(choice == 7) {
		std::cout << "Program ending...";
	}
	
	if(choice < 1 || choice > 7) {
		std::cout << "Invalid choice";
	}
}

delete list;

};

#endif
