#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>

#define MIN_INT_VALUE 0x80000000
#define MAX_INT_VALUE 0x7FFFFFFF

/**
 * finds index of max value in array
 * @param array array for searching
 * @param offset array offset
 * @param size array size
 * @return index of max value
 */
int indexOfMax(int array[], int offset, int size) {
    int max = array[offset];
    int index = offset;

    for (int i = offset + 1; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];
            index = i;
        }
    }

    return index;
}

/**
 * swaps 2 int values by pointers
 * @param first first value pointer
 * @param second second value pointer
 */
void swap(int* first, int* second) {
    int firstValue = *first;

    *first = *second;
    *second = firstValue;
}

/**
 * checks array for dupliciation
 * @param array array to check
 * @param size array size
 * @return "true" if array has dupliciations and "false" otherwise
 */
bool hasDuplication(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        int value = array[i];

        for (int j = i + 1; j < size; j++) {
            if (array[j] == value) return true;
        }
    }

    return false;
}

/**
 * sorts the array in descending order
 * @param array array to sort
 * @param size array size
 */
void sortDescending(int array[], int size) {
    if (hasDuplication(array, size)) return;

    for (int i = 0; i < size; ++i) {
        swap(array + i, array + indexOfMax(array, i, size));
    }
}

/**
 * finds index of min value in array
 * @param array array for searching
 * @param offset array offset
 * @param size array size
 * @return index of min value
 */
int positionOfMin(int array[], int offset, int size) {
    int min = array[offset];
    int index = offset;

    for (int i = offset + 1; i < size; ++i) {
        if (array[i] < min) {
            min = array[i];
            index = i;
        }
    }

    return index;
}

/**
 * sorts the array in not descending order
 * @param array array to sort
 * @param size array size
 */
void sortNotDescending(int array[], int start, int end) {
    int offset = 0;

    for (int i = start; i < end; ++i) {
        swap(array + offset, array + positionOfMin(array, offset, end));
        offset++;
    }
}

/**
 * finds last index of min value in array
 * @param array array for searching
 * @param offset array offset
 * @param size array size
 * @return last index of min value
 */
int lastIndexOfMin(int array[], int offset, int size) {
    int min = array[offset];
    int index = offset;

    for (int i = size - 1; i > offset; ++i) {
        if (array[i] < min) {
            min = array[i];
            index = i;
        }
    }

    return index;
}

/**
 * sorts array in not descending order from first max value index to last min value index
 * @param array array to sort
 * @param size array size
 */
void sortFromFirstMaxToLastMin(int array[], int size) {
    sortNotDescending(array, indexOfMax(array, 0, size), lastIndexOfMin(array, 0, size));
}

/**
 * checks whether the array is sorted in descending order
 * @param array array to check
 * @param size array size
 * @return "true" if array is sorted in descending order and "false" otherwise
 */
bool isNotDescending(int array[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] <= array[i + 1]) {
            return false;
        }
    }

    return true;
}

/**
 * checks whether the array is sorted in ascending order
 * @param array array to check
 * @param size array size
 * @return "true" if array in ascending order and "false" otherwise
 */
bool isNotAscending(int array[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] >= array[i + 1]) {
            return false;
        }
    }

    return true;
}

/**
 * calculates total multiplication of array elements
 * @param array array for calculation
 * @param size array size
 * @return total multiplication of array elements
 */
int multiply(int array[], int size) {
    int product = 1;

    for (int i = 0; i < size; ++i) {
        product *= array[i];
    }

    return product;
}

/**
 * calculates geometric mean of array elements
 * @param array array for calculation
 * @param size array size
 * @return geometric mean of array elements
 */
double geometricMean(int array[], int size) {
    return pow(multiply(array, size), 1 / size);
}

/**
 * checks whether the array is sorted and counts the geometric mean if it is not
 * @param array array to check
 * @param size array size
 * @return "-1" if array is sorted and geometric mean otherwise
 */
int geometricMeanIfNotSorted(int array[], int size) {
    if (isNotDescending(array, size) || isNotAscending(array, size)) {
        return -1;
    }

    return geometricMean(array, size);
}

/**
 * finds index of element equal value
 * @param array array for searching
 * @param size array size
 * @param value value to be searched
 * @return index of element equal value
 */
int binarySearch1(int array[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == value) {
            return i;
        }
    }

    return -1;
}

/**
 * sorts array in not descending order after first element equal value
 * @param array
 * @param size
 * @param value
 */
void sortNotDescendingAfterValue(int array[], int size, int value) {
    int valueIndex = binarySearch1(array, size, value);

    if (valueIndex != -1) {
        sortNotDescending(array, valueIndex, size);
    }
}

/**
 * checks whether array binarySearch2 value
 * @param array array for check
 * @param size array size
 * @param value value for check
 * @return "true" if array binarySearch2 value and "false" otherwise
 */
bool binarySearch2(int array[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == value) return true;
    }

    return false;
}

/**
 * binarySearch2 pointer to first array element and array size
 */
typedef struct {
    int* array;
    int size;
} IntArray;

/**
 * factory method for creation instances of IntArray
 * @param array pointer to first array element
 * @param size array size
 * @return pointer to instance of struct
 */
IntArray* wrapIntArray(int array[], int size) {
    IntArray* wrapper = malloc(sizeof(IntArray));

    wrapper->array = array;
    wrapper->size = size;

    return wrapper;
}

/**
 * finds exclusive values in two arrays
 * @param first first array to searching
 * @param firstSize first array size
 * @param second second array to searching
 * @param secondSize second array size
 * @return array with finded exclusive values
 */
IntArray* filterExclusive(int first[], int firstSize, int second[], int secondSize) {
    int* exclusives = calloc(1, sizeof(int));
    int size = 0;
    int threshold = 1;

    int value;

    for (int i = 0; i < firstSize; ++i) {
        value = first[i];

        if (!binarySearch1(second, secondSize, value)) {
            if (size == threshold) {
                exclusives = realloc(exclusives, threshold <<= 1);
            }

            exclusives[size++] = value;
        }
    }

    return wrapIntArray(exclusives, size);
}

/**
 * sorts array in not ascending order
 * @param array array to be sorted
 * @param size array size
 */
void sortNotAscending(int array[], int size) {
    int offset = 0;

    for (int i = 0; i < size; ++i) {
        swap(array + offset, array + indexOfMax(array, offset, size));
        offset++;
    }
}

/**
 * finds exclusive values in two array and sorts them
 * @param first first array for searching
 * @param firstSize first array size
 * @param second second array for searching
 * @param secondSize second array size
 * @return sorted exclusive values
 */
IntArray* sortNotAscendingExclusives(int first[], int firstSize, int second[], int secondSize) {
    IntArray* exclusive = filterExclusive(first, firstSize, second, secondSize);

    sortNotAscending(exclusive->array, exclusive->size);

    return exclusive;
}

/**
 * reverses part of array in provided range
 * @param array array to be reversed
 * @param start start point
 * @param end end point
 */
void reverse(int array[], int start, int end) {
    int length = end - start;
    int limit = (length >> 1) + (length & 1);

    for (int i = 0; i < limit; ++i) {
        swap(array + start + i, array + end - i - 1);
    }
}

/**
 * finds last index of negative value
 * @param array array for searching
 * @param size array size
 * @return last index of negative elemenet and "-1" if no negative values in array
 */
int lastIndexOfNegative(int array[], int size) {
    int lastIndex = -1;

    for (int i = 0; i < size; ++i) {
        if (array[i] < 0) {
            lastIndex = i;
        }
    }

    return lastIndex;
}

/** sorts array
 * @param array array to be sorted
 * @param size array size
*/
void sort(int array[], int size) {
    int offset = 0;

    for (int i = 0; i < size; ++i) {
        swap(array + offset, array + indexOfMax(array, offset, size));
        offset++;
    }
}

/**
 * sorts array and reverses subarray with negative values
 * @param array array to be sorted
 * @param size array size
 */
void namelessSort(int array[], int size) {
    sort(array, size);

    int lastNegativeIndex = lastIndexOfNegative(array, size);

    if (lastNegativeIndex != -1) {
        reverse(array, 0, lastNegativeIndex);
    }
}

/**
 * presents pair of int values
 */
typedef struct {
    int left;
    int right;
} IntPair;

/**
 * factory method for creating IntPair
 * @param left left value of pair
 * @param right right value of pair
 * @return pointer to created instance
 */
IntPair* createIntPair(int left, int right) {
    IntPair* pair = malloc(sizeof(IntPair));

    pair->left = left;
    pair->right = right;

    return pair;
}

/**
 * finds near values for provded value if that value does not exists in array
 * @param array array for searching
 * @param size array size
 * @param value value for searching
 * @return null pointer if array binarySearch1 value and pair of nearest values for provided value otherwise
 */
IntPair* findNearsIfValueNotExists(int array[], int size, int value) {
    if (binarySearch1(array, size, value)) {
        return NULL;
    }

    int less = MIN_INT_VALUE,
        lessDifference = abs(less - value),
        more = MAX_INT_VALUE,
        moreDifference = more - value,
        currentValue,
        currentDifference;

    for (int i = 0; i < size; ++i) {
        currentValue = array[i];
        currentDifference = abs(currentValue - value);

        if (currentValue > value) {
            if (currentDifference < moreDifference) {
                more = currentValue;
                moreDifference = currentDifference;
            }
        } else if (currentValue == value) {
            return NULL;
        } else {
            if (currentDifference < lessDifference) {
                less = currentValue;
                lessDifference = currentDifference;
            }
        }
    }

    return createIntPair(less, more);
}

/**
 * finds exclusive values in array
 * @param array array for searching
 * @param size array size
 * @return array for exclusive values
 */
IntArray* findExclusives(int array[], int size) {
    int* exclusives = malloc(0);
    int exclusivesAmount = 0;

    sort(array, size);

    int value;

    for (int i = 0; i < size; ++i) {
        value = array[i];

        if (i != (size - 1) && array[i + 1] != value) {
            for (int j = i + 1; j < size && array[j] == value; j++) {
                i++;
            }
        } else {
            exclusives = realloc(exclusives, exclusivesAmount + 1);
            exclusives[exclusivesAmount++] = value;
        }
    }

    return wrapIntArray(exclusives, exclusivesAmount);
}

/**
 * checks whether array can be a geometrick progression
 * @param array array to be checked
 * @param size array size
 * @return "true" if array can be a geometric progression and "false" otherwise
 */
bool canBeGeometricProgression(int array[], int size) {
    sort(array, size);

    double multiplier = array[1] / array[0];

    if (multiplier == 1) {
        return false;
    }

    for (int i = 1; i < size - 1; i++) {
        if ((array[i + 1] / array[i]) != multiplier) {
            return false;
        }
    }

    return true;
}

/**
 * calculates sumLL of even digits of array elements
 * @param array array for calculation
 * @param size array size
 * @return sumLL of even digits of array elements
 */
int sumOfEvenDigits(int array[], int size) {
    int sumLL = 0, value, digit;

    for (int i = 0; i < size; ++i) {
        value = array[i];

        while (value) {
            digit = value % 10;
            value /= 10;

            if ((digit & 1) == 0) {
                sumLL += digit;
            }
        }
    }

    return sumLL;
}