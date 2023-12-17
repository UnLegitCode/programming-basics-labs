#include <stdio.h>
#include "util.h"

long long countLines(const int value, const int coefficient) {
    long long stringAmount = value;
    long long divider = coefficient;

    while (value / divider) {
        stringAmount += value / divider;
        divider *= coefficient;
    }

    return stringAmount;
}

int binarySearch(const int stringAmount, const int performance_reduction_factor) {
    int left = 0,
        right = stringAmount;

    while (left <= right) {
        int middle = left + ((right - left) >> 1);
        long long countMiddle = countLines(middle, performance_reduction_factor);
        long long countBeforeMiddle = countLines(middle - 1, performance_reduction_factor);

        if (countMiddle >= stringAmount && countBeforeMiddle < stringAmount) {
            return middle;
        }

        if (countMiddle < stringAmount) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int main() {
    int lineAmount, performanceReductionFactor;

    scanf("%d %d", &lineAmount, &performanceReductionFactor);

    long long minRequiredInitialLines = binarySearch(lineAmount, performanceReductionFactor);

    printf("%lld", minRequiredInitialLines);
}