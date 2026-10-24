#pragma once

#include <expected>

/*

	Different problems make different assumptions about the Linked List implementation.

	It makes a lot more sense for most of these functions to be implemented as members of the LinkedList class,
	but for organization purposes, since this is a practice repo and not a reusable library, I have implemented 
	them here separately.

*/


Node* findMiddleNode(const LinkedList& list); // O(n)

bool hasLoop(const LinkedList& list); // O(n)

Node* findKthFromEnd(const LinkedList& list, int k); // O(n)

void removeDuplicates(LinkedList& list); // O(n) (set) or O(n^2) (nested loop) depending on the implementation

enum class BinaryConversionError
{
	InvalidDigit,
	Overflow
};

std::expected<unsigned int, BinaryConversionError> binaryToDecimal(const LinkedList& list); // O(n)

void partitionList(LinkedList& list, int value); // O(n)