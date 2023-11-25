#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void printOct(unsigned int number) {
    if (number != 0) {
        printOct(number / 8);
        printf("%d", number % 8);
    }
}

unsigned int deleteOctDigit(unsigned int number, unsigned int digit) {
    unsigned int result = 0, lastOctDigit, k = 0;

    while (number) {
        lastOctDigit = number & 0b111;

        if (lastOctDigit != digit) {
            result |= (lastOctDigit << k);
            k += 3;
        }

        number >>= 3;
    }

    return result;
}

unsigned int swapPairs(unsigned int number) {
    int bitPair, bitAmount = sizeof(int) << 2;
    unsigned int result = 0;
    bool notLastPair;

    for (int i = 0; i < bitAmount; ++i) {
        bitPair = number & 0b11;
        notLastPair = number >> 2;

        if (notLastPair) {
            switch (bitPair) {
                case 1:
                case 2: {
                    bitPair = ~bitPair & 0b11;
                }
            }

            number >>= 2;
        }

        result |= (bitPair << (i << 1));

        if (!notLastPair) break;
    }

    return result;
}

unsigned int invertHex(unsigned int x) {
    unsigned int result = 0;
    int hexSize = sizeof(int) << 1;

    for (int i = hexSize; i > 0; i--) {
        int hex = (x >> (i << 2)) & 0xF;

        if (hex != 0) {
            result = (result << 4) | hex;
        }
    }

    return result;
}

bool isBinPoly(unsigned int x) {
    unsigned int reverseBinX = 0, binX = x, lastDigit;

    while (binX) {
        lastDigit = binX & 1;
        reverseBinX = (reverseBinX << 1) | lastDigit;
        binX >>= 1;
    }

    return x == reverseBinX;
}

unsigned int mergeShorts(unsigned short sh1, unsigned short sh2) {
    unsigned int result = 0;

    for (int i = 0; i < 16; i++) {
        if (sh1 & (1 << i)) {
            result |= (1 << (i << 1));
        }

        if (sh2 & (1 << i)) {
            result |= (1 << ((i << 1) | 1));
        }
    }

    return result;
}

unsigned int getMaxLength(unsigned int x) {
    int unitCounter = 0, maxLength = 0;

    for (; x; x >>= 1) {
        if ((x & 1) && (++unitCounter > maxLength)) {
            maxLength = unitCounter;
        } else {
            unitCounter = 0;
        }
    }

    return maxLength;
}

unsigned int cyclicShift(unsigned int num, int k) {
    unsigned int result = (num << k) | (num >> (32 - k));

    return result;
}

unsigned long long getNumberWithDeleteDigits(unsigned long long x) {
    unsigned long long numberWithDeleteDigits;

    if (x == 1 || x == 2) {
        numberWithDeleteDigits = x >> (x - 1);
    } else {
        int digitsCounter = ceil(log2(x + 1));

        numberWithDeleteDigits = x >> (digitsCounter - 1);

        for (int i = digitsCounter - 3; i >= 0; i -= 2) {
            numberWithDeleteDigits <<= 1;
            numberWithDeleteDigits |= ((x >> i) & 1);
        }
    }

    return numberWithDeleteDigits;
}

unsigned char reverseByte(unsigned char byte) {
    unsigned char result = 0;

    for (int i = 0; i < 8; i++) {
        result = (result << 1) | (byte & 1);
        byte = byte >> 1;
    }

    return result;
}

void codeForces() {
    int coinAmount;

    scanf("%d", &coinAmount);

    int minPackagesNumber = log2(coinAmount) + 1;

    printf("%d", minPackagesNumber);
}