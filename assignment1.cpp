#include <iostream>
#include <cmath>

float add(float a, float b) { return a + b; }
// Define similar functions for other operations

int main() {
    float num1, num2;
    char operation;
    std::cout << "Enter a problem to solve (format: a + b): ";
    std::cin >> num1 >> operation >> num2;

    switch (operation) {
        case '+': std::cout << "Result: " << add(num1, num2) << std::endl; break;
        // Add cases for other operators
        default: std::cout << "Unknown operation\n";
    }
    return 0;
}
