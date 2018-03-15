#include <iostream>
#include "gtest/gtest.h"
#include <algorithm>
#include "lexer.h"
#include "parser.h"
#include "calculator.h"
#include <limits>

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


TEST_F(LexerTest, should_return_0) {
		std::string str = "0";
		std::string::iterator cur = str.begin();
		std::string::const_iterator end = str.end();
		std::string res = Lexer::readToken(cur,end);
		ASSERT_EQ(str, res);
}

TEST_F(LexerTest, should_return_plus) {
		std::string str = "0+2";
		std::string::iterator cur = str.begin();
		std::string::const_iterator end = str.end();
		std::string res = Lexer::readToken(cur,end);
		res = Lexer::readToken(cur,end);
		ASSERT_EQ("+", res);
}


TEST_F(CalculatorTest, should_return_0) {
		Calculator calc;
		std::string str = "0";
		double res = calc.calculate(str);
		ASSERT_EQ(0,res);
}

TEST_F(CalculatorTest, should_return_0_second_test) {
		Calculator calc;
		std::string str = "";
		double res = calc.calculate(str);
		ASSERT_EQ(0,res);
}

TEST_F(CalculatorTest, should_return_0_third_test) {
		Calculator calc;
		std::string str = "0.0";
		double res = calc.calculate(str);
		ASSERT_EQ(0,res);
}


TEST_F(CalculatorTest, should_throw_runtime_error) {
		Calculator calc;
		std::string str = ")";
		ASSERT_THROW(calc.calculate(str), std::runtime_error);
}

TEST_F(CalculatorTest, should_throw_runtime_error_second_test) {
		Calculator calc;
		std::string str = "2+";
		ASSERT_THROW(calc.calculate(str), std::runtime_error);
}

TEST_F(CalculatorTest, should_throw_runtime_error_third_test) {
		Calculator calc;
		std::string str = "*1";
		ASSERT_THROW(calc.calculate(str), std::runtime_error);
}

TEST_F(CalculatorTest, should_return_3) {
		Calculator calc;
		std::string str = "1+2";
		double res = calc.calculate(str);
		ASSERT_EQ(3,res);
}

TEST_F(CalculatorTest, should_return_6) {
		Calculator calc;
		std::string str = "(1+1)*3";
		double res = calc.calculate(str);
		ASSERT_EQ(6,res);
}

TEST_F(CalculatorTest, should_return_6_second_test) {
		Calculator calc;
		std::string str = "((1+1.0))*3";
		double res = calc.calculate(str);
		ASSERT_EQ(6,res);
}

TEST_F(CalculatorTest, should_return_9) {
		Calculator calc;
		std::string str = "(((1.0+2)))*3.0";
		double res = calc.calculate(str);
		ASSERT_EQ(9,res);
}

TEST_F(CalculatorTest, should_return_inf) {
		Calculator calc;
		std::string str = "1/0";
		double res = calc.calculate(str);
		ASSERT_EQ(std::numeric_limits<double>::infinity(),res);
}

TEST_F(CalculatorTest, should_return_2) {
		Calculator calc;
		std::string str = "2/1";
		double res = calc.calculate(str);
		ASSERT_EQ(2,res);
}

TEST_F(CalculatorTest, should_return_4) {
		Calculator calc;
		std::string str = "10/2.5";
		double res = calc.calculate(str);
		ASSERT_EQ(4,res);
}
