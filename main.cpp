#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

// Struct to group variables for the calculator
struct Calculator {
    string problem;      // Problem entered by the user
    char repeat;         // Choice to repeat the program
};

// Function to display intermediate steps
void displayStep(const string& step) {
    cout << step << endl;
}

// Function to evaluate a simple arithmetic problem
float evaluate(string& problem);

// Function to handle parenthesis
string handleParenthesis(string& problem);

// Function to handle exponentiation
string handleExponents(string& problem);

// Function to handle multiplication and division
string handleMulDiv(string& problem);

// Function to handle addition and subtraction
string handleAddSub(string& problem);

int main() {
    Calculator calc;

    do {
        // Input problem
        cout << "Enter a problem to solve: ";
        getline(cin, calc.problem);

        // Evaluate the problem
        float result = evaluate(calc.problem);

        // Display the final answer
        cout << "The answer to this problem is " << result << ".\n";

        // Ask if the user wants to solve another problem
        cout << "Would you like to solve another problem? (Y/N): ";
        cin >> calc.repeat;
        cin.ignore(); // To consume leftover newline
    } while (calc.repeat == 'Y' || calc.repeat == 'y');

    cout << "Thank you for using this calculator!\n";
    return 0;
}

// Function to evaluate the entire expression
float evaluate(string& problem) {
    displayStep(problem);

    // Solve parenthesis
    problem = handleParenthesis(problem);
    displayStep(problem);

    // Solve exponents
    problem = handleExponents(problem);
    displayStep(problem);

    // Solve multiplication and division
    problem = handleMulDiv(problem);
    displayStep(problem);

    // Solve addition and subtraction
    problem = handleAddSub(problem);
    displayStep(problem);

    // Convert the final result back to float and return
    return stof(problem);
}

// Function to handle parenthesis
string handleParenthesis(string& problem) {
    size_t openIndex, closeIndex;

    // Find and process innermost parenthesis
    while ((openIndex = problem.find_last_of('(')) != string::npos) {
        closeIndex = problem.find(')', openIndex);
        string inner = problem.substr(openIndex + 1, closeIndex - openIndex - 1);

        // Evaluate the content inside parenthesis
        float innerResult = evaluate(inner);

        // Replace the parenthesis with the result
        problem.replace(openIndex, closeIndex - openIndex + 1, to_string(innerResult));
    }

    return problem;
}

// Function to handle exponents
string handleExponents(string& problem) {
    size_t index;
    while ((index = problem.find('^')) != string::npos) {
        size_t leftStart = problem.find_last_of("+-*/(", index);
        size_t rightEnd = problem.find_first_of("+-*/) ", index);

        float base = stof(problem.substr(leftStart + 1, index - leftStart - 1));
        float exp = stof(problem.substr(index + 1, rightEnd - index - 1));

        // Perform the exponentiation
        float result = pow(base, exp);

        // Replace the base^exp with the result
        problem.replace(leftStart + 1, rightEnd - leftStart - 1, to_string(result));
    }

    return problem;
}

// Function to handle multiplication and division
string handleMulDiv(string& problem) {
    size_t index;
    while ((index = problem.find_first_of("*/")) != string::npos) {
        size_t leftStart = problem.find_last_of("+-*/(", index);
        size_t rightEnd = problem.find_first_of("+-*/) ", index);

        float left = stof(problem.substr(leftStart + 1, index - leftStart - 1));
        float right = stof(problem.substr(index + 1, rightEnd - index - 1));

        // Perform the operation
        float result = (problem[index] == '*') ? left * right : left / right;

        // Replace the left*right or left/right with the result
        problem.replace(leftStart + 1, rightEnd - leftStart - 1, to_string(result));
    }

    return problem;
}

// Function to handle addition and subtraction
string handleAddSub(string& problem) {
    size_t index;
    while ((index = problem.find_first_of("+-", 1)) != string::npos) {
        size_t leftStart = problem.find_last_of("+-*/(", index);
        size_t rightEnd = problem.find_first_of("+-*/) ", index);

        float left = stof(problem.substr(leftStart + 1, index - leftStart - 1));
        float right = stof(problem.substr(index + 1, rightEnd - index - 1));

        // Perform the operation
        float result = (problem[index] == '+') ? left + right : left - right;

        // Replace the left+right or left-right with the result
        problem.replace(leftStart + 1, rightEnd - leftStart - 1, to_string(result));
    }

    return problem;
}
