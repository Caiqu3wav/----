#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

std::string reverse_words(std::string str)
{
    int n = str.length();

    int start = 0;

    for (int end = 0; end < n; ++end){
        if (str[end] == ' ' || end == n - 1) {

            if (end == n - 1) {
                end++;
            }
            std::reverse(str.begin() + start, 
            str.begin() + end);
          start = end + 1;
        }
    }
  return str;
}