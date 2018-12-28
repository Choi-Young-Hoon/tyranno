#ifndef __STRING_TREE_HEADER__
#define __STRING_TREE_HEADER__

#include <iostream>

class StringTree {
public:
    explicit StringTree()
	{}
    virtual ~StringTree()
	{}

public:
    void PrintInfo() {
        std::cout << "Hello World" << std::endl;
    }

private:
	
};

#endif
