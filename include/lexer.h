#ifndef LEXER_H
#define LEXER_H

#include <stdexcept>
#include <exception>
#include <string>
#include <iterator>
#include "expression.h"


class Lexer {
public:
	static std::string readToken(std::string::iterator& current, std::string::const_iterator& end);

};
#endif
