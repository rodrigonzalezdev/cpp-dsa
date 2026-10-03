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

	void printList() const;

	Node* getHead() const;
	Node* getTail() const;

	void append(int value);
	void removeLast();
	void prepend(int value);
	void removeFirst();
	Node* get(int index) const;
	bool set(int index, int value);
	bool insert(int index, int value);
	void remove(int index);

	void reverse();
};