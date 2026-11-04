#pragma once

#include <expected>

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

	// Leetcode problems

	Node* findMiddleNode() const; // O(n)

	bool hasLoop() const; // O(n)

	Node* findKthFromEnd(int k) const; // O(n)

	void removeDuplicates(); // O(n) (set) or O(n^2) (nested loop) depending on the implementation

	enum class BinaryConversionError
	{
		InvalidDigit,
		Overflow
	};

	std::expected<unsigned int, BinaryConversionError> binaryToDecimal() const; // O(n)

	void partitionList(int value); // O(n)

	void reverseBetween(int index1, int index2); 
};