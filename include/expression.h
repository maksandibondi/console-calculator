#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_


class Expression {
protected:
	virtual ~Expression() = 0;
};

class BinaryExpression : public Expression {
protected:
	Expression* left;
	Expression* right;
	BinaryExpression(Expression* left, Expression* right) : left(left), right(right){}
};

class UnaryExpression : public Expression {
};

class AddExpression: public BinaryExpression {
public:
	AddExpression(Expression* left, Expression* right): BinaryExpression(left,right) {}
	~AddExpression(){
	};
};

class MinusExpression : public BinaryExpression {
public:
	MinusExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}
	~MinusExpression() {};
};

class MultExpression : public BinaryExpression {
public:
	MultExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}
	~MultExpression() {};
};

class DivExpression : public BinaryExpression {
public:
	DivExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}
	~DivExpression() {};
};

class Number : public UnaryExpression {
public:
	double value;
	Number(double value): value(value) {}
	~Number(){}
};

#endif
