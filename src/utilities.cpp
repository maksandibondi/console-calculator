#include "utilities.h"

double Utilities::traverse(std::shared_ptr<Expression> root) {
		return root->eval();
}
