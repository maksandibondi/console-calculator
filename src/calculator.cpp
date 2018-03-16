#include "calculator.h"

double Calculator::calculate(std::string& expression) {
		double result = Utilities::traverse(Parser::parse(expression));
		memory = result;
		empty = false;
		return result;
}

void Calculator::clear() {
		memory = 0;
		empty = true;
}

bool Calculator::is_empty(){
		return empty;
}
