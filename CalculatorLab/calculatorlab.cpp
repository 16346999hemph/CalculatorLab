// Anyshya Hemphill
// Assignment 3 - Calculator
// This program will perform calculatory operations for the user including base conversions and arithmetic operations.

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <cctype>
#include <limits>
using namespace std;

// Convert from any base (2, 8, 10, 16) to decimal
int convertToDecimal(const string& number, int base) {
    int decimal = 0;
    int power = 1;

    for (int i = number.length() - 1; i >= 0; --i) {
        char c = toupper(number[i]);
        int digit;

        if (isdigit(c)) digit = c - '0';
        else if (c >= 'A' && c <= 'F') digit = c - 'A' + 10;
        else {
            cerr << "Invalid digit '" << c << "' for base " << base << endl;
            return -1;
        }

        if (digit >= base) {
            cerr << "Digit '" << c << "' not valid in base " << base << endl;
            return -1;
        }

        decimal += digit * power;
        power *= base;
    }

    return decimal;
}

// Convert from decimal to binary
string convertToBinary(int number) {
    if (number == 0) return "0";
    string binary = "";
    while (number > 0) {
        binary = char('0' + (number % 2)) + binary;
        number /= 2;
    }
    return binary;
}

// Convert from decimal to octal
string convertToOctal(int number) {
    if (number == 0) return "0";
    string octal = "";
    while (number > 0) {
        octal = char('0' + (number % 8)) + octal;
        number /= 8;
    }
    return octal;
}

// Convert from decimal to hexadecimal
string convertToHexadecimal(int number) {
    if (number == 0) return "0";
    string hex = "";
    char hexDigits[] = "0123456789ABCDEF";

    while (number > 0) {
        hex = hexDigits[number % 16] + hex;
        number /= 16;
    }
    return hex;
}

// Base conversion menu and loop
int baseConversion() {
    int base = 0;
    string number = "";
    char again = 'y';

    while (again == 'y' || again == 'Y') {
        cout << "\nWelcome to the Number Base Converter!" << endl;
        cout << "You can convert numbers between bases 2, 8, 10, and 16." << endl;

        // Ask for base with input validation
        while (true) {
            cout << "Which base do you want to convert from? (2, 8, 10, 16): ";
            cin >> base;
            if (base == 2 || base == 8 || base == 10 || base == 16) break;
            cout << "Invalid base. Please try again.\n";
        }

        cout << "Enter the number to convert without any spaces: ";
        cin >> number;

        int decimal = convertToDecimal(number, base);
        if (decimal == -1) {
            cout << "Conversion to decimal failed. Please try again." << endl;
            continue;
        }

        cout << "\n=== Conversion Results ===" << endl;
        if (base != 10) cout << "Decimal:     " << decimal << endl;
        if (base != 2)  cout << "Binary:      " << convertToBinary(decimal) << endl;
        if (base != 8)  cout << "Octal:       " << convertToOctal(decimal) << endl;
        if (base != 16) cout << "Hexadecimal: " << convertToHexadecimal(decimal) << endl;

        cout << "\nDo you want to convert another number? (y/n): ";
        cin >> again;
    }

    cout << "Thanks for using the converter. Returning to main menu..." << endl;
    return 0;
}

// Arithmetic operation functions
float add(float num1, float num2) {
    return num1 + num2;
}

float subtract(float num1, float num2) {
    return num1 - num2;
}

float multiply(float num1, float num2) {
    return num1 * num2;
}

float divide(float num1, float num2) {
    if (num2 == 0) {
        cout << "You cannot divide by zero." << endl;
        return 0;
    }
    return num1 / num2;
}

// Menu for arithmetic operations
int performArithmeticOperations() {
    float num1, num2;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    switch (operation) {
    case '+':
        cout << "Result: " << add(num1, num2) << endl;
        break;
    case '-':
        cout << "Result: " << subtract(num1, num2) << endl;
        break;
    case '*':
        cout << "Result: " << multiply(num1, num2) << endl;
        break;
    case '/':
        cout << "Result: " << divide(num1, num2) << endl;
        break;
    default:
        cout << "Invalid operation." << endl;
    }

    // Prompt for another operation
    char anotherOp = 'y';
    cout << "Do you want to perform another operation? (y/n): ";
    cin >> anotherOp;

    if (tolower(anotherOp) == 'y') {
        return performArithmeticOperations();  // Recursive call
    }
    else {
        cout << "Returning to main menu..." << endl;
    }

    return 0;
}

// Menu-driven interface
int main() {
    char choice = 'y';

    do {
        cout << "\n==============================" << endl;
        cout << "BASE CONVERSIONS AND ARITHMETIC CALCULATOR" << endl;
        cout << "1. Base Conversions" << endl;
        cout << "2. Basic Arithmetic Calculator" << endl;
        cout << "E. Exit" << endl;
        cout << "==============================" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (toupper(choice)) {
        case '1':
            baseConversion();
            break;
        case '2':
            performArithmeticOperations();
            break;
        case 'E':
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "ERROR: '" << choice << "' is not a valid option." << endl;
        }

    } while (toupper(choice) != 'E');

    return 0;
}
