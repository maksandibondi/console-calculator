#include "parser.h"

/*
bool Parser::isOperator(const std::string& token) {
	if (token == std::string("+") ||
		token == std::string("-") ||
		token == std::string("*") ||
		token == std::string("/")
		) {
		return true;
	}
	return false;
}

int Parser::precedence(const std::string& op) {
	if (op == std::string("(")) return 0;
	if (op == std::string("+") || op == std::string("-")) return 1;
	return 2;
}
/*
Expression* Parser::parse(std::string input) {
	std::string::iterator cur = input.begin();
	std::string::const_iterator end = input.end();
	if (cur == end) {
		return new Number(0);
	}

	std::stack<Expression*> operands;
	std::stack<std::string> operators;

	while (cur != end) {
		std::string token = Lexer::readToken(cur, end);
		if (token == "(") {
			operators.push(token);
		}

		else if (isdigit(*token.c_str())) {
			operands.push(new Number(std::stod(token)));
		}

		else if (isOperator(token)) {

				while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
					const std::string op = operators.top();
					operators.pop();

					if (operands.empty()) {
						throw std::runtime_error("Parser error: wrong semantics");
					}
					Expression* exp2 = operands.top();
					operands.pop();

					if (operands.empty()) {
						throw std::runtime_error("Parser error: wrong semantics");
					}
					Expression* exp1 = operands.top();
					operands.pop();

					if (op == std::string("+")) {
						operands.push(new AddExpression(exp1, exp2));
					}
					else if (op == std::string("-")) {
						operands.push(new MinusExpression(exp1, exp2));
					}
					else if (op == std::string("*")) {
						operands.push(new MultExpression(exp1, exp2));
					}
					else if (op == std::string("/")) {
						operands.push(new DivExpression(exp1, exp2));
					}
				}

				operators.push(token);
		}

		else if (token == std::string(")")) {
			if (operators.empty()) {
				throw std::runtime_error("Parser error: wrong semantics");
			}
			while (operators.top() != std::string("(")) {
				const std::string op = operators.top();
				operators.pop();

				if (operands.empty()) {
					throw std::runtime_error("Parser error: wrong semantics");
				}
				Expression* exp2 = operands.top();
				operands.pop();
				if (operands.empty()) {
					throw std::runtime_error("Parser error: wrong semantics");
				}
				Expression* exp1 = operands.top();
				operands.pop();

				if (op == std::string("+")) {
					operands.push(new AddExpression(exp1, exp2));
				}
				else if (op == std::string("-")) {
					operands.push(new MinusExpression(exp1, exp2));
				}
				else if (op == std::string("*")) {
					operands.push(new MultExpression(exp1, exp2));
				}
				else if (op == std::string("/")) {
					operands.push(new DivExpression(exp1, exp2));
				}
			}
			/*
			if (!isOperator(operators.top())) {
				throw std::runtime_error("Parser error: wrong semantics");
			}

			operators.pop();
		}

		else {
			throw std::runtime_error("Parser error: wrong semantics");
		}
	}

	while (!operators.empty()) {
		const std::string op = operators.top();
		operators.pop();

		if (operands.empty()) {
			throw std::runtime_error("Parser error: wrong semantics");
		}
		Expression* exp2 = operands.top();
		operands.pop();

		if (operands.empty()) {
			throw std::runtime_error("Parser error: wrong semantics");
		}
		Expression* exp1 = operands.top();
		operands.pop();

		if (op == std::string("+")) {
			operands.push(new AddExpression(exp1, exp2));
		}
		else if (op == std::string("-")) {
			operands.push(new MinusExpression(exp1, exp2));
		}
		else if (op == std::string("*")) {
			operands.push(new MultExpression(exp1, exp2));
		}
		else if (op == std::string("/")) {
			operands.push(new DivExpression(exp1, exp2));
		}
	}

	return operands.top();
}
*/

// to check if this symbol is Num ber or Bracket
std::pair<bool,ptr_expression> Parser::accept(SymbolList sym) {
	std::pair<SymbolList, std::string> token = lex.readToken();
	if (token.first == sym) {
		//lex.next();
		if (sym == Number) {
			return std::pair<bool, ptr_expression>(1, ptr_expression(new NumberExpression(std::stod(token.second))));
		}
		return std::pair<bool, ptr_expression>(1, nullptr);
	}
	return std::pair<bool, ptr_expression>(0, nullptr);
}
// to check if next symbol is good semantically
std::pair<bool, ptr_expression> Parser::expect(SymbolList sym) {
	if (accept(sym).first) {
		return accept(sym);
	}
	else {
		throw std::runtime_error("expect:unexpected symbol");
		return std::pair<bool, ptr_expression>(0, nullptr);
	}
}

void Parser::next() {
	lex.next();
}

ptr_expression Parser::parse() {

	return parseExpression();

}

ptr_expression Parser::parseExpression() {
	if (lex.readToken().first == EndOfLine) {
		return ptr_expression(new NumberExpression(0));
	}
	ptr_expression result;
	if (lex.readToken().first == Plus || lex.readToken().first == Minus) {
		SymbolList op = lex.readToken().first;
		next();
		if (op == Minus) {
			result = ptr_expression(new MinusExpression(ptr_expression(new NumberExpression(0)), parseTerm()));
		}
		else {
			result = parseTerm();
		}

	}
	else {
		result = parseTerm();
	}
	while (lex.readToken().first == Plus || lex.readToken().first == Minus) {
		if (lex.readToken().first == Plus) {
			next();
			result = ptr_expression(new AddExpression(result, parseTerm()));
		}
		else if (lex.readToken().first == Minus) {
			next();
			result = ptr_expression(new MinusExpression(result, parseTerm()));
		}
	}
	return result;

}

ptr_expression Parser::parseTerm() {
	ptr_expression result = parseFactor();

	while (lex.readToken().first == Mult || lex.readToken().first == Div) {
		if (lex.readToken().first == Mult) {
			next();
			result = ptr_expression(new MultExpression(result,parseFactor()));
		} else if (lex.readToken().first == Div) {
			next();
			result = ptr_expression(new DivExpression(result, parseFactor()));
		}
	}
	return result;
}

ptr_expression Parser::parseFactor() {
	std::pair<bool, ptr_expression> token = accept(Number);
	if (token.first) {
		ptr_expression temp = token.second;
		next();
		return temp;
	}

	else if (accept(LBracket).first) {
		next();
		ptr_expression result = parseExpression();
		if (!expect(RBracket).first) {
			throw std::runtime_error("Parser: wrong parentesis");
		}
		next();
		return result;
	}

	else {
		throw std::runtime_error("Parser: syntax error");
	}

}
