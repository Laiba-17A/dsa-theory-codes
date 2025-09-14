#include <iostream>

int main() {
    int number = 42;
    int* ptr = &number; // Declare a pointer and assign the address of 'number'
    int** parptr = &ptr;

    std::cout << "Value of number: " << number << std::endl;
    std::cout << "Address of number: " << &number << std::endl;

    std::cout << "Value of ptr: " << ptr << std::endl;  // Address of 'number'
    std::cout << "Dereferenced value of ptr: " << parptr << std::endl; // Value at the address pointed to by 'ptr'

    return 0;
}

