#include "../LinkedLists.h"

bool LinkedList::hasLoop() const // O(n)
{
	Node* slow = head;
	Node* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			return true; // if the list has a loop, fast and fast->next will never be nullptr
			// so the loop continues until slow and fast meet
		}
	}
	return false;
}