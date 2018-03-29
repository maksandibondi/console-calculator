#ifndef _UTILITIES_H
#define _UTILITIES_H
#include "expression.h"

class Utilities {
public:
	static double traverse(std::shared_ptr<Expression> root);
};

#endif
