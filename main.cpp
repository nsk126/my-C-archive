#include <iostream>
#include "Matrix.h"

int main(void)
{
    int a = 0;

    matrix::update(&a);
    std::cout << a << std::endl;

    return 0;
}