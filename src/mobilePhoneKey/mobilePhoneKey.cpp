#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

vector<string> buttons = {"1.,?!", "2abc", "3def", "4ghi", "5jkl", "6mno", "7pqrs", "8tuv", "9wxyz", "*'-+=", "0", "#"};

std::pair<int, int> contains_char(char target) {
    for (size_t i = 0; i < buttons.size(); ++i) {
        const string& digit = buttons[i];
        size_t pos = digit.find(target);
        if (pos != string::npos) {
            return {static_cast<int>(i + 1), static_cast<int>(pos + 1)}; // Retorna o número do botão e a posição do caractere
        }
    }
    return {-1, -1};
}

string send_message(const string& message) {
    vector<string> pressedButtons;
    bool isUpper = false;

    for (char c : message) {

        if (c == ' ') {
            pressedButtons.push_back("0");
        } else if (isdigit(c)) {
            pressedButtons.push_back(std::string(1, c) + "-"); // Para números, mantém o "-"
        } else if (isalpha(c)) {
            // Verifica se a letra é maiúscula
            bool isCurrentUpper = isupper(c);
            if (isCurrentUpper != isUpper) {
                pressedButtons.push_back("#"); // Alterna entre maiúsculas e minúsculas
                isUpper = isCurrentUpper; // Atualiza o estado
            }

            auto buttonPressed = contains_char(tolower(c));
            if (buttonPressed.first != -1) {
                // Adiciona a sequência do botão
                pressedButtons.push_back(to_string(buttonPressed.first));
                for (int i = 2; i < buttonPressed.second; ++i) {
                    pressedButtons.back() += to_string(buttonPressed.first);
                }
            }
        } else if (c == '-' || c == '+' || c == '=') {
            pressedButtons.push_back("*");
        }
         else {
            // Adiciona a sequência para caracteres especiais
            auto buttonPressed = contains_char(c);
            if (buttonPressed.first != -1) {
                pressedButtons.push_back(to_string(buttonPressed.first));
                for (int i = 2; i < buttonPressed.second; ++i) {
                    pressedButtons.back() += to_string(buttonPressed.first);
                }
            }
        }
        
        // Adiciona um espaço se a próxima tecla é a mesma
        if (pressedButtons.size() > 1 && isalpha(c) &&
            pressedButtons.back()[0] == pressedButtons[pressedButtons.size() - 2][0]) {
            pressedButtons.insert(pressedButtons.end() - 1, " "); // Insere um espaço antes do último botão
        }
    }

    // Cria a string final de teclas pressionadas
    string result;
    for (const string& str : pressedButtons) {
        result += str;
    }
    return result;
}

int main() {
string message = "Heyy";
      cout << send_message(message);
    return 0;
}