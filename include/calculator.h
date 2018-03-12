#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "parser.h"
#include <sstream>

class Calculator {
public:
	double calculate(std::string& expression) {
		Parser _parser(expression);
		return _parser.parse();
	}

};

#endif