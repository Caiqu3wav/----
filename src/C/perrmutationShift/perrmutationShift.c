#include <stddef.h>
#include <stdlib.h>

int permutation_shift(size_t length, const int array[length]) {
    int* difference = (int*)malloc(length * sizeof(int));
    if (difference == NULL) {
        return -1;
    }

    for (size_t i = 0; i < length; i++) {
        difference[i] = array[i] - (int)i;
    }

    int max_shift = difference[0];
    int min_shift = difference[0];
    for (size_t i = 1; i < length; i++) {
        if (difference[i] > max_shift) {
            max_shift = difference[i];
        }
        if (difference[i] < min_shift) {
            min_shift = difference[i];
        }
    }

    int result = max_shift - min_shift;

    free(difference);

    return result;
}