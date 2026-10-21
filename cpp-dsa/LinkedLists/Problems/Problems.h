#pragma once

#include <expected>

// Different problems make different assumptions about the Linked List implementation

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