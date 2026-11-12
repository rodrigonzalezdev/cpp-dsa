#include "../DoublyLinkedList.h"

void DoublyLinkedList::partitionList(int value)
{
	if (!head) return;

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
			temp->prev = prev1;

			prev1 = prev1->next;
		}
		else
		{
			prev2->next = temp;
			temp->prev = prev2;

			prev2 = prev2->next;
		}

		temp = temp->next;
	}

	prev1->next = dummy2.next;
	if (dummy2.next) dummy2.next->prev = prev1;

	prev2->next = nullptr;

	head = dummy1.next;

	tail = dummy2.next ? prev2 : prev1;

	head->prev = nullptr;
}