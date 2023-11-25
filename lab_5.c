#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}


void one5() {
    int taskAmount, solvedTaskAmount = 0, petyaVoice, vasyaVoice, tonyaVoice;

    scanf("%d", &taskAmount);

    for (int i = 0; i < taskAmount; ++i) {
        scanf("%d %d %d", &petyaVoice, &vasyaVoice, &tonyaVoice);

        solvedTaskAmount += ((petyaVoice + vasyaVoice + tonyaVoice) > 1);
    }

    printf("%d", solvedTaskAmount);
}

void two5() {
    int sourceNumber, subtractionAmount;

    scanf("%d %d", &sourceNumber, &subtractionAmount);

    for (int i = 0; i < subtractionAmount; ++i) {
        if (sourceNumber % 10) {
            sourceNumber--;
        } else {
            sourceNumber /= 10;
        }
    }

    printf("%d", sourceNumber);
}

void three5() {
    int stopAmount, outcoming, incoming, tramCapacity = 0, passengersNumber = 0;

    scanf("%d", &stopAmount);

    for (int i = 1; i <= stopAmount; i++) {
        scanf("%d %d", &outcoming, &incoming);

        passengersNumber = passengersNumber - outcoming + incoming;

        if (passengersNumber > tramCapacity) {
            tramCapacity = passengersNumber;
        }
    }

    printf("%d", tramCapacity);
}

void four5() {
    int friendAmount, fenceHeight, height;

    scanf("%d %d", &friendAmount, &fenceHeight);

    int roadWidth = friendAmount;

    for (int i = 0; i < friendAmount; i++) {
        scanf("%d", &height);

        roadWidth += height > fenceHeight;
    }

    printf("%d", roadWidth);
}

void five5() {
    int roomCount, availableRoomAmount = 0, occupiedPlaceAmount, roomSize;

    scanf("%d", &roomCount);

    for (int i = 1; i <= roomCount; i++) {
        scanf("%d %d", &occupiedPlaceAmount, &roomSize);

        availableRoomAmount += (roomSize - occupiedPlaceAmount) >= 2;
    }

    printf("%d", availableRoomAmount);
}

void six5() {
    int programmerAmount, minParticipiationAmount, participationAmount, potentialParticipiantAmount = 0;

    scanf("%d %d", &programmerAmount, &minParticipiationAmount);

    for (int i = 1; i <= programmerAmount; i++) {
        scanf("%d", &participationAmount);

        potentialParticipiantAmount += (participationAmount + minParticipiationAmount) <= 5;
    }

    int teamAmount = potentialParticipiantAmount / 3;

    printf("%d", teamAmount);
}

void seven5() {
    int performanceAmount, point, amazingPerformancesAmount = 0;

    scanf("%d", &performanceAmount);
    scanf("%d", &point);

    int maxPoint = point, minPoint = point;

    for (int i = 2; i <= performanceAmount; i++) {
        scanf("%d", &point);

        if (point > maxPoint) {
            maxPoint = point;
            amazingPerformancesAmount++;
        } else if (point < minPoint) {
            minPoint = point;
            amazingPerformancesAmount++;
        }
    }

    printf("%d", amazingPerformancesAmount);
}

void eight5() {
    int iterations, pairAmount, setElement;

    scanf("%d", &iterations);

    for (int i = 1; i <= iterations; i++) {
        scanf("%d", &pairAmount);

        int evenNumbers = 0, oddNumbers = 0;

        for (int j = 1; j <= 2 * pairAmount; j++) {
            scanf("%d", &setElement);

            if (setElement % 2) {
                oddNumbers++;
            } else {
                evenNumbers++;
            }
        }

        printf((evenNumbers == pairAmount && oddNumbers == pairAmount) ? "YES\n" : "NO\n");
    }
}

void nine5() {
    int eventAmount, event, unsolvedCrimesCounter = 0, officersCounter = 0;

    scanf("%d", &eventAmount);

    for (int i = 0; i < eventAmount; i++) {
        scanf("%d", &event);

        if (event > 0) {
            officersCounter += event;
        } else if (officersCounter) {
            officersCounter--;
        } else {
            unsolvedCrimesCounter++;
        }
    }

    printf("%d", unsolvedCrimesCounter);
}

void ten5() {
    int sourceNumber;

    scanf("%d", &sourceNumber);

    int simpleNumbersCounter = sourceNumber / 2;
    int oddNumber = sourceNumber % 2;

    printf("%d\n", simpleNumbersCounter);

    for (int i = oddNumber; i < simpleNumbersCounter; i++) {
        printf("2 ");
    }

    if (oddNumber) {
        printf("3");
    }
}

void eleven5() {
    int bobWeight, limakWeight, yearAmount = 0;

    scanf("%d %d", &bobWeight, &limakWeight);

    while (bobWeight <= limakWeight) {
        bobWeight *= 3;
        limakWeight *= 2;
        yearAmount++;
    }

    printf("%d", yearAmount);
}

void twelve5() {
    int iterations, listWidth, listHeight, friendAmount;

    scanf("%d", &iterations);

    for (int i = 1; i <= iterations; i++) {
        scanf("%d %d %d", &listWidth, &listHeight, &friendAmount);

        int sheetAmount = 1;

        while (listWidth % 2 == 0 || listHeight % 2 == 0) {
            if (listWidth % 2 == 0) {
                listWidth >>= 1;
                sheetAmount <<= 1;
            } else if (listHeight % 2 == 0) {
                listHeight >>= 1;
                sheetAmount <<= 1;
            }
        }

        printf(sheetAmount >= friendAmount ? "YES\n" : "NO\n");
    }
}

void thirteen5() {
    int cubeAmount, maxHeight = 0, cubes = 0, totalCubes = 0;

    scanf("%d", &cubeAmount);

    while (totalCubes <= cubeAmount) {
        maxHeight++;
        cubes += maxHeight;
        totalCubes += cubes;
    }

    if (totalCubes > cubeAmount) {
        maxHeight--;
    }

    printf("%d", maxHeight);
}

void fourteen5() {
    int iterations, userAmount, userType;

    scanf("%d", &iterations);

    for (int i = 1; i <= iterations; i++) {
        scanf("%d", &userAmount);

        int likeAmount = 0;

        for (int j = 1; j <= userAmount; j++) {
            scanf("%d", &userType);

            if (userType != 2) {
                likeAmount++;
            }
        }

        printf("%d\n", likeAmount);
    }
}

void fifteen5() {
    int executedCommandAmount, commandType, successPacketAmount, failedPacketAmount;

    scanf("%d", &executedCommandAmount);

    int serverAX = 0, serverAY = 0, serverBX = 0, serverBY = 0;

    for (int i = 1; i <= executedCommandAmount; i++) {
        scanf("%d %d %d", &commandType, &successPacketAmount, &failedPacketAmount);

        switch (commandType) {
            case 1: {
                serverAX += successPacketAmount;
                serverAY += failedPacketAmount;

                break;
            }
            case 2: {
                serverBX += successPacketAmount;
                serverBY += failedPacketAmount;

                break;
            }
        }
    }

    printf(serverAX >= serverAY ? "LIVE\n" : "DEAD\n");
    printf(serverBX >= serverBY ? "LIVE\n" : "DEAD\n");
}

void sixteen5() {
    int iterations, balance;

    scanf("%d", &iterations);

    for (int i = 1; i <= iterations; i++) {
        scanf("%d", &balance);

        int cashback = 0;
        int burlyAmount = balance;

        while (balance >= 10) {
            cashback += balance / 10;
            balance = balance / 10 + balance % 10;
        }

        burlyAmount += cashback;

        printf("%d\n", burlyAmount);
    }
}

void seventeen5() {
    int restaurantAmount, dinnerTime, restaurantPleasure, restaurantDinnerTime;

    scanf("%d %d", &restaurantAmount, &dinnerTime);

    long long pleasure, maxPleasure = -(1LL << 60);

    for (int i = 1; i <= restaurantAmount; i++) {
        scanf("%d %d", &restaurantPleasure, &restaurantDinnerTime);

        if (restaurantDinnerTime > dinnerTime) {
            pleasure = restaurantPleasure - (restaurantDinnerTime - dinnerTime);
        } else {
            pleasure = restaurantPleasure;
        }

        if (pleasure > maxPleasure) {
            maxPleasure = pleasure;
        }
    }

    printf("%lld\n", maxPleasure);
}

void eighteen5() {
    long long numberAmount, number;

    scanf("%lld", &numberAmount);

    for (int i = 0; i < numberAmount; i++) {
        scanf("%lld", &number);

        long long sum = number * (number + 1) >> 1;

        for (int j = 0; j < number; j <<= 1) {
            sum -= (j << 1);
        }

        printf("%lld\n", sum);
    }
}

void nineteen5() {
    int dayAmount, requiredSweetAmount, a;

    scanf("%d %d", &dayAmount, &requiredSweetAmount);

    int dayCounter = 0, totalSweets = 0, sweets = 0;

    for (int i = 1; i <= dayAmount; i++) {
        scanf("%d", &a);

        sweets += a;

        if (sweets >= 8) {
            totalSweets += 8;
            sweets -= 8;
        } else {
            totalSweets += sweets;
            sweets = 0;
        }

        dayCounter++;

        if (totalSweets >= requiredSweetAmount) break;
    }

    if (dayCounter > dayAmount || totalSweets < requiredSweetAmount) {
        printf("-1");
    } else {
        printf("%d", dayCounter);
    }
}

void twenty5() {
    int billDenominationAmount, billDenomination, badAmount = 1;

    scanf("%d", &billDenominationAmount);

    for (int i = 1; i <= billDenominationAmount; i++) {
        scanf("%d", &billDenomination);

        if (billDenomination == 1) {
            badAmount = -1;
        }
    }

    printf("%d", badAmount);
}

void twenty_one5() {
    int dayAmount, raspberryAmount, honeyPrice, previousHoneyPrice, profit, maxProfit = 0;

    scanf("%d %d\n %d", &dayAmount, &raspberryAmount, &previousHoneyPrice);

    for (int i = 2; i <= dayAmount; i++) {
        scanf("%d", &honeyPrice);

        profit = previousHoneyPrice - honeyPrice - raspberryAmount;

        if (profit > maxProfit) {
            maxProfit = profit;
        }

        previousHoneyPrice = honeyPrice;
    }

    printf("%d", maxProfit);
}

void twenty_two5() {
    int setSize, addition, setElement, previousSetElement, minStepsAmount = 0;

    scanf("%d %d %d", &setSize, &addition, &previousSetElement);

    for (int i = 1; i < setSize; i++) {
        scanf("%d", &setElement);

        int increase = 0;

        if (setElement <= previousSetElement) {
            increase = (previousSetElement - setElement) / addition + 1;
            minStepsAmount += increase;
        }

        previousSetElement = setElement + increase * addition;
    }

    printf("%d", minStepsAmount);
}

void twenty_three5() {
    int pairAmount, pairPresense, pairsInUniversityCounter = 0, pairsAtHomeCounter = 0, freePairs = 0;

    scanf("%d", &pairAmount);

    for (int i = 1; i <= pairAmount; i++) {
        scanf("%d", &pairPresense);

        if (pairPresense == 1) {
            pairsInUniversityCounter++;
            pairsAtHomeCounter = 1;

            if (freePairs < 2) {
                pairsInUniversityCounter += freePairs;
            }

            freePairs = 0;
        } else if (pairPresense == 0 && pairsAtHomeCounter == 1) {
            freePairs++;
        }
    }

    printf("%d", pairsInUniversityCounter);
}

void twenty_four5() {
    int numberAmount, number;

    scanf("%d", &numberAmount);

    int positiveNumberSum = 0, maxNegativeOddNumber = -10000, minPositiveOddNumber = 10000;

    for (int i = 1; i <= numberAmount; i++) {
        scanf("%d", &number);

        if (number > 0) {
            positiveNumberSum += number;
            if (number % 2) {
                minPositiveOddNumber = min(number, minPositiveOddNumber);
            }
        } else if (number < 0 && number % 2) {
            maxNegativeOddNumber = max(number, maxNegativeOddNumber);
        }
    }

    if (positiveNumberSum % 2 == 0) {
        positiveNumberSum -= min(minPositiveOddNumber, -maxNegativeOddNumber);
    }

    printf("%d", positiveNumberSum);
}