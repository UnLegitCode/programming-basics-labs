#include <stdio.h>
#include "util.h"

long long binarySearch(const int array[], const int length) {
    long long goodPairAmount = 0;

    for (int i = 0; i < length - 1; i++) {
        int left = i + 1,
            right = length - 1;

        while (left <= right) {
            int middle = (left + right) >> 1;

            if (array[i] + array[middle] > 0) {
                goodPairAmount += (right - middle + 1);
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
    }

    return goodPairAmount;
}

void fillingDifferenceArray(int* array, const int length) {
    for (int i = 0; i < length; i++) {
        array[i] -= scanInt();
    }
}

int main() {
    int topicAmount = scanInt();
    int* array = scanNumArray(topicAmount);

    fillingDifferenceArray(array, topicAmount);
    sortIntArray(array, topicAmount);

    printf("%lld", binarySearch(array, topicAmount));
}