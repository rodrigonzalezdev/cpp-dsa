#include "../LinkedLists.h"

/*
	- In this instance we assume the Linked List does not have a tail
*/

void LinkedList::removeDuplicates() // O(n^2), less efficient version - will implement more efficient version after I've studied sets
{
	Node* current = head;
	
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
				--length;
			}
			else // Only advance runner if no deletion occurred, to check for consecutive duplicates
			{
				runner = runner->next;
			}
			
		}

		current = current->next;
	}
}