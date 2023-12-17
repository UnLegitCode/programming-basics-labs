#include <stdio.h>
#include "util.h"

int equate(const void* firstNumber, const void* secondNumber) {
    long long first = *((long long*) firstNumber);
    long long second = *((long long*) secondNumber);

    return (first > second) - (first < second);
}

void fillPrefixArray(long long* newArray, const long long* oldArray, const long long length) {
    for (long long i = 1, j = (length >> 1) + 1; j < length; i++, j++) {
        newArray[i] = (oldArray[j] - oldArray[j - 1]) * i + newArray[i - 1];
    }
}

long long binarySearch(const long long* array, const long long length, const long long operationAmount) {
    long long left = 0,
              right = length - 1;

    while (left <= right) {
        const long long middle = left + ((right - left) >> 1);
        const long long middleValue = array[middle];

        if (middleValue <= operationAmount && array[middle + 1] > operationAmount) {
            return middle;
        }

        if (middleValue < operationAmount) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return 0;
}

long long searchMaxMean(const long long prefixArray[], const long long* array, const long long arraySize, const long long operationAmount) {
    long long halfArraySize = arraySize >> 1,
              maxMean;

    if (operationAmount >= prefixArray[halfArraySize]) {
        maxMean = array[arraySize - 1] + (operationAmount - prefixArray[halfArraySize]) / (halfArraySize + 1);
    } else {
        long long prefixIndex = binarySearch(prefixArray, halfArraySize + 1, operationAmount);

        maxMean = array[halfArraySize + prefixIndex] + ((operationAmount - prefixArray[prefixIndex]) / (prefixIndex + 1));
    }

    return maxMean;
}

int main() {
    long long arraySize, operationAmount;

    scanf("%lld %lld", &arraySize, &operationAmount);

    long long* array = scanNumArrayLL(arraySize);

    qsort(array, arraySize, sizeof(long long), equate);

    long long prefixArray[(arraySize >> 1) + 1];

    prefixArray[0] = 0;

    fillPrefixArray(prefixArray, array, arraySize);

    long long maxMean = searchMaxMean(prefixArray, array, arraySize, operationAmount);

    printf("%lld", maxMean);
}