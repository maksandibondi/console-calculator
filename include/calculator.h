#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "parser.h"
#include "utilities.h"
#include <limits>

class Calculator {
	bool empty = true;
public:
	double memory;
	double calculate(std::string& expression);
	void clear();
	bool is_empty();
};
#endif
