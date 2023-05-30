#pragma once
#ifndef BAD_RANGE_H_
#define BAD_RANGE_H_
#include <exception>
#include <iostream>

class Bad_range : public std::exception {
public:
	virtual const char* what() const noexcept override;
};

#endif BAD_RANGE_H_
