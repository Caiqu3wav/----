#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

std::string reverse_letter(const std::string &str) {
    std::string localStr = str;
    std::vector<char> reversedStr;

        while (!localStr.empty()) {
            reversedStr.push_back(localStr.back());
            localStr.pop_back();
        }

        std::string reversedStrAsString{reversedStr.cbegin(), reversedStr.cend()};
        auto rm_numbers = std::remove_if(std::begin(reversedStrAsString), std::end(reversedStrAsString), [](auto c) {
            return !std::isalpha(c);
        });
        reversedStrAsString.erase(rm_numbers, std::end(reversedStrAsString));
        std::cout << "Reversed string: " << reversedStrAsString << std::endl;
        return reversedStrAsString;
}

int main() {
      std::string word = "evil";

        std::cout << (reverse_letter(word));
}

