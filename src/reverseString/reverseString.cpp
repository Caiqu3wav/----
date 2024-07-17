#include <iostream>
#include <vector>

std::string reverse_letter(const std::string &str) {
    std::string localStr = str;
    std::vector<char> reversedStr;

        while (!localStr.empty()) {
            reversedStr.push_back(localStr.back());
            localStr.pop_back();
        }
       std::string reversedStrAsString{reversedStr.cbegin(), reversedStr.cend()};
        std::cout << "Reversed string: " << reversedStrAsString << std::endl;
        return reversedStrAsString;
}

int main() {
      std::string word = "evil";

        std::cout << (reverse_letter(word));
}

