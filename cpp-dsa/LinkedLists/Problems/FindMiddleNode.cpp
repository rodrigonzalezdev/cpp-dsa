#include "../LinkedLists.h"

/*
	- Not using length attribute
	- Not allowed to calculate length
	- Only allowed to loop through the list once
*/

Node* LinkedList::findMiddleNode() const // O(n)
{
	Node* slow = head;
	Node* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow; // slow moves through the list at half the speed of fast, 
			     // so when fast is at the end of the list, slow will be in the middle
}