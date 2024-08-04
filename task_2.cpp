#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;
    
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    cout << "Enter operation (+, -, *, /): ";
    cin >> op;
    
    switch (op) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Error: Invalid operation!" << endl;
    }
    
    return 0;
}
