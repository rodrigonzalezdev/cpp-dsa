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

void LinkedList::printList() const
{
	Node* temp = head;
	
	while (temp)
	{
		std::cout << temp->value << std::endl;
		temp = temp->next;
	}
}

Node* LinkedList::getHead() const
{
	return head;
}

Node* LinkedList::getTail() const
{
	return tail;
}

void LinkedList::increaseLength()
{
	++length;
}

void LinkedList::decreaseLength()
{
	--length;
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

Node* LinkedList::get(int index) const // O(n)
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

bool LinkedList::insert(int index, int value) // O(n)
{
	if (index < 0 || index > length)
	{
		std::cout << "Error: Index out of bounds" << std::endl;
		return false;
	}

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
	Node* temp = get(index - 1);

	newNode->next = temp->next;
	temp->next = newNode;

	length++;

	return true;
}

void LinkedList::remove(int index) // O(n)
{
	if (index < 0 || index >= length)
	{
		std::cout << "Error: Index out of bounds" << std::endl;
		return;
	}

	if (index == 0)
	{
		removeFirst();
		return;
	}

	if (index == length - 1)
	{
		removeLast();
		return;
	}

	Node* temp = get(index - 1);
	Node* target = temp->next;

	temp->next = target->next;
	delete target;

	length--;
}

void LinkedList::reverse() // O(n)
{
	Node* temp = head;
	head = tail;
	tail = temp;

	Node* before = nullptr;
	Node* after = temp->next;

	for (int i = 0; i < length; i++)
	{
		after = temp->next;
		temp->next = before;
		before = temp;
		temp = after;
	}

}