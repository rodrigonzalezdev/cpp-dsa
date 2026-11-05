#include "../LinkedLists.h"

void LinkedList::reverseBetween(int index1, int index2) // O(n)
{
	if (index1 < 0 || index2 <= index1 || index2 >= length) return;

	Node dummy1(0);

	dummy1.next = head;

	Node* prev = &dummy1;

	for (int i = 0; i < index1; ++i)
	{
		prev = prev->next;
	}

	Node* current = prev->next;

	for (int i = 0; i < (index2 - index1); ++i)
	{
		Node* toMove = current->next;

		current->next = toMove->next;

		toMove->next = prev->next;

		prev->next = toMove;
	}

	head = dummy1.next;

	if (current->next == nullptr) tail = current;
	
}