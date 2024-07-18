#include <iostream>
#include <vector>
#include <cmath>
#include <string> 

int square_digits(int num) {
    std::string numCopy = std::to_string(num);
    std::string sqrdNumbers;
    
for (char c : numCopy) {
        int digit = c - '0';
        int squaredDigit = digit * digit;
        sqrdNumbers += std::to_string(squaredDigit);
    }

    return std::stoi(sqrdNumbers);
}

int main() {
    int number = 9119;
    square_digits(number);

    return 0;
}