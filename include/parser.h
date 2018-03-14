#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <stack>

class Parser {

static bool isOperator(const std::string& token) {
	if (token == std::string("+") ||
		token == std::string("-") ||
		token == std::string("*") ||
		token == std::string("/")
		) {
		return true;
	}
	return false;
}

static int precedence(const std::string& op) {
	if (op == std::string("(")) return 0;
	if (op == std::string("+") || op == std::string("-")) return 1;
	return 2;
}

public:
	static Expression* parse(std::string input) {
	std::string::iterator cur = input.begin();
	std::string::const_iterator end = input.end();

	std::stack<Expression*> operands;
	std::stack<std::string> operators;

	while (cur != end) {
		std::string token = Lexer::readToken(cur, end);
		if (token == "(") {
			operators.push(token);
		}

		else if (isdigit(*token.c_str())) {
			operands.push(new Number(std::stod(token)));
		}

		else if (isOperator(token)) {

				while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
					const std::string& op = operators.top();
					operators.pop();

					Expression* exp2 = operands.top();
					operands.pop();
					Expression* exp1 = operands.top();
					operands.pop();

					if (token == std::string("+")) {
						operands.push(new AddExpression(exp1, exp2));
					}
					else if (token == std::string("-")) {
						operands.push(new MinusExpression(exp1, exp2));
					}
					else if (token == std::string("*")) {
						operands.push(new MultExpression(exp1, exp2));
					}
					else if (token == std::string("/")) {
						operands.push(new DivExpression(exp1, exp2));
					}
				}

				operators.push(token);
		}

		else if (token == std::string(")")) {
			while (operators.top() != std::string("(")) {
				const std::string& op = operators.top();
				operators.pop();

				Expression* exp2 = operands.top();
				operands.pop();
				Expression* exp1 = operands.top();
				operands.pop();

				if (token == std::string("+")) {
					operands.push(new AddExpression(exp1, exp2));
				}
				else if (token == std::string("-")) {
					operands.push(new MinusExpression(exp1, exp2));
				}
				else if (token == std::string("*")) {
					operands.push(new MultExpression(exp1, exp2));
				}
				else if (token == std::string("/")) {
					operands.push(new DivExpression(exp1, exp2));
				}
			}
			operators.pop();
		}

		else {
			throw std::runtime_error("wrong semantics");
		}
	}

	return operands.top();
}

};

#endif
