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

void DoublyLinkedList::removeLast()
{
	if (length == 0) return;

	Node* temp = tail;

	if (length == 1)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		tail = tail->prev;
		tail->next = nullptr;
	}

	delete temp;

	length--;
}

void DoublyLinkedList::prepend(int value)
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
		head->prev = newNode;
		head = newNode;
	}

	length++;
}

void DoublyLinkedList::removeFirst()
{
	if (length == 0) return;

	Node* temp = head;

	if (length == 1)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = head->next;
		head->prev = nullptr;
	}

	delete temp;

	length--;
}

Node* DoublyLinkedList::get(int index)
{
	if (index < 0 || index >= length) return nullptr;

	Node* temp = head;

	if (index < length / 2)
	{
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
	}
	else
	{
		temp = tail;

		for (int i = length - 1; i > index; i--)
		{
			temp = temp->prev;
		}
	}

	return temp;
}

bool DoublyLinkedList::set(int index, int value)
{
	Node* temp = get(index);

	if (!temp) return false;

	temp->value = value;

	return true;
}

bool DoublyLinkedList::insert(int index, int value)
{
	if (index < 0 || index > length) return false;

	if (index == 0)
	{
		prepend(value);
		return true;
	}

	if (index == length)
	{
		append(value);
		return true;
	}

	Node* newNode = new Node(value);

	Node* before = get(index - 1);
	Node* after = before->next;

	newNode->prev = before;
	newNode->next = after;

	before->next = newNode;
	after->prev = newNode;

	length++;

	return true;
}

void DoublyLinkedList::remove(int index)
{
	if (index < 0 || index >= length) return;

	if (index == 0) return removeFirst();

	if (index == length - 1) return removeLast();

	Node* temp = get(index);

	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	delete temp;

	length--;
}