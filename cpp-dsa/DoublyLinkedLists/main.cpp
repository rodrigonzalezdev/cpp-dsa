#include "DoublyLinkedList.h"

#include <iostream>

int main()
{
	DoublyLinkedList list(1);

	list.printList();

	list.append(2);
	list.append(3);
	list.prepend(0);
	list.removeLast();
	list.removeFirst();

	std::cout << '\n';
	
	list.printList();


	return 0;
}

