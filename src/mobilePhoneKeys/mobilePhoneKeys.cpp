#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

  vector<string> buttons = {"1.,?!", "2abc", "3def", "4ghi", "5jkl", "6mno", "7pqrs", "8tuv", "9wxyz", "*'-+=", "0", "#"};

string mobilePhoneKeys(const string& message) {
    vector<string> pressedButtons;
    string result;

  for (char c : message) {
    if(c == ' ') {
        pressedButtons.push_back("0");
    } else if(isdigit(c)) {
        pressedButtons.push_back(std::string(1, c));
    } else if (isalpha(c)) {

    }
  }

  for (const string& str : pressedButtons){
      result += str;
  }

    cout << "The pressed buttons for the message is: " << result;
    return result;
}


std::pair<int, char> contains_char(const std::vector<std::string>& digits, char target) {
    int foundIndex = -1;
    string firstDigit;

    for (size_t i = 0; i < digits.size(); ++i) {
      const string& digit = digits[i];
        for (char c : digit){
        if (c == target) {
          if (foundIndex == -1) {
            size_t pos = digit.find(target);
            foundIndex = static_cast<int>(pos);
            firstDigit = digit;
            }
            }
        }
    }

if (foundIndex != -1) {
        std::cout << "First character of the string where the target is found: " << firstDigit[0] << std::endl;
                std::cout << "Index: " << foundIndex << std::endl;
    }


    return {foundIndex, firstDigit[0]};
    }


int main() {
    char message = 'a';
    contains_char(buttons, message);
    return 0;
}