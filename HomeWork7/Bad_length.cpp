#include "Bad_length.h"

const char* Bad_length::what() const noexcept
{
	return "ERROR: array length is negative or invalid.";
}
