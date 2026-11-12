#include "../DoublyLinkedList.h"

void DoublyLinkedList::reverse()
{
	if (length == 0) return;

	Node* current = head;
	Node* temp = nullptr;

	while (current)
	{
		temp = current->prev;

		current->prev = current->next;
		current->next = temp;

		current = current->prev;
	}

	temp = head;
	head = tail;
	tail = temp;
}