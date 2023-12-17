#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>
#include "util.h"

int* scanNumArray(const size_t size) {
    int* array = calloc(size, sizeof(int));

    for (int i = 0; i < size; ++i) {
        scanf("%d", array + i);
    }

    return array;
}

int compare(const void* first, const void* second) {
    return *((const int*) first) - *((const int*) second);
}

void sortIntArray(int* array, const int size) {
    qsort(array, size, sizeof(int), compare);
}

int compareLL(const void* first, const void* second) {
    return *((const long long*) first) - *((const long long*) second);
}

void sortLLArray(long long* array, const int size) {
    qsort(array, size, sizeof(long long), compareLL);
}

int min(const int a, const int b) {
    return (a < b) ? a : b;
}

int max(const int a, const int b) {
    return (a > b) ? a : b;
}

long long minLL(const long long a, const long long b) {
    return (a < b) ? a : b;
}

long long maxLL(const long long a, const long long b) {
    return (a > b) ? a : b;
}

int scanInt() {
    int value;

    scanf("%d", &value);

    return value;
}

long long scanLL() {
    long long value;

    scanf("%lld", &value);

    return value;
}


int findMax(const int* array, const int size) {
    int maximum = array[0];

    for (int i = 1; i < size; ++i) {
        maximum = max(maximum, array[i]);
    }

    return maximum;
}

long long findMaxLL(const long long* array, const int size) {
    long long maximum = array[0];

    for (int i = 1; i < size; ++i) {
        maximum = maxLL(maximum, array[i]);
    }

    return maximum;
}

void swapll(long long* const a, long long* const b) {
    const long long aValue = *a;

    *a = *b;
    *b = aValue;
}

long long* scanNumArrayLL(const size_t size) {
    long long* array = calloc(size, sizeof(long long));

    for (int i = 0; i < size; ++i) {
        scanf("%lld", array + i);
    }

    return array;
}

void copyOfRange(const long long* source, long long* const destination, const int start, const int end) {
    for (int i = start; i < end; ++i) {
        destination[i] = source[i];
    }
}

long long sum(const int* array, const int size) {
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }

    return sum;
}

long long sumLL(const long long* array, const int size) {
    long long sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }

    return sum;
}

bool isEqual(const double long first, const long long second) {
    return fabsl(first - second) <= EPS;
}