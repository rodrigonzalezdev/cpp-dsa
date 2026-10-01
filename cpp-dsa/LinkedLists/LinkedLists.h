#pragma once

//Node class
class Node
{
public:
	int value;
	Node* next;

	Node(int value);
};

//LinkedList class
class LinkedList
{
private:
	Node* head;
	Node* tail;
	int length;

public:
	LinkedList(int value);
	~LinkedList();

	void printList();
	void printHead();
	void printTail();
	void printLength();

	void append(int value);
	void removeLast();
	void prepend(int value);
	void removeFirst();
	Node* get(int index);
	bool set(int index, int value);
	bool insert(int index, int value);
	void remove(int index);
};