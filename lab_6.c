//#include <stdio.h>
//#include <math.h>
//#include <stdbool.h>
//
///**
// * calculates the modulus of a double number
// * @param number original real number
// * @return modulus of source number
// */
//int absd(double number) {
//    return number >= 0 ? number : -number;
//}
//
///**
// * selects the maximum of two integer numbers
// * @param first first number
// * @param second second number
// * @return max of the two numbers
// */
//int max2(int first, int second) {
//    return first >= second ? first : second;
//}
//
///**
// * selects the maximum of three integer numbers
// * @param first first number
// * @param second second number
// * @param third third number
// * @return max of the three numbers
// */
//int max3(int first, int second, int third) {
//    return max2(max2(first, second), third);
//}
//
///**
// * computes distance between two points in 2-dimensional space
// * @param x1 first point x coordinate
// * @param y1 first point y coordinate
// * @param x2 second point x coordinate
// * @param y2 second point y coordinate
// * @return computed distance
// */
//int getDistance(int x1, int y1, int x2, int y2) {
//    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
//}
//
///**
// * solves a quadratic equation and <u>prints</u> the results
// * @param a senior coefficient
// * @param b middle coefficient
// * @param c free term
// */
//void solveX2(int a, int b, int c) {
//    double discriminant = pow(b, 2) - ((a * c) << 2);
//
//    if (discriminant < 0) {
//        printf("The equation has no roots");
//    } else if (discriminant == 0) {
//        double x = -b / (a << 1);
//
//        printf("x = %.2lf", x);
//    } else {
//        double discriminantSqrt = sqrt(discriminant);
//        double x1 = (-b + discriminantSqrt) / (a << 1);
//        double x2 = (-b - discriminantSqrt) / (a << 1);
//
//        printf("x1 = %.2lf\nx2 = %.2lf", x1, x2);
//    }
//}
//
///**
// * checks whether the character is a digit
// * @param number character
// * @return "true" if the character is a digit and "false" otherwise
// */
//bool _isDigit(char number) {
//    return number >= '0' && number <= '9';
//}
//
///**
// * swaps float values between two memory points
// * @param a first pointer
// * @param b second pointer
// */
//void swapf(float* a, float* b) {
//    float aValue = *a;
//
//    *a = *b;
//    *b = aValue;
//}
//
///**
// * sorts float values between two memory points
// * @param a first pointer
// * @param b second pointer
// */
//void sort2(float* a, float* b) {
//    if (*a > *b) swapf(a, b);
//}
//
///**
// * sorts float values between three memory points
// * @param a first pointer
// * @param b second pointer
// * @param c third pointer
// */
//void sort3(float* a, float* b, float*c) {
//    sort2(a, b);
//    sort2(b, c);
//    sort2(a, b);
//}
//
//
///**
// * swaps integer values between two memory points
// * @param a first pointer
// * @param b second pointer
// */
//void swapi(int* a, int* b) {
//    int aValue = *a;
//
//    *a = *b;
//    *b = aValue;
//}
//
///**
// * sorts integer values between two memory points
// * @param a first pointer
// * @param b second pointer
// */
//void sort2i(int* a, int* b) {
//    if (*a > *b) swapi(a, b);
//}
//
///**
// * sorts integer values between three memory points
// * @param a first pointer
// * @param b second pointer
// * @param c third pointer
// */
//void sort3i(int* a, int* b, int*c) {
//    sort2i(a, b);
//    sort2i(b, c);
//    sort2i(a, b);
//}
//
///**
// * checks the possibility of creating a triangle with these sides
// * @param a first side
// * @param b second side
// * @param c third side
// * @return "true" if triangle can be created and "false" otherwise
// */
//bool isTrianglePossible(int a, int b, int c) {
//    return (a + b > c) && (a + c > b) && (b + c > a);
//}
//
///**
// * compares two integer numbers
// * @param a first number
// * @param b second number
// * @return "1" if a more than b, "0" if a equals b and "-1" if a less than b
// */
//int compare(int a, int b) {
//    if (a < b) return -1;
//
//    return a == b ? 0 : 1;
//}
//
//enum TriangleType {
//    INVALID = -1,
//    ACUTE_ANGLED = 0,
//    RECTANGULAR = 1,
//    OBTUSE_ANGLED = 2
//};
//
///**
// * defines the type of triangle by the lengths of the sides
// * @param a first side
// * @param b second side
// * @param c third side
// * @return defined triangle type
// */
//enum TriangleType getTriangleType(int a, int b, int c) {
//    if (!isTrianglePossible(a, b, c)) return INVALID;
//
//    int aCopy = a;
//    int bCopy = b;
//    int cCopy = c;
//
//    sort3i(&aCopy, &bCopy,& cCopy);
//
//    switch (compare(pow(aCopy, 2) + pow(bCopy, 2), pow(cCopy, 2))) {
//        case -1: return ACUTE_ANGLED;
//        case 0: return RECTANGULAR;
//        default: return OBTUSE_ANGLED;
//    }
//}
//
///**
// * calculates the modulus of a integer number
// * @param number original integer number
// * @return modulus of source number
// */
//int absi(int number) {
//    return number >= 0 ? number : -number;
//}
//
///**
// * checks whether a number is prime
// * @param number input number
// * @return "true" if number is prime and "false" otherwise
// */
//bool unoptimizedIsPrime(int number) {
//    number = absi(number);
//
//    for (int i = 2; i < number; ++i) {
//        if (number % i == 0) return false;
//    }
//
//    return true;
//}
//
///**
// * checks whether a number is prime (optimized version)
// * @param number input number
// * @return "true" if number is prime and "false" otherwise
// */
//bool optimizedIsPrime(int number) {
//    number = absi(number);
//    int numberSqrt = sqrt(number);
//
//    if (pow(numberSqrt, 2) != number) return false;
//
//    for (int i = 2; i < numberSqrt; ++i) {
//        if (number % i == 0) return false;
//    }
//
//    return true;
//}
//
///**
// * checks whether a number is prime (most optimized version)
// * @param number input number
// * @return "true" if number is prime and "false" otherwise
// */
//bool mostOptimizedIsPrime(int number) {
//    number = absi(number);
//    int numberSqrt = sqrt(number);
//
//    if (pow(numberSqrt, 2) != number) return false;
//
//    for (int i = 2 + (number & 1); i < numberSqrt; i += 2) {
//        if (number % i == 0) return false;
//    }
//
//    return true;
//}
//
///**
// * checks whether a number is perfect
// * @param number input number
// * @return "true" if number is perfect and "false" otherwise
// */
//bool isPerfect(int number) {
//    int maxDivider = (number & 1) ? number / 3 : number >> 1;
//    int dividerSum = maxDivider;
//
//    for (int i = 1; i < maxDivider; i++) {
//        if (number % i == 0) {
//            dividerSum += i;
//        }
//    }
//
//    return dividerSum == number;
//}
//
///**
// * prints each perfect number before limit
// * @param limit max sequence element
// */
//void printPerfectNumbers(int limit) {
//    for (int i = 1; i <= limit; ++i) {
//        if (isPerfect(i)) {
//            printf("%d ", i);
//        }
//    }
//}
//
///**
// * writes the digits of the number in reverseArray order
// * @param number source number
// * @return reversed number
// */
//int reverse(int number) {
//    int reversed = 0;
//
//    while (number > 0) {
//        reversed = reversed * 10 + number % 10;
//        number /= 10;
//    }
//
//    return reversed;
//}
//
///**
// * calculates amount of palindrome numbers before limit
// * @param limit max sequence element
// * @return amount of palindrome numbers
// */
//int getPalindromeAmount(int limit) {
//    int amount = 0;
//
//    for (int i = 1; i <= limit; ++i) {
//        if (i == reverse(i)) amount++;
//    }
//
//    return amount;
//}
//
///**
// * check whether ticket is happy
// * @param ticket ticket number
// * @return "true" if ticket is happy and "false" otherwise
// */
//bool isTicketHappy(int ticket) {
//    int leftTrioSum = (ticket / 100000) + ((ticket % 100000) / 10000) + ((ticket % 10000) / 1000);
//    int rightTrioSum = ((ticket % 1000) / 100) + ((ticket % 100) / 10) + (ticket % 10);
//
//    return leftTrioSum == rightTrioSum;
//}