#include <iostream>
#include <limits>

int main(){

    double num1 = 0, num2 = 0;
    char op;

    while(true){
        std::cout << "Enter number1: ";
        std::cin >> num1;
        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input! Please enter valid numbers: ";
            continue;
        }else{
            break;
        }
    }

    while(true){
        std::cout << "Enter number2: ";
        std::cin >> num2;
        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input! Please enter valid numbers: ";
            continue;
        }else{
            break;
        }
    }

    while(true){
        std::cout << "Enter operator (+, -, *, /): ";
        std::cin >> op;
        if(op == '+' || op == '-' || op == '*' || op == '/'){
            break;
        }else{
            std::cout << "Invalid operator! Please enter a valid operator: ";
            continue;
        }
    }

    switch(op) {
        case '+':
            std::cout << num1 << " + " << num2 << " = " << (num1 + num2) << std::endl;
            break;
        case '-':
            std::cout << num1 << " - " << num2 << " = " << (num1 - num2) << std::endl;
            break;
        case '*':
            std::cout << num1 << " * " << num2 << " = " << (num1 * num2) << std::endl;
            break;
        case '/':
            if(num2 != 0)
                std::cout << num1 << " / " << num2 << " = " << (num1 / num2) << std::endl;
            else
                std::cout << "Error: Division by zero!" << std::endl;
            break;
    }

    return 0;

}
