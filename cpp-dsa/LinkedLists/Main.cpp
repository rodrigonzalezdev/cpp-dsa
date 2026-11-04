#include "LinkedLists.h"
#include <iostream>

int main()
{
	
	LinkedList list(1);

	list.append(2);
	list.append(3);
	list.append(4);
	list.append(5);

	list.printList();

	std::cout << '\n';

	list.reverseBetween(1, 3);

	list.printList();

	std::cout << '\n';

	return 0;
}