#include "../LinkedLists.h"
#include "Problems.h"

/*
	- Not using length attribute
	- Not allowed to calculate length
*/

Node* findKthFromEnd(const LinkedList& list, int k) // O(n)
{
	if (k <= 0) return nullptr;

	Node* fast = list.getHead();
	Node* slow = list.getHead();

	for (int i = 0; i < k; i++)
	{
		if (!fast) return nullptr; // kth index out of bounds
		fast = fast->next;
	}

	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return slow; 
}