#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "parser.h"
#include <sstream>

class Calculator {
public:
	double calculate(std::string& expression) {
		Parser _parser;
		return _parser.parse(expression);
	}

};

#endif