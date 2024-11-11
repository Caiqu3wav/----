#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>

std::vector<int> solution(std::vector<int> nums) {
    std::vector<int> sortedNums = nums;
    if (!sortedNums.empty()) {
        std::sort(sortedNums.begin(), sortedNums.end());
        return sortedNums;
    }
    return {};
}