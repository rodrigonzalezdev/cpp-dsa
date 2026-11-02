#include "../LinkedLists.h"
#include <limits>

/*
	- Not using length attribute
	- Not allowed to calculate length
	- Working with unsigned ints
*/

std::expected<unsigned int, LinkedList::BinaryConversionError> LinkedList::binaryToDecimal() const // O(n)
{
	unsigned int decimal = 0;

	Node* temp = head;

	while (temp)
	{
		if (temp->value != 0 && temp->value != 1)
		{
			return std::unexpected(BinaryConversionError::InvalidDigit);
		}

		if (decimal > (std::numeric_limits<unsigned int>::max() - temp->value) / 2)
		{
			return std::unexpected(BinaryConversionError::Overflow);
		}

		decimal *= 2;

		decimal += temp->value;

		temp = temp->next;
	}

	return decimal;
}