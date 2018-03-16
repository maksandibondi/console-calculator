#include "calculator.h"

double Calculator::calculate(std::string& expression) {
		double result = Utilities::traverse(Parser::parse(expression));
		memory = result;
		empty = false;
		return result;
}
