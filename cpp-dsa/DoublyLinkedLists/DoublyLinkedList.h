#pragma once

class Node
{
public:
	int value;
	Node* next;
	Node* prev;

	Node(int value);
};

class DoublyLinkedList
{
private:
	Node* head;
	Node* tail;
	int length;

public:
	DoublyLinkedList(int value);
	~DoublyLinkedList();

	void printList() const;

	void append(int value);
	void removeLast();
};