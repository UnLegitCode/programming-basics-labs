#include <stdio.h>
#include <stdbool.h>
#include "util.h"

void fillPrefixArray(const long long *source, long long *destination, const int size) {
    for (int i = 1; i < size; i++) {
        destination[i] = source[i] + destination[i - 1];
    }
}

long long maxDifference(const long long *array, const int size) {
    long long max = array[0];

    for (int i = 1; i < size; ++i) {
        max = maxLL(max, array[i] - array[i - 1]);
    }

    return max;
}

bool isMaxSum(const long long *array, const int size, const int intervalAmount, const long long maxSum) {
    long long left = 0;
    int i = 0,
        interval = 0;

    while ((i < size) && (interval < intervalAmount)) {
        if ((array[i] - left) > maxSum) {
            left = (i > 0) ? array[i - 1] : 0;
            interval++;
        }
        i++;
    }

    return (i == size) && (interval < intervalAmount);
}

long long findMinMaxSum(const long long *array, const int size, const int intervalsTotal) {
    long long left = maxDifference(array, size) - 1,
              right = array[size - 1] + 1;

    while ((left < right) - 1) {
        const long long middle = left + ((right - left) >> 1);

        if (isMaxSum(array, size, intervalsTotal, middle)) {
            right = middle;
        } else {
            left = middle;
        }
    }

    return right;
}

int main() {
    int arraySize, intervalAmount;

    scanf("%d %d", &arraySize, &intervalAmount);

    long long* numbers = scanNumArrayLL(arraySize);

    fillPrefixArray(numbers, numbers, arraySize);

    printf("%lld\n", findMinMaxSum(numbers, arraySize, intervalAmount));
}