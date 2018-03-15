#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_

class Expression {
protected:
	Expression() {}
	Expression(double value) : value(value) {} // Number case
	Expression(Expression* left) : left(left) {} // Unary case
	Expression(Expression* left, Expression* right): left(left), right(right) {} // Binary case
	double value;
	Expression* left;
	Expression* right;
	virtual ~Expression(){
		delete left;
		delete right;
	}
public:
	virtual double getValue() = 0;
};

class BinaryExpression : public Expression {
protected:
	BinaryExpression(Expression* left, Expression* right) : Expression(left, right){}
};

class UnaryExpression : public Expression {
protected:
	UnaryExpression(double value): Expression(value){}
	UnaryExpression(Expression* left) : Expression(left) {}
};

class AddExpression: public BinaryExpression {
public:
	AddExpression(Expression* left, Expression* right): BinaryExpression(left,right) {}
	~AddExpression(){};
	double getValue() {
		return left->getValue() + right->getValue();
	}
};

class MinusExpression : public BinaryExpression {
public:
	MinusExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}
	~MinusExpression() {};
	double getValue() {
		return left->getValue() - right->getValue();
	}
};

class MultExpression : public BinaryExpression {
public:
	MultExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}
	~MultExpression() {};
	double getValue() {
		return left->getValue() * right->getValue();
	}
};

class DivExpression : public BinaryExpression {
public:
	DivExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}
	~DivExpression() {};
	double getValue() {
		return left->getValue() / right->getValue();
	}
};

class Number : public UnaryExpression {
public:
	Number(double value): UnaryExpression(value) {}
	~Number(){}
	double getValue() {
		return value;
	}
};

#endif
