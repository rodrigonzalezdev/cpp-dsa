#include "../LinkedLists.h"
#include "Problems.h"

/*
	- Not using length attribute
	- Not allowed to calculate length
	- Only allowed to loop through the list once
*/

Node* findMiddleNode(const LinkedList& list) // O(n)
{
	Node* slow = list.getHead();
	Node* fast = list.getHead();

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow; // slow moves through the list at half the speed of fast, 
			     // so when fast is at the end of the list, slow will be in the middle
}