#include "DoublyLinkedList.h"

#include <iostream>

Node::Node(int value)
{
	this->value = value;
	next = nullptr;
	prev = nullptr;
}

DoublyLinkedList::DoublyLinkedList(int value)
{
	Node* newNode = new Node(value);
	head = newNode;
	tail = newNode;

	length = 1;
}

DoublyLinkedList::~DoublyLinkedList()
{
	while (head)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

void DoublyLinkedList::printList() const
{
	Node* temp = head;

	while (temp)
	{
		std::cout << temp->value << '\n';

		temp = temp->next;
	}
}

void DoublyLinkedList::append(int value)
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
		newNode->prev = tail;
		tail = newNode;
	}

	length++;
}