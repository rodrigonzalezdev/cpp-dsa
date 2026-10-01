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

void LinkedList::printList()
{
	Node* temp = head;
	
	while (temp)
	{
		std::cout << temp->value << std::endl;
		temp = temp->next;
	}
}

void LinkedList::printHead()
{
	std::cout << "Head: " << head->value << std::endl;
}

void LinkedList::printTail()
{
	std::cout << "Head: " << tail->value << std::endl;
}

void LinkedList::printLength()
{
	std::cout << "Length: " << length << std::endl;
}

void LinkedList::append(int value) // O(1)
{
	Node* newNode = new Node(value);

	if (length == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}

	length++;
}

void LinkedList::removeLast() // O(n)
{
	if (length == 0)
	{
		std::cout << "Error: Linked List is empty" << std::endl;
		return;
	}
	else if (length == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;

		length--;
	}
	else
	{
		Node* temp = head;

		while (temp->next->next)
		{
			temp = temp->next;
		}

		temp->next = nullptr;
		delete tail;
		tail = temp;

		length--;
	}
}

void LinkedList::prepend(int value) // O(1)
{
	Node* newNode = new Node(value);

	if (length == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}

	length++;
}

void LinkedList::removeFirst() // O(1)
{
	if (length == 0)
	{
		std::cout << "Error: Linked List is empty" << std::endl;
		return;
	}
	else if (length == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;

		length--;
	}
	else
	{
		Node* temp = head;
		head = head->next;
		delete temp;

		length--;
	}
}

Node* LinkedList::get(int index) // O(n)
{
	if (index < 0 || index >= length)
	{
		std::cout << "Error: Index out of bounds" << std::endl;
		return nullptr;
	}

	Node* temp = head;

	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}

	return temp;
}

bool LinkedList::set(int index, int value) // O(n)
{
	Node* temp = get(index);

	if (temp == nullptr)
	{
		return false;
	}

	temp->value = value;

	return true;
}