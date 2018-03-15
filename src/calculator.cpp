#include "../include/calculator.h"

double Calculator::calculate(std::string& expression) {
		return Utilities::traverse(Parser::parse(expression));
}

