#include "IntegerArray.h"

IntegerArray::IntegerArray() = default;

IntegerArray::IntegerArray(int length) : length_(length) {
	if (length < 0) {
		throw "Length cannot 0 or less.";
	}
	data_ = new int[length];
};

IntegerArray::~IntegerArray() {
	delete[] data_;
}

IntegerArray::IntegerArray(IntegerArray& array) {
	reallocate(array.get_length());
	for (int i = 0; i < length_; ++i) {
		data_[i] = array[i];
	}
}

int& IntegerArray::operator[](int index)
{
	if (index < 0 && index > length_) {
		throw "Index is incorrect";
	}
	return data_[index];
}

void IntegerArray::erase() {
	delete[] data_;
	data_ = nullptr;
	length_ = 0;
}

int IntegerArray::get_length() {
	return length_;
}

void IntegerArray::reallocate(int new_length) {
	erase();
	if (new_length <= 0) {
		return;
	}
	data_ = new int[new_length];
	length_ = new_length;
}

void IntegerArray::resize(int new_length) {
	if (length_ == new_length) {
		return;
	}
	if (new_length <= 0) {
		erase();
		return;
	}
	int* new_data = new int[new_length];
	int elementsToCopy = new_length > length_ ? length_ : new_length ;
	for (int i = 0; i < elementsToCopy; ++i) {
		new_data[i] = data_[i];
	}
	delete[] data_;
	data_ = new_data;
	length_ = new_length;
}

IntegerArray& IntegerArray::operator=(IntegerArray& array)
{
	if (&array == this) {
		return *this;
	}
	reallocate(array.get_length());
	for (int i = 0; i < length_; ++i) {
		data_[i] = array[i];
	}
	return *this;
}