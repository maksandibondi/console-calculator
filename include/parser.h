#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

class Calculator;

class Parser {

	friend Calculator;

	std::pair<std::string, std::string> cur;

	std::string::iterator current;

	std::string::const_iterator end;

	double parseExpression() {

		double left = parseTerm();

		std::string _operator = cur.first;
		if (cur.second == "symbol") {

			double right = parseTerm();

			if (_operator == "+") {
				left += right;
				return left;
			}
			else if (_operator == "-") {
				left -= right;
				return left;
			}
			else if (_operator == "/") {
				if (right == 0) {
					throw std::runtime_error("division by 0");
				}
				left /= right;
				return left;
			}
			else if (_operator == "*") {
				left *= right;
				return left;
			}
		}
		else {
			throw std::runtime_error("Wrong sematics");
		}
	}

	double parseTerm() {

		double left = parseFactor();
		std::string _operator = cur.first;
		if (cur.second == "symbol") {
			// here
			//cur = Lexer::readToken(current, end);
			double right = parseFactor();
			if (_operator == "*") {
				left *= right;
				return left;
			}
			else if (_operator == "/") {
				if (right == 0) {
					throw std::runtime_error("division by 0");
				}
				left /= right;
				return left;
			}
			else if (_operator == "+") {
				left += right;
				return left;

			}
			else if (_operator == "-") {
				left -= right;
				return left;

			}
			else {
				throw std::runtime_error("Wrong semantics");
			}
		}
	}

	double parseFactor() {
		double value;
		if (cur.first == "(" && cur.second == "symbol") {
			// here
			cur = Lexer::readToken(current, end);
			value = parseExpression();
			if (cur.first != ")" || cur.second != "symbol") {
				throw std::runtime_error("wrong parenthesis");
			}
		}
		else {
			// here
			value = parseNumber();

		}
		// here
		//cur = Lexer::readToken(current, end);
		return value;
	}

	double parseNumber() {

			if (cur.second != "number") {
				throw std::runtime_error("wrong semantics");
			}
			else {
				double value = std::stod(cur.first); // substract ascii value
				cur = Lexer::readToken(current, end);
				return value;
			}
	}

public:

	Parser(){}

	double parse(std::string& expression) {
		double value = 0;
		while (1) {
			current = expression.begin();
			end = expression.cend();


			cur = Lexer::readToken(current, end); // first value in a string
			if (cur.second != "end of line") {
				value = parseExpression();
				expression.erase(expression.begin(), current);
				if (expression.begin() != expression.end()) {
					expression.insert(expression.begin(), (*(std::to_string(value)).c_str()));
				}
				else {
					return value;
				}
			}
			else {
				return value;
			}
		}

	}

};

#endif
