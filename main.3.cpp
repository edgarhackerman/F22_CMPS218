#include <iostream>
#include <string>
#include <cmath>
#include <iomanip> // For formatting BMI output
using namespace std;

// Struct to group person details
struct Person {
    string name;
    int age;
    string gender;
    int heightFeet;
    int heightInches;
    float weight;
    float BMI;
};

// Function to calculate BMI
float calculateBMI(float weight, int totalInches) {
    return (703 * weight) / (totalInches * totalInches);
}

// Function to determine BMI status
string determineBMIStatus(float BMI) {
    if (BMI < 18.5) return "Underweight";
    else if (BMI >= 18.5 && BMI < 24.9) return "Normal weight";
    else if (BMI >= 25 && BMI < 29.9) return "Overweight";
    else return "Obesity";
}

int main() {
    Person person;

    // Collect user input
    cout << "Please enter your name: ";
    getline(cin, person.name);

    cout << "Please enter your age: ";
    cin >> person.age;

    cout << "Please enter your gender (male/female): ";
    cin >> person.gender;

    cout << "Please enter your height in feet: ";
    cin >> person.heightFeet;

    cout << "Please enter your height in inches: ";
    cin >> person.heightInches;

    cout << "Please enter your weight in pounds: ";
    cin >> person.weight;

    // Calculate total height in inches
    int totalInches = (person.heightFeet * 12) + person.heightInches;

    // Calculate BMI
    person.BMI = calculateBMI(person.weight, totalInches);

    // Determine BMI status
    string BMIStatus = determineBMIStatus(person.BMI);

    // Display results
    cout << fixed << setprecision(1); // Format BMI to 1 decimal place
    cout << "\nHi " << person.name << ",\n";
    cout << "You are a " << person.gender << ". You are " << person.age << " years old.\n";
    cout << "You are currently " << person.heightFeet << "' " << person.heightInches 
         << "\" and you currently weigh " << person.weight << " pounds.\n";
    cout << "Your BMI is " << person.BMI << ", which is " << BMIStatus << ".\n";
    cout << "Thank you for using the BMI Calculator!\n";

    return 0;
}
