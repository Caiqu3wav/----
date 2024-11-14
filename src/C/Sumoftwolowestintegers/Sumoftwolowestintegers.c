#include <stddef.h>
#include <limits.h>
#include <stdio.h>

long sum_two_smallest_numbers(size_t n, const int *numbers) {
    int minNumbers[2] = {INT_MAX, INT_MAX};
    size_t lastMin = -1;

    for (size_t i = 0; i < n; i++) {
        if (numbers[i] < minNumbers[0]) {
            minNumbers[0] = numbers[i];
            lastMin = i;
        }
    }

    for (size_t i = 0; i < n; i++) {
        if (i != lastMin && numbers[i] < minNumbers[1]) {
            minNumbers[1] = numbers[i];
        }
    }

    return (long)minNumbers[0] + minNumbers[1];
}

int main() {
    int numbers[] = {5, 8, 12, 19, 22};

    printf("%ld\n", sum_two_smallest_numbers(5, numbers));
    return 0;
}