#include <iostream>
#include "gtest/gtest.h"
#include <algorithm>
#include "../include/lexer.h"

class LexerTest : public::testing::Test{
				protected:
                void SetUp() {}
                void TearDown() {}
};


TEST_F(LexerTest, should_create_a_lexer) {
		ASSERT_TRUE(1);
}

