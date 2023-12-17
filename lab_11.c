#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int inputTextLength() {
    if (getchar() == '\n') {
        return 0;
    }

    return inputTextLength() + 1;
}

void printOct(const unsigned int number) {
    if (number != 0) {
        printOct(number / 8);
        printf("%d", number % 8);
    }
}

int geometricMeanMember(const int startMember, const int multiplier, const int memberIndex) {
    if (memberIndex == 1) {
        return startMember;
    } else {
        return geometricMeanMember(startMember * multiplier, multiplier, memberIndex - 1);
    }
}

bool contains(const int* array, const int size, const int value) {
   if (size == 0) {
       return false;
   }

   const int current = array[size - 1];

   return (current == value) || ((current >= value) && contains(array, size - 1, value));
}

bool isNotDescending(const int* array, const int size) {
    return (size == 1) || ((array[size - 2] <= array[size - 1]) && isNotDescending(array, size - 1));
}

int indexOfMinInRange(const int* array, const int start, const int end) {
    if (start == end) {
        return start;
    }

    const int minIndex = indexOfMinInRange(array, start, end - 1);

    return (array[minIndex] < array[end]) ? minIndex : end;
}

int indexOfMin(const int* array, const int size) {
    return indexOfMinInRange(array, 0, size - 1);
}

bool isNearbyFibonacciMembers0(const int sequenceLeft, const int sequenceRight, const int left, const int right) {
    if ((sequenceLeft > left) || (sequenceRight > right)) {
        return false;
    }

    if ((sequenceLeft == left) && (sequenceRight == right)) {
        return true;
    }

    return isNearbyFibonacciMembers0(sequenceRight, sequenceLeft + sequenceRight, left, right);
}

bool isNearbyFibonacciMembers(const int left, const int right) {
    return isNearbyFibonacciMembers0(1, 1, left, right);
}

void printReversedScannedNotDigits() {
    char character = getchar();

    if (character != '\n') {
        printReversedScannedNotDigits();

        if (!isdigit(character)) {
            putchar(character);
        }
    }
}

int arithmeticMeanFirstMember(const int member, const int index, const int difference) {
    return (index == 1) ? member : arithmeticMeanFirstMember(member - difference, index - 1, difference);
}

double scanDouble() {
    double value;

    scanf("%lf", &value);

    return value;
}

void printAverages0(const double first, const double second) {
    printf("%.2lf\n", (first + second) / 2);

    double value = scanDouble();

    if (value >= 0) {
        printAverages0(second, value);
    }
}

void printAverages() {
    double first = scanDouble();

    if (first >= 0) {
        double second = scanDouble();

        if (second >= 0) {
            printAverages0(first, second);
        }
    }
}

bool any(const int* array, const int size, const bool (*predicate)(int)) {
    return (size > 0) && (predicate(array[size - 1]) || any(array, size - 1, predicate));
}

bool all(const int* array, const int size, const bool (*predicate)(int)) {
    return (size == 0) || (predicate(array[size - 1]) && all(array, size - 1, predicate));
}

int binarySearch0(const int* array, const int left, const int right, const int value) {
    const int middle = left + ((right - left) >> 1);
    const int middleValue = array[middle];

    if (middleValue == value) {
        return middle;
    }

    if (middleValue < value) {
        return binarySearch0(array, middle + 1, right, value);
    }

    return binarySearch0(array, left, middle - 1, value);
}

int binarySearch(const int* array, const int size, const int value) {
    return binarySearch0(array, 0, size - 1, value);
}

void swap(int* const first, int* const second) {
    const int firstValue = *first;

    *first = *second;
    *second = firstValue;
}

void sortDescending(int* const array, const int size) {
    if (size == 0) return;

    swap(array + size - 1, array + indexOfMinInRange(array, 0, size - 1));
    sortDescending(array, size - 1);
}