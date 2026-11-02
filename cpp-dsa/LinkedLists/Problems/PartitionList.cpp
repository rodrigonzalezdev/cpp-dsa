#include "../LinkedLists.h"

void LinkedList::partitionList(int value) // O(n)
{
	if (!head)
	{
		return;
	}

	Node dummy1(0);
	Node* prev1 = &dummy1;

	Node dummy2(0);
	Node* prev2 = &dummy2;

	Node* temp = head;

	while (temp)
	{
		if (temp->value < value)
		{
			prev1->next = temp;
			prev1 = prev1->next;
		}
		else
		{
			prev2->next = temp;
			prev2 = prev2->next;
		}

		temp = temp->next;
	}

	prev1->next = dummy2.next;

	prev2->next = nullptr;

	Node* newHead = dummy1.next ? dummy1.next : dummy2.next;
	Node* newTail = dummy2.next ? prev2 : prev1;

	head = newHead;
	tail = newTail;
}