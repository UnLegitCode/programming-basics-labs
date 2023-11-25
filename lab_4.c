#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdbool.h>

#define EPS 0.0000001

int fcompare(double a, double b) {
    return fabs(a - b) < EPS;
}

bool isLetter(char character) {
    return character >= 'a' && character <= 'z';
}

bool isConsonantLetter(char character) {
    switch (character) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            return false;
        default:
            return true;
    }
}

bool isDigit(char character) {
    return character >= '0' && character <= '9';
}

void one4() {
    int numberAmount;
    long long number, maxNumber;

    scanf("%d", &numberAmount);
    scanf("%lld", &number);

    maxNumber = number;

    for (int i = 1; i < numberAmount; ++i) {
        scanf("%lld", &number);

        if (number > maxNumber) {
            maxNumber = number;
        }
    }

    printf("%lld", maxNumber);
}

void two4() {
    SetConsoleOutputCP(CP_UTF8);

    int number, maxNumber = 0;

    scanf("%d", &number);

    while (number) {
        if (number > maxNumber) {
            maxNumber = number;
        }

        scanf("%d", &number);
    }

    if (maxNumber == 0) {
        printf("Последовательность пуста");
    } else {
        printf("%d", maxNumber);
    }
}

void three4() {
    int numberAmount, firstMinNumberIndex = 0;
    long long number, minNumber;

    scanf("%d", &numberAmount);
    scanf("%lld", &minNumber);

    for (int i = 1; i < numberAmount; ++i) {
        scanf("%lld", &number);

        if (number < minNumber) {
            minNumber = number;
            firstMinNumberIndex = i;
        }
    }

    printf("%d", firstMinNumberIndex);
}

void four4() {
    int numberAmount, lastMaxNumberIndex = 0;
    long long number, maxNumber;

    scanf("%d", &numberAmount);
    scanf("%lld", &maxNumber);

    for (int i = 1; i < numberAmount; ++i) {
        scanf("%lld", &number);

        if (number >= maxNumber) {
            maxNumber = number;
            lastMaxNumberIndex = i;
        }
    }

    printf("%d", lastMaxNumberIndex);
}

void five4() {
    int numberAmount, minNumberAmount = 1;
    long long number, minNumber;

    scanf("%d", &numberAmount);
    scanf("%lld", &minNumber);

    for (int i = 1; i < numberAmount; ++i) {
        scanf("%lld", &number);

        if (number < minNumber) {
            minNumber = number;
            minNumberAmount = 1;
        } else {
            minNumberAmount++;
        }
    }

    printf("%d", minNumberAmount);
}

void six4() {
    int numberAmount;
    long long number, minNumber, maxNumber;

    scanf("%d", &numberAmount);
    scanf("%lld", &minNumber);

    maxNumber = minNumber;

    for (int i = 0; i < numberAmount; ++i) {
        scanf("%lld", &number);

        if (number > maxNumber) {
            maxNumber = number;
        } else {
            minNumber = number;
        }
    }

    long long difference = maxNumber - minNumber;

    printf("%lld", difference);
}

void seven4() {
    long long number, evenNumberSum = 0;

    scanf("%lld", &number);

    while (number) {
        if (number % 2 == 0) {
            evenNumberSum += number;
        }

        scanf("%lld", &number);
    }

    printf("%lld", evenNumberSum);
}

void eight4() {
    long long number;
    int lastDigit, maxDigit = 0;

    scanf("%lld", &number);

    while (number) {
        lastDigit = number % 10;

        if (lastDigit > maxDigit) {
            maxDigit = lastDigit;
        }

        number /= 10;
    }

    printf("%d", maxDigit);
}

void nine4() {
    long long number;
    int evenNumberAmount = 0, oddNumberAmount = 0;

    scanf("%lld", &number);

    while (number) {
        if (number % 2) {
            oddNumberAmount++;
        } else {
            evenNumberAmount++;
        }

        scanf("%lld", &number);
    }

    printf("%d %d", evenNumberAmount, oddNumberAmount);
}

void ten4() {
    long long number, digitMultiplication = 1;
    int lastDigit;

    scanf("%lld", &number);

    while (number) {
        lastDigit = number % 10;

        if (lastDigit != 0) {
            digitMultiplication *= lastDigit;
        }

        number /= 10;
    }

    printf("%d", digitMultiplication);
}

void eleven4() {
    long long number;
    int digit, requiredDigitAmount, actuallyDigitAmount = 0;

    scanf("%lld %d %d", &number, &digit, &requiredDigitAmount);

    while (number) {
        if (number % 10 == digit) {
            actuallyDigitAmount++;
        }

        number /= 10;
    }

    printf(actuallyDigitAmount == requiredDigitAmount ? "YES" : "NO");
}

void twelve4() {
    SetConsoleOutputCP(CP_UTF8);

    long long number, minNumber, nextAfterMinNumber = 0;
    bool needToSaveNext = false;

    scanf("%lld", &number);

    while (number) {
        if (number <= minNumber) {
            minNumber = number;
            needToSaveNext = true;
        } else if (needToSaveNext) {
            nextAfterMinNumber = number;
            needToSaveNext = false;
        }

        scanf("%lld", &number);
    }

    if (needToSaveNext) {
        printf("Минимальный элемент - последний в последоавтельности");
    } else if (nextAfterMinNumber == 0) {
        printf("Последовательность пуста");
    } else {
        printf("%lld", nextAfterMinNumber);
    }
}

void thirteen4() {
    SetConsoleOutputCP(CP_UTF8);

    long long number, previousNumber = 0, maxNumber, previousBeforeMaxNumber = 0;

    scanf("%lld", &number);

    while (number) {
        if (number > maxNumber) {
            maxNumber = number;
            previousBeforeMaxNumber = previousNumber;
        }

        previousNumber = number;

        scanf("%lld", &number);
    }

    if (previousNumber == 0) {
        printf("Последовательность пуста");
    } else if (previousBeforeMaxNumber == 0) {
        printf("Максимальный элемент - первый в последовательности");
    } else {
        printf("%lld", previousBeforeMaxNumber);
    }
}

void fourteen4() {
    char character;
    int letterAmount = 0;

    while ((character = getchar()) != '\n') {
        if (isLetter(character)) {
            letterAmount++;
        }
    }

    printf("%d", letterAmount);
}

void fifteen4() {
    char character;
    int consonantLetterAmount = 0;

    while ((character = getchar()) != '\n') {
        if (isConsonantLetter(character)) {
            consonantLetterAmount++;
        }
    }

    printf("%d", consonantLetterAmount);
}

void sixteen4() {
    SetConsoleOutputCP(CP_UTF8);

    long long number, previousNumber;
    bool ascending = false,
            descending = false,
            equality = false;

    scanf("%lld", &number);

    previousNumber = number;

    while (number) {
        if (number < previousNumber) {
            previousNumber = number;
            descending = true;
        } else if (number > previousNumber) {
            previousNumber = number;
            ascending = true;
        } else if (descending || ascending) {
            equality = false;
        } else {
            equality = true;
        }

        scanf("%lld", &number);

        if (number != previousNumber && number) {
            equality = false;
        }
    }

    if (descending && !ascending && !equality) {
        printf("Невозрастающая последовательность");
    } else if (!descending && ascending && !equality) {
        printf("Неубывающая последовательность");
    } else if (!descending && !ascending && equality) {
        printf("Все элементы последовательности равны");
    } else {
        printf("Последовательность не принадлежит ни к какой из групп");
    }
}

void seventeen4() {
    char character;
    int digitSum = 0;

    while ((character = getchar()) != '.') {
        if (isDigit(character)) {
            digitSum += character - '0';
        }
    }

    printf("%d", digitSum);
}

void eighteen4() {
    char character;
    long long number = 0,
            numberSum = 0;
    bool last = false;

    while ((character = getchar()) != '.') {
        if (character != ' ') {
            number = number * 10 + (character - '0');
            last = true;
        } else {
            numberSum += number;
            number = 0;
            last = false;
        }
    }

    if (last) {
        numberSum += number;
    }

    printf("%lld", numberSum);
}

void nineteen4() {
    SetConsoleOutputCP(CP_UTF8);

    double firstNumber;

    scanf("%lf", &firstNumber);

    if (firstNumber == 0) {
        printf("Последовательность пуста");

        return;
    }

    double secondNumber;
    scanf("%lf", &secondNumber);

    if (secondNumber == 0) {
        printf("Последовательность состоит из одного числа");

        return;
    }

    bool progression = true;
    double difference = secondNumber - firstNumber;

    while (secondNumber) {
        if (progression && !fcompare(firstNumber, secondNumber - difference)) {
            progression = false;
        }

        firstNumber = secondNumber;

        scanf("%lf", &secondNumber);
    }

    printf(progression ? "Арифметическая прогрессия" : "Не арифметическая прогрессия");
}