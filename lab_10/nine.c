#include <stdio.h>
#include "util.h"

int binarySearch(const long long array[], const int length, const long long free_minutes) {
    int max_books = 0;

    for (int i = 0; i < length; i++) {
        int left = i,
            right = length;
        long long start_sum = array[i];

        while (left <= right) {
            int middle = left + ((right - left) >> 1);
            long long requiredSecondsForMiddle = array[middle] - start_sum,
                      requiredSecondsForAfter = array[middle + 1] - start_sum;

            if (requiredSecondsForMiddle <= free_minutes && requiredSecondsForAfter > free_minutes) {
                max_books = min(max_books, middle - i);

                break;
            } else if (requiredSecondsForMiddle < free_minutes) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
    }

    return max_books;
}

int main() {
    int bookAmount;
    long long freeMinutes;

    scanf("%d %lld", &bookAmount, &freeMinutes);

    long long array[bookAmount + 1];

    array[0] = 0;

    for (int i = 1; i <= bookAmount; i++) {
        array[i] = array[i - 1] + scanInt();
    }

    int maxBooks;

    if (array[bookAmount] <= freeMinutes) {
        maxBooks = bookAmount;
    } else {
        maxBooks = binarySearch(array, bookAmount, freeMinutes);
    }

    printf("%d", maxBooks);
}