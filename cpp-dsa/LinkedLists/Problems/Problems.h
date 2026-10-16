#pragma once

// Different problems make difference assumptions about the Linked List implementation

Node* findMiddleNode(const LinkedList& list); // O(n)
bool hasLoop(const LinkedList& list); // O(n)
Node* findKthFromEnd(const LinkedList& list, int k); // O(n)
void removeDuplicates(LinkedList& list); // O(n) (set) or O(n^2) (nested loop) depending on the implementation