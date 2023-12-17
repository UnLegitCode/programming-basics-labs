#include <malloc.h>
#include <stdbool.h>

#define EPS 1E-6

int* scanNumArray(const size_t size);

void sortIntArray(int* array, const int size);

void sortLLArray(long long* array, const int size);

int min(const int a, const int b);

int max(const int a, const int b);

long long minLL(const long long a, const long long b);

long long maxLL(const long long a, const long long b);

int scanInt();

long long scanLL();

int findMax(const int* array, const int size);

long long findMaxLL(const long long* array, const int size);

void swapll(long long* const a, long long* const b);

long long* scanNumArrayLL(const size_t size);

void copyOfRange(const long long* source, long long* const destination, const int start, const int end);

long long sum(const int* array, const int size);

long long sumLL(const long long* array, const int size);

bool isEqual(const double long first, const long long second);