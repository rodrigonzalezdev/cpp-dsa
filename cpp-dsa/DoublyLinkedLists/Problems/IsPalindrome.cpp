#include "../DoublyLinkedList.h"

bool DoublyLinkedList::isPalindrome()
{
	if (length == 0 || length == 1) return true;

	Node* forward = head;
	Node* backward = tail;

	for (int i = 0; i < length / 2; i++)
	{
		if (forward->value != backward->value) return false;

		forward = forward->next;
		backward = backward->prev;
	}

	return true;
}