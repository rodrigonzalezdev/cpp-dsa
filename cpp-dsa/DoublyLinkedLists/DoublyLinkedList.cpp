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

void DoublyLinkedList::printList() const
{
	Node* temp = head;

	while (temp)
	{
		std::cout << temp->value << '\n';

		temp = temp->next;
	}
}