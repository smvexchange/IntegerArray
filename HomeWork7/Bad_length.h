#pragma once
#ifndef BAD_LENGTH_H_
#define BAD_LENGTH_H_
#include <exception>
#include <iostream>

class Bad_length : public std::exception {
public:
	virtual const char* what() const noexcept override;
};

#endif BAD_LENGTH_H_