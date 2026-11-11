#include "../LinkedLists.h"

void LinkedList::swapPairs() // O(n)
{
	if (!head) return;

	Node dummy(0);
	dummy.next = head;

	Node* prev = &dummy;

	Node* temp1 = prev->next;

	while (temp1 && temp1->next)
	{
		Node* temp2 = temp1->next;

		prev->next = temp2;

		temp1->next = temp2->next;

		temp2->next = temp1;

		prev = temp1;

		temp1 = prev->next;
	}

	head = dummy.next;
}