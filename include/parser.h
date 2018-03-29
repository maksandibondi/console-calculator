#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <stack>
typedef std::shared_ptr<Expression> ptr_expression;

class Parser {

	Lexer& lex;

	std::stack<ptr_expression> operands;

	std::stack<SymbolList> operators;

	std::pair<bool, ptr_expression> accept(SymbolList sym);

	std::pair<bool, ptr_expression> expect(SymbolList sym);

	void next();

	ptr_expression parseExpression();

	ptr_expression parseTerm();

	ptr_expression parseFactor();

public:

	Parser(Lexer& lex): lex(lex){}

	ptr_expression parse();

};

#endif
