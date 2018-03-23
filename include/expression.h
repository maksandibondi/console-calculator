#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_
#include <memory>

class Expression;

typedef std::shared_ptr<Expression> ptr_expression;

class Expression {
protected:
	Expression() {}
	virtual ~Expression() {}
public:
	virtual double eval() = 0;
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

class Number : public Expression {
	const double value;
public:
	Number(double value) : value(value) {}

	double eval() const {
		return value;
	}
};

class AddExpression: public BinaryExpression {
	~AddExpression() {}
public:
	double eval() {
		return left->eval() + right->eval();
	}
};

class MinusExpression : public BinaryExpression {
	~MinusExpression() {};
public:
	double eval() {
		return left->eval() - right->eval();
	}
};

class MultExpression : public BinaryExpression {
	~MultExpression() {}
public:
	double eval() {
		return left->eval() * right->eval();
	}
};

class DivExpression : public BinaryExpression {
	~DivExpression() {}
public:
	double eval() {
		return left->eval() / right->eval();
	}
};

/*------------------------*/
// To do
class SqrExpression : public UnaryExpression {
	~SqrExpression() {};
public:
	double eval() {
		double a = exp->eval();
		return a*a;
	}
};

#endif
