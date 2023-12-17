#include <stdio.h>
#include "util.h"

int binarySearchStart(const int* array, const int start, const int end, const double long extraAmount, const int firstNumber) {
    int left = start,
        right = end;

    while (left <= right) {
        int middle = left + ((right - left) >> 1);
        int middleValue = array[middle];

        if (
                isEqual(extraAmount, middleValue + firstNumber) &&
                (!isEqual(extraAmount, array[middle - 1] + firstNumber) || middle == start)
        ) {
            return middle;
        }

        if (!isEqual(extraAmount, firstNumber + middleValue)) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int binarySearchEnd(const int* array, const int start, const int end, const int number) {
    int left = start,
        right = end;

    while (left <= right) {
        int middle = left + ((right - left) >> 1);
        int middleValue = array[middle];

        if (middleValue == number && (array[middle + 1] != number || middle == end)) {
            return middle;
        }

        if (middleValue > number) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    return -1;
}

int searchSecondNum(const int* array, const int start, const int end, const double long extraAmount, const int firstNumber) {
    int startUbdex = binarySearchStart(array, start, end, extraAmount, firstNumber);

    if (startUbdex > -1) {
        return binarySearchEnd(array, startUbdex, end, array[startUbdex]) - startUbdex + 1;
    }

    return 0;
}

long long searchPairs(const int* array, const int length, const double long extraAmount) {
    long long desiredPairs = 0;

    for (int i = 0; i < length - 1; i++) {
        desiredPairs += searchSecondNum(array, i + 1, length - 1, extraAmount, array[i]);
    }

    return desiredPairs;
}

int main() {
    int inputAmount = scanInt();

    for (int i = 0; i < inputAmount; i++) {
        int length = scanInt();
        int* array = scanNumArray(length);
        long long arraySum = sum(array, length);

        double long arithmeticMean = (double long) arraySum / length,
                    extraAmount = arithmeticMean * 2;

        sortIntArray(array, length);

        long long desiredPairs = 0;

        if (isEqual(extraAmount, (long long) extraAmount)) {
            desiredPairs = searchPairs(array, length, extraAmount);
        }

        printf("%lld\n", desiredPairs);
    }
}