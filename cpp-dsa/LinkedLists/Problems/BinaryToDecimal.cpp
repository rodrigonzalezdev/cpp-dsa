#include "../LinkedLists.h"
#include "Problems.h"
#include <expected>
#include <limits>

/*
	- Not using length attribute
	- Not allowed to calculate length
	- Working with unsigned ints
*/

std::expected<unsigned int, BinaryConversionError> binaryToDecimal(const LinkedList& list) // O(n)
{
	unsigned int decimal = 0;

	Node* temp = list.getHead();

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