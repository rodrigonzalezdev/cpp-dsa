#include "LinkedLists.h"
#include "Problems/Problems.h"
#include <iostream>

int main()
{
	
	LinkedList list(1);

	list.append(1);
	list.append(1);
	list.append(1);


	list.printList();

	auto result = binaryToDecimal(list);

	if (result)
	{
		std::cout << "Decimal value: " << result.value() << std::endl;
	}
	else
	{
		switch (result.error())
		{
		case BinaryConversionError::InvalidDigit:
			std::cerr << "Error: Invalid binary nmber.";
			break;
		case BinaryConversionError::Overflow:
			std::cerr << "Error: Value exceeds unsigned int range.";
			break;
		default:
			std::cerr << "Error.";
		}
	}


	return 0;
}