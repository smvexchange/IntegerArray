#pragma once
#ifndef INTEGER_ARRAY_H_
#define INTEGER_ARRAY_H_

class IntegerArray {
public:
	IntegerArray();
	IntegerArray(int length);
	IntegerArray(IntegerArray& array);
	~IntegerArray();
	int& operator[](int index);
	int get_length();
	void erase();	
	void reallocate(int new_length);
	void resize(int new_length);
	IntegerArray& operator=(IntegerArray& array);

private:
	int length_;
	int* data_;
};

#endif INTEGER_ARRAY_H_

