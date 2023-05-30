#include "Bad_range.h"

const char* Bad_range::what() const noexcept
{
	return "ERROR: attempt to access elements out of defined range.";
}
