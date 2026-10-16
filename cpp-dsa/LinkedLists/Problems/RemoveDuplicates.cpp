#include "../LinkedLists.h"
#include "Problems.h"

/*
	- In this instance we assume the Linked List does not have a tail
*/

void removeDuplicates(LinkedList& list) // O(n^2), less efficient version - will implement more efficient version after I've studied sets
{
	Node* current = list.getHead();
	
	while (current && current->next)
	{
		Node* runner = current;

		while (runner->next)
		{
			if (runner->next->value == current->value)
			{
				Node* temp = runner->next;
				runner->next = temp->next;
				delete temp;
				list.decreaseLength();
			}
			else // Only advance runner if no deletion occured, to check for consecutive duplicates
			{
				runner = runner->next;
			}
			
		}

		current = current->next;
	}
}