#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

vector<string> buttons = {"1.,?!", "2abc", "3def", "4ghi", "5jkl", "6mno", "7pqrs", "8tuv", "9wxyz", "*'-+=", "0", "#"};

std::pair<int, int> contains_char(char target) {
  if (target == '*') {
        return {9, 0}; // Retorna 9 para '*' (posição 1)
    } else if (target == '\'') {
        return {9, 1}; // Retorna 9 para '\'' (posição 2)
    } else if (target == '-') {
        return {9, 2}; // Retorna 9 para '-' (posição 3)
    } else if (target == '+') {
        return {9, 3}; // Retorna 9 para '+' (posição 4)
    } else if (target == '=') {
        return {9, 4}; // Retorna 9 para '=' (posição 5)
    }
  
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
         if (!pressedButtons.empty() && pressedButtons.back() == "0") {
                pressedButtons.back() += " ";
            } 
                pressedButtons.push_back("0"); // Adiciona um novo espaço
            }         
          else if (isdigit(c) || c == '*') {
    if (!pressedButtons.empty() && pressedButtons.back() == std::string(1, c)) {
              pressedButtons.back() += " ";
            }
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
        if (!pressedButtons.empty() && pressedButtons.back()[0] == to_string(buttonPressed.first)[0]) {
            pressedButtons.back() += " "; // Adiciona um espaço se o último botão é o mesmo
        }
            }
            
            if (buttonPressed.first != -1) {
                // Adiciona a sequência do botão
                pressedButtons.push_back(to_string(buttonPressed.first));
                for (int i = 2; i < buttonPressed.second; ++i) {
                    pressedButtons.back() += to_string(buttonPressed.first);
                }
            }
        }  else if (buttons[9].find(c) != std::string::npos) {
          auto buttonPressed = contains_char(c);
          if (buttonPressed.first != -1) {
               char symbolFirstChar = buttons[buttonPressed.first][0];

               if (!pressedButtons.empty() && pressedButtons.back() == "*") {
            pressedButtons.back() += " "; // Adiciona um espaço
        }

              for (int i = 0; i < buttonPressed.second; ++i) {
            pressedButtons.push_back(string(1, symbolFirstChar)); // Adiciona o caractere correspondente
        }
            }
        }
         else {
    // Adiciona a sequência para caracteres especiais
    auto buttonPressed = contains_char(c);
         if (c == '#') {
        pressedButtons.back() += "#";
        pressedButtons.back() += "-";
      } else {
           
           
    if (buttonPressed.first != -1) {
      
      
      if (!pressedButtons.empty() && pressedButtons.back()[1] != '-' && pressedButtons.back()[0] == to_string(buttonPressed.first)[0]) {
            pressedButtons.push_back(" "); // Adiciona um espaço antes de adicionar o novo botão
        }
       
        // Adiciona o número do botão
        pressedButtons.push_back(to_string(buttonPressed.first));

        // Adiciona a sequência de pressionamentos para o botão
        for (int i = 2; i < buttonPressed.second; ++i) {
            pressedButtons.back() += to_string(buttonPressed.first);
        }
    }
}

        
        if (pressedButtons.size() > 1 && isalpha(c) &&
            pressedButtons.back()[0] == pressedButtons[pressedButtons.size() - 2][0]) {
            pressedButtons.insert(pressedButtons.end() - 1, " "); // Insere um espaço antes do último botão
        }
      }
    }

    // Cria a string final de teclas pressionadas
    string result;
    for (const string& str : pressedButtons) {
        result += str; // Adiciona um espaço entre as teclas pressionadas
    }

    
    return result;
}

int main() {
string message = "A--b==C";
      cout << send_message(message);
    return 0;
}