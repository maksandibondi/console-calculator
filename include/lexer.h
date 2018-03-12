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
	static std::pair<std::string, std::string> readToken(std::string::iterator& current, std::string::const_iterator& end) {
		std::string token = "";
		if (current != end) {
			char el = *current;
			if (isdigit(el)) {
				token.push_back(el);
				current++;
				while (isdigit(*(current)) || *(current) == '.') {
					token.push_back(*current);
					current++;
				}
				return std::pair<std::string, std::string>(token, "number");
			}
			else if (el == '+' || el == '-' || el == '*' || el == '/' || el == '(' || el == ')') {
				token.push_back(el);
				current++;
				return std::pair<std::string, std::string>(token, "symbol");
			}
			else if (isspace(el)) {
				current++;
				return readToken(current, end);
			}
		}
		else {
			return std::pair<std::string, std::string>(token,"end of line");
		}
	}
};

#endif
