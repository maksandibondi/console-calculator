#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_
#include <memory>
#include <stdexcept>
#include <cmath>

class Expression;

typedef std::shared_ptr<Expression> ptr_expression;

class Expression {
protected:
	Expression() {}
	virtual ~Expression() {}
public:
	virtual double eval() const = 0;
};

class BinaryExpression : public Expression {
protected:
	ptr_expression left;
	ptr_expression right;
public:
	BinaryExpression(ptr_expression left, ptr_expression right) : left(left), right(right) {}
};

class UnaryExpression : public Expression {
protected:
	ptr_expression exp;
public:
	UnaryExpression(ptr_expression exp): exp(exp) {}
};

class NumberExpression : public Expression {
protected:
	const double value;
public:
	NumberExpression(double value) : value(value) {}

	double eval() const {
		return value;
	}
};

class AddExpression: public BinaryExpression {
	//~AddExpression() {}
public:
	AddExpression(ptr_expression left, ptr_expression right) : BinaryExpression(left, right) {}
	double eval() const {
		return left->eval() + right->eval();
	}
};

class MinusExpression : public BinaryExpression {
	//~MinusExpression() {};
public:
	MinusExpression(ptr_expression left, ptr_expression right) : BinaryExpression(left, right) {}
	double eval() const {
		return left->eval() - right->eval();
	}
};

class MultExpression : public BinaryExpression {
	//~MultExpression() {}
public:
	MultExpression(ptr_expression left, ptr_expression right) : BinaryExpression(left, right) {}
	double eval() const {
		return left->eval() * right->eval();
	}
};

class DivExpression : public BinaryExpression {
	//~DivExpression() {}
public:
	DivExpression(ptr_expression left, ptr_expression right) : BinaryExpression(left, right) {}
	double eval() const {
		double rvalue = right->eval();
		if (rvalue == 0) {
			throw std::runtime_error("division by zero");
		}
		return left->eval() / rvalue;
	}
};

/*------------------------*/
// To do
class SqrExpression : public UnaryExpression {
	~SqrExpression() {};
public:
	SqrExpression(ptr_expression exp) : UnaryExpression(exp) {}
	double eval() {
		double result = exp->eval();
		return result*result;
	}
};

class LogExpression : public UnaryExpression {
	~LogExpression() {};
public:
	LogExpression(ptr_expression exp) : UnaryExpression(exp) {}
	double eval() {
		double result = exp->eval();
		return log(result);
	}
};



#endif
