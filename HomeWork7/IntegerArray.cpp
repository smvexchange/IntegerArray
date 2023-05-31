#include "IntegerArray.h"
#include "Bad_range.h"
#include "Bad_length.h"

IntegerArray::IntegerArray() = default;

IntegerArray::IntegerArray(int length) : length_(length)
{
	if (length < 0)
	{
		throw Bad_length();
	}
	data_ = new int[length] {};
};

IntegerArray::~IntegerArray()
{
	delete[] data_;
}

IntegerArray::IntegerArray(IntegerArray& array)
{
	reallocate(array.get_length());
	for (int i = 0; i < length_; ++i)
	{
		data_[i] = array[i];
	}
}

int& IntegerArray::operator[](int index)
{
	if (index < 0 && index > length_)
	{
		throw Bad_range();
	}
	return data_[index];
}

void IntegerArray::erase()
{
	delete[] data_;
	data_ = nullptr;
	length_ = 0;
}

int IntegerArray::get_length()
{
	return length_;
}

void IntegerArray::reallocate(int new_length)
{
	erase();
	if (new_length < 0)
	{
		throw Bad_length();
	}
	data_ = new int[new_length];
	length_ = new_length;
}

void IntegerArray::resize(int new_length)
{
	if (length_ == new_length)
	{
		throw Bad_length();
	}

	if (new_length == 0)
	{
		erase();
		return;
	}

	if (new_length < 0)
	{
		throw Bad_length();
	}
	int* new_data = new int[new_length];
	int elementsToCopy = new_length > length_ ? length_ : new_length;
	for (int i = 0; i < elementsToCopy; ++i)
	{
		new_data[i] = data_[i];
	}
	delete[] data_;
	data_ = new_data;
	length_ = new_length;
}

IntegerArray& IntegerArray::operator=(IntegerArray& array)
{
	if (&array == this)
	{
		return *this;
	}
	reallocate(array.get_length());
	for (int i = 0; i < length_; ++i)
	{
		data_[i] = array.data_[i];
	}
	return *this;
}

void IntegerArray::print()
{
	for (int i = 0; i < length_; ++i)
	{
		std::cout << data_[i] << ' ';
	}
	std::cout << '\n';
}

void IntegerArray::insertBefore(int index, int value)
{
	if (index < 0 && index > length_)
	{
		throw Bad_range();
	}
	int* new_data = new int[length_ + 1];
	for (int i = 0; i < index; ++i)
	{
		new_data[i] = data_[i];
	}
	new_data[index] = value;
	for (int i = index; i < length_; ++i)
	{
		new_data[i + 1] = data_[i];
	}
	delete[] data_;
	data_ = new_data;
	++length_;
}

void IntegerArray::remove(int index)
{
	if (index < 0 && index > length_)
	{
		throw Bad_range();
	}
	if (length_ == 1) {
		erase();
		return;
	}
	int* new_data = new int[length_ - 1];
	for (int i = 0; i < index; ++i)
	{
		new_data[i] = data_[i];
	}
	for (int i = index + 1; i < length_; ++i)
	{
		new_data[i - 1] = data_[i];
	}
	delete[] data_;
	data_ = new_data;
	--length_;
}

void IntegerArray::insertAtBeginning(int value)
{
	insertBefore(0, value);
}

void IntegerArray::insertAtEnd(int value)
{
	insertBefore(length_, value);
}

int IntegerArray::findElement(int value)
{
	for (int i = 0; i < length_; ++i)
	{
		if (data_[i] == value) {
			return i;
		}
	}
	return NULL;
}
