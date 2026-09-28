#include "LinkedLists.h"
#include <iostream>

// Node class
Node::Node(int value)
{
	this->value = value;
	next = nullptr;
}

// LinkedList class
LinkedList::LinkedList(int value)
{
	Node* newNode = new Node(value);

	head = newNode;
	tail = newNode;

	length = 1;
}

LinkedList::~LinkedList()
{
	Node* temp = head;

	while (head)
	{
		head = head->next;
		delete temp;
		temp = head;
	}
}

void LinkedList::PrintList()
{
	Node* temp = head;
	
	while (temp)
	{
		std::cout << temp->value << std::endl;
		temp = temp->next;
	}
}

void LinkedList::PrintHead()
{
	std::cout << "Head: " << head->value << std::endl;
}

void LinkedList::PrintTail()
{
	std::cout << "Head: " << tail->value << std::endl;
}

void LinkedList::PrintLength()
{
	std::cout << "Head: " << length << std::endl;
}