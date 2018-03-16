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
	void clear() {
		memory = 0;
		empty = true;
	}
	bool is_empty(){
		return empty;
	}
};
#endif
