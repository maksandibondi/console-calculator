#include "../include/lexer.h"


std::string Lexer::readToken(std::string::iterator& current, std::string::const_iterator& end) {
		std::string token = "";
		if (current != end) {
			char el = *current;
			if (isdigit(el)) {
				token.push_back(el);
				current++;
				if (current != end) {
					while (isdigit(*(current)) || *(current) == '.') {
						token.push_back(*current);
						current++;
					}
				}
				return token;
			}
			else if (el == '+' || el == '-' || el == '*' || el == '/' || el == '(' || el == ')') {
				token.push_back(el);
				current++;
				return token;
			}
			else if (isspace(el)) {
				current++;
				return readToken(current, end);
			}
		}
		else {
			return std::string("end of line");
		}
}
