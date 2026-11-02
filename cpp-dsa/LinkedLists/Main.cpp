#include "LinkedLists.h"
#include <iostream>

int main()
{
	
	LinkedList list(1);

	list.append(1);
	list.append(1);
	list.append(1);


	list.printList();

	auto result = list.binaryToDecimal();

	if (result)
	{
		std::cout << "Decimal value: " << result.value() << std::endl;
	}
	else
	{
		switch (result.error())
		{
		case LinkedList::BinaryConversionError::InvalidDigit:
			std::cerr << "Error: Invalid binary number.";
			break;
		case LinkedList::BinaryConversionError::Overflow:
			std::cerr << "Error: Value exceeds unsigned int range.";
			break;
		default:
			std::cerr << "Error.";
		}
	}


	return 0;
}