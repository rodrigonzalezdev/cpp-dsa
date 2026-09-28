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

	void PrintList();
	void PrintHead();
	void PrintTail();
	void PrintLength();
};