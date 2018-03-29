#ifndef LEXER_H
#define LEXER_H

#include <stdexcept>
#include <exception>
#include <string>
#include <iterator>
#include "expression.h"

typedef enum { Number, LBracket, RBracket, Plus, Minus, Mult, Div, EndOfLine } SymbolList;


class Lexer {
	std::string str;
	std::string::iterator current;
	std::string::iterator _next;
	std::string::const_iterator end;
	std::string::const_iterator begin;

	std::pair<bool, std::string> readNumber(std::string::iterator& cur, std::string token);
	std::pair<bool, std::string> readMinus(std::string::iterator& cur, std::string token);
	std::pair<bool, std::string> readPlus(std::string::iterator& cur, std::string token);
	std::pair<bool, std::string> readMult(std::string::iterator& cur, std::string token);
	std::pair<bool, std::string> readDiv(std::string::iterator& cur, std::string token);
	std::pair<bool, std::string> readLBracket(std::string::iterator& cur, std::string token);
	std::pair<bool, std::string> readRBracket(std::string::iterator& cur, std::string token);
	std::pair<bool, std::string> readSpace(std::string::iterator& cur, std::string token);

public:
	Lexer(std::string& str): str(str), begin(str.begin()), current(str.begin()), end(str.cend()), _next(current) {}
	std::pair<SymbolList, std::string> readToken();

	void next();
	void prev();

};


#endif
