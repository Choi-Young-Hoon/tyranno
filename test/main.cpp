#include <iostream>

#include "gtest/gtest.h"

#include "StringTree.hpp"

TEST(STRTEST, TEST) {
    StringTree strTree;    
}

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
