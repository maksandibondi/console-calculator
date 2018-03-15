#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <stack>

class Parser {

	static bool isOperator(const std::string& token);

	static int precedence(const std::string& op);

public:

	static Expression* parse(std::string input);

};

#endif
