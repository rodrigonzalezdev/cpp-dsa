#include "DoublyLinkedList.h"

#include <iostream>

int main()
{
	DoublyLinkedList list(1);

	list.printList();

	list.append(2);
	list.append(3);
	
	list.printList();


	return 0;
}

