#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "parser.h"
#include "utilities.h"
#include <sstream>

class Calculator {
public:
	double calculate(std::string& expression);
};

#endif