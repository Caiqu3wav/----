#include <string>
#include <vector>
#include <iostream>

std::string likes(const std::vector<std::string> &names) {
    std::string result;
  
    switch(names.size()) {
        case 0 : 
        result = "no one likes this";
        break;
        case 1 : 
        result = names[0] + " likes this";
        break;
        case 2 : 
        result = names[0] + " and " + names[1] + " like this";
        break;
        case 3 : 
        result = names[0] + ", " + names[1] + " and " + names[2] + " like this";
        break;
        default : 
        result = names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
        break;
          
    }
      
  
    return result; // Do your magic!
}

int main() {
    std::vector<std::string> names = {"Gabriel", "Caique"};
    std::cout << likes(names);
    return 0;
}