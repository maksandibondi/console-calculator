#include "lexer.h"

void Lexer::next() {
	current = _next;
}

void Lexer::prev() {
	--current;
}

std::pair<bool, std::string> Lexer::readNumber(std::string::iterator& cur, std::string token) {

	if (cur != begin) {
		if (*cur == '-' && isdigit(*(cur + 1)) && !isdigit(*(cur - 1))) {
			token.push_back(*cur);
			_next++;

			if (isdigit(*_next)) {
				token.push_back(*_next);
				_next++;
				if (_next != end) {
					while (isdigit(*(_next)) || *(_next) == '.') {
						token.push_back(*_next);
						_next++;
						if (_next == end) break;
					}
				}
				return std::pair<bool, std::string>(true, token);
			}

		}
	}
	else {
		if (*cur == '-' && isdigit(*(cur + 1))) {
			token.push_back(*cur);
			_next++;

			if (isdigit(*_next)) {
				token.push_back(*_next);
				_next++;
				if (_next != end) {
					while (isdigit(*(_next)) || *(_next) == '.') {
						token.push_back(*_next);
						_next++;
						if (_next == end) break;
					}
				}
				return std::pair<bool, std::string>(true, token);
			}

		}
	}

	if (isdigit(*cur)) {
		token.push_back(*cur);
		_next++;
		if (_next != end) {
			while (isdigit(*(_next)) || *(_next) == '.') {
				token.push_back(*_next);
				_next++;
				if (_next == end) break;
			}
		}
		return std::pair<bool, std::string>(true, token);
	}

	else {
		return std::pair<bool, std::string>(false, token);
	}
}

std::pair<bool, std::string> Lexer::readPlus(std::string::iterator& cur, std::string token) {
	if (*cur == '+') {
		token.push_back(*cur);
		_next++;
		return std::pair<bool, std::string>(true, token);
	}
	else {
		return std::pair<bool, std::string>(false, token);
	}
}

std::pair<bool, std::string> Lexer::readMult(std::string::iterator& cur, std::string token) {
	if (*cur == '*') {
		token.push_back(*cur);
		_next++;
		return std::pair<bool, std::string>(true, token);
	}
	else {
		return std::pair<bool, std::string>(false, token);
	}
}

std::pair<bool, std::string> Lexer::readDiv(std::string::iterator& cur, std::string token) {
	if (*cur == '/') {
		token.push_back(*cur);
		_next++;
		return std::pair<bool, std::string>(true, token);
	}
	else {
		return std::pair<bool, std::string>(false, token);
	}
}

std::pair<bool, std::string> Lexer::readMinus(std::string::iterator& cur, std::string token) {
	if (*cur == '-') {
		token.push_back(*cur);
		_next++;
		return std::pair<bool, std::string>(true, token);
	}
	else {
		return std::pair<bool, std::string>(false, token);
	}
}

std::pair<bool, std::string> Lexer::readLBracket(std::string::iterator& cur, std::string token) {
	if (*cur == '(') {
		token.push_back(*cur);
		_next++;
		return std::pair<bool, std::string>(true, token);
	}
	else {
		return std::pair<bool, std::string>(false, token);
	}
}

std::pair<bool, std::string> Lexer::readRBracket(std::string::iterator& cur, std::string token) {
	if (*cur == ')') {
		token.push_back(*cur);
		_next++;
		return std::pair<bool, std::string>(true, token);
	}
	else {
		return std::pair<bool, std::string>(false, token);
	}
}

std::pair<bool, std::string> Lexer::readSpace(std::string::iterator& cur, std::string token) {
	if (isspace(*cur)) {
		_next++;
		next(); // sets current to next
		return std::pair<bool, std::string>(true, token);
	}
}


std::pair<SymbolList, std::string> Lexer::readToken() {

		_next = current;

		std::string token = "";
		if (current != end) {

			std::pair<bool, std::string> currentToken;

			currentToken = readNumber(current, token);
			if (currentToken.first == true) {
				return std::pair<SymbolList, std::string>(Number, currentToken.second);
			}

			currentToken = readPlus(current, token);
			if (currentToken.first == true) {
				return std::pair<SymbolList, std::string>(Plus, currentToken.second);
			}

			currentToken = readMinus(current, token);
			if (currentToken.first == true) {
				return std::pair<SymbolList, std::string>(Minus, currentToken.second);
			}

			currentToken = readMult(current, token);
			if (currentToken.first == true) {
				return std::pair<SymbolList, std::string>(Mult, currentToken.second);
			}

			currentToken = readDiv(current, token);
			if (currentToken.first == true) {
				return std::pair<SymbolList, std::string>(Div, currentToken.second);
			}

			currentToken = readLBracket(current, token);
			if (currentToken.first == true) {
				return std::pair<SymbolList, std::string>(LBracket, currentToken.second);
			}

			currentToken = readRBracket(current, token);
			if (currentToken.first == true) {
				return std::pair<SymbolList, std::string>(RBracket, currentToken.second);
			}

			currentToken = readSpace(current, token);
			if (currentToken.first == true) {
				return readToken();
			}

			throw std::runtime_error("Lexer error: wrong syntax");


		}
		else {

			return std::pair<SymbolList, std::string>(EndOfLine, token);

		}
}
