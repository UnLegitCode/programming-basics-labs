#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

/**
 * scans array with fixed size from standard input
 * @param size array size
 * @return pointer to first array element
*/
int* scanArray(int size) {
    int* array = (int*) malloc(sizeof(int) * size);

    for (int i = 0; i < size; ++i) {
        scanf("%d", array + i);
    }

    return array;
}

/**
 * prints array to the standard output
 * @param array the array to be printed
 * @param size array size
*/
void printArray(int array[], int size) {
    putchar('[');

    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i != (size - 1)) {
            printf(", ");
        }
    }

    putchar(']');
}

/**
 * searches target value in provided array and returns index of first result
 * @param array the array in which the binarySearch3 will be performed
 * @param size array size
 * @param value target value
 * @return index of the first element equal to target
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
 * searches negative value in provided array and returns index of first result
 * @param array the array in which the binarySearch3 will be performed
 * @param size array size
 * @return index of the first negative element
*/
int indexOfNegative(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        if (array[i] < 0) {
            return i;
        }
    }

    return -1;
}

/**
 * searches for value satisfying the predicate in provided array and returns index of first result
 * @param array the array in which the binarySearch3 will be performed
 * @param size array size
 * @param value target value
 * @return index of the first element satisfying the predicate
*/
int indexOfByPredicate(int array[], int size, bool (*predicate)(int)) {
    for (int i = 0; i < size; ++i) {
        if (predicate(array[i])) {
            return i;
        }
    }

    return -1;
}

/**
 * searches for an even element from the end of the provided array
 * @param array the array in which the binarySearch3 will be performed
 * @param size array size
 * @return index of the last even element
*/
int lastIndexOfEven(int array[], int size) {
    for (int i = size - 1; i > 0; i--) {
        if (array[i] & 1) {
            return i;
        }
    }

    return -1;
}

/**
 * searches for value from the end of the array satisfying the predicate and returns index of first result
 * @param array the array in which the binarySearch3 will be performed
 * @param size array size
 * @param predicate predicate to check elements
 * @return index of the last element satisfying the predicate
*/
int lastIndexOfByPredicate(int array[], int size, bool (*predicate)(int)) {
    for (int i = size - 1; i > 0; i--) {
        if (predicate(array[i])) {
            return i;
        }
    }

    return -1;
}

/**
 * counts negative elements in the provided array
 * @param array the array in which the binarySearch3 will be performed
 * @param size array size
 * @return amount of negative elements in the provided array
*/
int countNegative(int array[], int size) {
    int counter = 0;

    for (int i = 0; i < size; ++i) {
        if (array[i] < 0) {
            counter++;
        }
    }

    return counter;
}

/**
 * counts elements which satisfies the predicate in the provided array
 * @param array the array in which the binarySearch3 will be performed
 * @param size array size
 * @return amount of elements which satisfies the predicate in the provided array
*/
int count(int array[], int size, bool (*predicate)(int)) {
    int counter = 0;

    for (int i = 0; i < size; ++i) {
        if (predicate(array[i])) {
            counter++;
        }
    }

    return counter;
}

/**
 * reverses array
 * @param array the array to be reversed
 * @param size array size
 * @return reversed array
*/
int* reverseArray(int array[], int size) {
    int* destination = (int*) malloc(sizeof(int) * size);

    for (int i = 0; i < size; ++i) {
        destination[size - i - 1] = array[i];
    }

    return destination;
}

/**
 * checks whether the array is a palindrome
 * @param array array to be checked
 * @param size array size
 * @return "true" if array is palindrome and "false" otherwise
*/
bool isPalindrome(int array[], int size) {
    int limit = (size >> 1) + (size & 1);

    for (int i = 0; i < limit; i++) {
        if (array[i] != array[size - i - 1]) {
            return false;
        }
    }

    return true;
}

/**
 * searches max element in the array and returns index of that element
 * @param array the array in which the binarySearch3 will be performed
 * @param offset start index
 * @param size array size
 * @return index of array max element
*/
int indexOfMax(int array[], int offset, int size) {
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
 * swaps two int values by pointers
 * @param first first value pointer
 * @param second second value pointer
*/
void swapDouble(int* first, int* second) {
    int firstValue = *first;

    *first = *second;
    *second = firstValue;
}

/**
 * sorts array
 * @param array array to be sorted
 * @param size array size
*/
void sort(int array[], int size) {
    int offset = 0;

    for (int i = 0; i < size; ++i) {
        swapDouble(array + offset, array + indexOfMax(array, offset, size));
        offset++;
    }
}

/**
 * removes all odd element from array
 * @param array array for cleaning
 * @param size array size
 * @return new array size
*/
int removeOdd(int array[], int size) {
    int index = 0;
    for (int i = 0; i < size; i++) {
        if ((array[i] & 1) == 0) {
            array[index++] = array[i];
        }
    }

    for (int i = index; i < size; i++) {
        array[i] = 0;
    }

    return size - index;
}

/**
 * inserts an element into an array by index
 * @param array destination array
 * @param size array size
 * @param index index for insertion
 * @param value value to be inserted
*/
void insertTo(int array[], int size, int index, int value) {
    for (int i = size - 1; i >= index; i--) {
        array[i + 1] = array[i];
    }

    array[index] = value;
}

/**
 * adds the value to the end of the array
 * @param array destination array
 * @param size array size
 * @param value value to be added
*/
void add(int array[], int* size, int value) {
    array[*size] = value;
    (*size)++;
}

/**
 * deletes elemenet from the array and safes array order
 * @param array the array from which the element will be removed
 * @param size array size
 * @param index index of the element to be deleted
*/
void deleteAndSafeOrder(int array[], int *size, int index) {
    for (int i = index; i < *size - 1; i++) {
        array[i] = array[i + 1];
    }

    (*size)--;
}

/**
 * deletes elemenet from the array but does not safes array order
 * @param array the array from which the element will be removed
 * @param size array size
 * @param index index of the element to be deleted
*/
void delete(int array[], int* size, int index) {
    array[index] = array[--(*size)];
}

/**
 * performs a cyclic shift of the array to the left
 * @param array array to be shifted
 * @param size array size
 * @param distance shift distance
*/
void lefyCyclyShift(int array[], int size, int distance) {
    distance = distance % size;

    for (int i = 0; i < distance; i++) {
        int temp = array[0];

        for (int j = 0; j < size - 1; j++) {
            array[j] = array[j + 1];
        }

        array[size - 1] = temp;
    }
}

/**
 * performs action for each element of the array
 * @param array array for handling
 * @param size array size
 * @param action the action that will be performed
*/
void forEach(int array[], int size, void (*action)(int)) {
    for (int i = 0; i < size; ++i) {
        action(array[i]);
    }
}

/**
 * checks that at least one of the array elements satisfies the predicate
 * @param array array for check
 * @param size array size
 * @param predicate predicate for check
 * @return "true" if at least one of the array elements satisfies the predicate and "false" otherwise
*/
bool any(int array[], int size, bool (*predicate)(int)) {
    for (int i = 0; i < size; ++i) {
        if (predicate(array[i])) {
            return true;
        }
    }

    return false;
}

/**
 * checks that all the array elements satisfies the predicate
 * @param array array for check
 * @param size array size
 * @param predicate predicate for check
 * @return "true" if all of the array elements satisfies the predicate and "false" otherwise
*/
bool all(int array[], int size, bool (*predicate)(int)) {
    for (int i = 0; i < size; ++i) {
        if (!predicate(array[i])) {
            return false;
        }
    }

    return true;
}

/**
 * representation of a dynamic integer array
*/
typedef struct {
    int* array;
    int size;
} IntVector;

/**
 * factory method for creating an integer vector
 * @param initialSize initial vector size
 * @return created vector
 */
IntVector* createIntVector(int initialSize) {
    IntVector* array = malloc(sizeof(IntVector));

    array->array = calloc(initialSize, sizeof(int));
    array->size = initialSize;

    return array;
}

/**
 * adds an element to the end of the vector, first expanding it
 * @param vector destination vector
 * @param value value to be added
*/
void push(IntVector* vector, int value) {
    vector->array = realloc(vector->array, vector->size + sizeof(int));
    vector->array[vector->size++] = value;
}

/**
 * splits the source array into 2 vectors depending on the predicate
 * @param array source array
 * @param size source array size
 * @param predicate predicate to splitting
 * @return two vectors with splitting results
*/
IntVector** splitArray(int array[], int size, bool (*predicate)(int)) {
    IntVector** vectors = malloc(sizeof(IntVector*) << 1);

    for (int i = 0; i < 2; ++i) {
        vectors[i] = createIntVector(0);
    }

    int value;

    for (int i = 0; i < size; ++i) {
        value = array[i];

        push(vectors[!predicate(value)], value);
    }

    return vectors;
}