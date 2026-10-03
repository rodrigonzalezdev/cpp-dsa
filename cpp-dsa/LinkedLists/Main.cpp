#include "LinkedLists.h"
#include "Problems/Problems.h"
#include <iostream>

int main()
{
	
	LinkedList list(1);

	list.append(2);
	list.append(3);
	list.append(4);
	list.append(5);
	list.append(6);
	list.append(7);

	list.printList();

	std::cout << "Middle node: " << FindMiddleNode(list)->value << std::endl;


	return 0;
}