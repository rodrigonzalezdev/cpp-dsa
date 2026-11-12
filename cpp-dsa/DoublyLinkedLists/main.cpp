#include "DoublyLinkedList.h"

#include <iostream>

int main()
{
	DoublyLinkedList list(1);

	list.append(2);
	list.append(4);
	list.append(2);
	list.append(1);

	list.printList();

	std::cout << '\n';
	
	if (list.isPalindrome())
	{
		std::cout << "It's a palindrome!\n";
	}
	else
	{
		std::cout << "It's not a palindrome!\n";
	}


	return 0;
}

