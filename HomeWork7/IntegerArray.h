#pragma once
#ifndef INTEGER_ARRAY_H_
#define INTEGER_ARRAY_H_

class IntegerArray {
public:
	IntegerArray();
	IntegerArray(int length);
	IntegerArray(IntegerArray& array);
	~IntegerArray();
	int get_length();
	void erase();	
	void reallocate(int new_length);
	void resize(int new_length);
	void print();
	void insertBefore(int index, int value);
	void remove(int index);
	void insertAtBeginning(int value);
	void insertAtEnd(int value);
	int findElement(int value);
	int& operator[](int index);
	IntegerArray& operator=(IntegerArray& array);

private:
	int length_;
	int* data_;
};

#endif INTEGER_ARRAY_H_

