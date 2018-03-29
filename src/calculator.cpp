#include "calculator.h"

double Calculator::calculate(std::string& expression) {
		Lexer lex(expression);
		Parser parser(lex);
		ptr_expression ast = parser.parse();
		double result = Utilities::traverse(ast);
		memory = result;
		empty = false;
		return result;
}

void Calculator::clear() {
		memory = 0;
		empty = true;
	}

bool Calculator::is_empty() {
		return empty;
}

