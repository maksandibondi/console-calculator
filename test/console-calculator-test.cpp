#include <iostream>
#include "gtest/gtest.h"
#include <algorithm>
#include "../include/lexer.h"
#include "parser.h"
#include "calculator.h"

class LexerTest : public::testing::Test{
				protected:
                void SetUp() {}
                void TearDown() {}
};

class CalculatorTest : public::testing::Test{
				protected:
                void SetUp() {}
                void TearDown() {}
};


TEST_F(LexerTest, should_create_a_lexer) {
		ASSERT_TRUE(1);
}


TEST_F(CalculatorTest, should_return_0) {
		Calculator calc;
		std::string str = "1+2";
		double res = calc.calculate(str);
		ASSERT_EQ(3,res);
}

