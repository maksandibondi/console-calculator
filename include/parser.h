#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

class Calculator;

class Parser{

	friend Calculator;

	std::pair<char, std::string> cur;

	std::string::iterator current;

	const std::string::iterator end;

	double parseExpression() {

		double left = parseTerm();

		current++;
		cur = Lexer::readToken(current, end);

		char _operator = cur.first;
		if (cur.second == "symbol") {
			current++;
			cur = Lexer::readToken(current, end);
			double right = parseTerm();

			if (_operator == '+') {
				left += right;
				return left;
			}
			else if (_operator == '-') {
				left -= right;
				return left;
			}
		}
		else {
			throw std::runtime_error("Wrong sematics");
		}
	}

	double parseTerm() {

		double left = parseFactor();
		if (cur.second == "symbol") {
			// here is the problem
			double right = parseFactor();
			if (cur.first == '*') {
				left *= right;
				return left;
			}
			else if (cur.first == '/') {
				if (right == 0) {
					throw std::runtime_error("division by 0");
				}
				left /= right;
				return left;

			}
			else {
				throw std::runtime_error("Wrong semantics");
			}
		}
	}

	double parseFactor() {
		double value;
		if (cur.first == '(' && cur.second == "symbol") {
			cur = Lexer::readToken(current, end);
			value = parseExpression();
			if (cur.first != ')' || cur.second != "symbol") {
				throw std::runtime_error("wrong parenthesis");
			}
		}
		else {
			value = parseNumber();
		}
		return value;

	}

	double parseNumber() {


			if (cur.second != "number") {
				throw std::runtime_error("wrong semantics");
			}
			else {
				double value = cur.first - 48; // substract ascii value
				//cur = Lexer::readToken(current, end);
				return value;
			}
	}

public:

	Parser(std::string& expression) :
		current(expression.begin()),
		end(expression.end()) {

	}

	double parse() {
		cur = Lexer::readToken(current, end);
		if (cur.second != "end of line") {
			return parseExpression();
		}
		else {
			return parseExpression();
		}

	}

};

#endif
