#include <stdio.h>
#include "util.h"

int sortAroundSupport(long long array[], const int start, const int end) {
    long long support = array[end];
    int support_index = start;

    for (int i = start; i < end; i++) {
        if (array[i] <= support) {
            swapll(&array[i], &array[support_index]);
            support_index++;
        }
    }

    swapll(&array[support_index], &array[end]);

    return support_index;
}

void sort(long long array[], const int start, const int end) {
    if (start >= end) {
        return;
    }

    int support = sortAroundSupport(array, start, end);

    sort(array, start, support - 1);
    sort(array, support + 1, end);
}

long long calculateHeight(const long long array[], const int length) {
    long long destination[length];

    copyOfRange(array, destination, 0, length - 1);
    sort(destination, 0, length - 1);

    long long height = 0;

    for (int i = length - 1; i > -1; i -= 2) {
        height += destination[i];
    }

    return height;
}

int binarySearch(const long long* array, const int length, const int height) {
    int left = 0,
        right = length;

    while (left <= right) {
        int middle = left + ((right - left) >> 1);

        if (middle == right) {
            return middle;
        }

        long long need_height_for_middle = calculateHeight(array, middle);
        long long need_height_for_next_number = calculateHeight(array, middle + 1);

        if (need_height_for_middle <= height && need_height_for_next_number > height) {
            return middle;
        }

        if (need_height_for_middle <= height) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return 0;
}

int main() {
    int bottleAmount = scanInt();

    printf("%d", binarySearch(
            scanNumArrayLL(bottleAmount),
            bottleAmount,
            scanInt()
    ));
}