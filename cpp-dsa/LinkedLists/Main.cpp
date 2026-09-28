#include "LinkedLists.h"
#include <iostream>

int main()
{
	LinkedList linkedList{ 1 };

	linkedList.printList();

	std::cout << "----" << std::endl;

	linkedList.append(2);

	linkedList.append(3);

	linkedList.append(4);

	linkedList.printList();

	std::cout << "----" << std::endl;

	linkedList.removeLast();

	linkedList.printList();


	return 0;
}