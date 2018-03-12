#ifndef LEXER_H
#define LEXER_H

#include <stdexcept>
#include <exception>
#include <string>
#include <iterator>


class TYPE {};
class NUMBER : public TYPE {};
class SYMBOL : public TYPE {};

class Lexer {
public:
	static std::pair<char, std::string> readToken(std::string::iterator& current, const std::string::iterator& end) {
		if (current != end) {
			char token = *current;
			if (isdigit(token)) {
				current++;
				return std::pair<char, std::string>(token, "number");
			}
			else if (token == '+' || token == '-' || token == '*' || token == '/') {
				current++;
				return std::pair<char, std::string>(token, "symbol");
			}
			else if (isspace(token)) {
				current++;
				return Lexer::readToken(current, end);
			}
		}
		else {
			return std::pair<char, std::string>(' ',"end of line");
		}
	}
};

#endif
