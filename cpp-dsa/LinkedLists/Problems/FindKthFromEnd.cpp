#include "../LinkedLists.h"

/*
	- Not using length attribute
	- Not allowed to calculate length
*/

Node* LinkedList::findKthFromEnd(int k) const // O(n)
{
	if (k <= 0) return nullptr;

	Node* fast = head;
	Node* slow = head;

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