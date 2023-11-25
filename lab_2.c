#include <stdio.h>
#include <math.h>

void one() {
    float lyukWidth, pressesDistance, firstPressSpeed, secondPressSpeed;

    scanf("%f %f %f %f", &lyukWidth, &pressesDistance, &firstPressSpeed, &secondPressSpeed);

    float secondsToDeath = (pressesDistance - lyukWidth) / (firstPressSpeed + secondPressSpeed);

    printf("%f", secondsToDeath);
}

void two() {
    int iterations, sum;

    scanf("%d", &iterations);

    for (int i = 0; i < iterations; ++i) {
        scanf("%d", &sum);

        int one, two;

        switch (sum % 3) {
            case 0: {
                one = two = sum / 3;

                break;
            }
            case 1: {
                two = sum / 3;
                one = two + 1;

                break;
            }
            default: {
                one = sum / 3;
                two = one + 1;
            }
        }

        printf("%d %d\n", one, two);
    }
}

void three() {
    int iterations, vasyaApartmentNumber, otherFloorsApartmentAmount;

    scanf("%d", &iterations);

    for (int i = 0; i < iterations; ++i) {
        scanf("%d %d", &vasyaApartmentNumber, &otherFloorsApartmentAmount);

        int vasyaFloorNumber;

        if (vasyaApartmentNumber <= 2) {
            vasyaFloorNumber = 1;
        } else {
            vasyaApartmentNumber -= 2; //apartment number from second floor
            vasyaFloorNumber = (vasyaApartmentNumber / otherFloorsApartmentAmount) + 1 + ((vasyaApartmentNumber % otherFloorsApartmentAmount) > 0);
        }

        printf("%d\n", vasyaFloorNumber);
    }
}

void four() {
    int iterations, firstRabbitCoordinate, secondRabbitCoordinate, firstRabbitSpeed, secondRabbitSpeed;

    scanf("%d", &iterations);

    for (int i = 0; i < iterations; ++i) {
        scanf("%d %d %d %d", &firstRabbitCoordinate, &secondRabbitCoordinate, &firstRabbitSpeed, &secondRabbitSpeed);

        int totalSpeed = firstRabbitSpeed + secondRabbitSpeed;
        int distance = secondRabbitCoordinate - firstRabbitCoordinate;

        int secondsToMeet;

        if ((distance % totalSpeed) == 0) {
            secondsToMeet = distance / totalSpeed;
        } else {
            secondsToMeet = -1;
        }

        printf("%d\n", secondsToMeet);
    }
}

void five() {
    int iterations, width, height, initialSum;

    scanf("%d", &iterations);

    for (int i = 0; i < iterations; ++i) {
        scanf("%d %d %d", &width, &height, &initialSum);

        int min, max;

        if (width >= height) {
            max = width;
            min = height;
        } else {
            max = height;
            min = width;
        }

        int requiredSum = (max - 1) + ((min - 1) * max);

        printf((initialSum == requiredSum) ? "YES\n" : "NO\n");
    }
}

void six() {
    int lastSequenceElement;

    scanf("%d", &lastSequenceElement);

    if (lastSequenceElement % 2) {
        lastSequenceElement++;
    }

    int sumDifference = (lastSequenceElement / 2) % 2;

    printf("%d", sumDifference);
}

void seven() {
    int minSequenceBound, maxSequenceBound;

    scanf("%d %d", &minSequenceBound, &maxSequenceBound);

    int result;

    if (minSequenceBound == maxSequenceBound) {
        result = minSequenceBound;
    } else if ((minSequenceBound % 3) == 0 && (maxSequenceBound % 3) == 0 && maxSequenceBound - minSequenceBound == 3) {
        result = 3;
    } else {
        result = 2;
    }

    printf("%d", result);
}

void eight() {
    int mashaFloor, egorFloor, liftFloor, stairsSpeed, liftSpeed, liftDoorSpeed;

    scanf("%d %d %d %d %d %d",  &mashaFloor, &egorFloor, &liftFloor, &stairsSpeed, &liftSpeed, &liftDoorSpeed);

    int stairsTime = abs(mashaFloor - egorFloor) * stairsSpeed;
    int liftTime = (abs(mashaFloor - liftFloor) * liftSpeed) + (liftDoorSpeed * 3) + (abs(mashaFloor - egorFloor) * liftSpeed);

    if (liftTime <= stairsTime) {
        printf("YES");
    } else {
        printf("NO");
    }
}

void nine() {
    int stickLength;

    scanf("%d", &stickLength);

    int wayAmount;

    if (stickLength % 2) {
        wayAmount = 0;
    } else {
        wayAmount = stickLength / 4;

        if (stickLength % 4 == 0) {
            wayAmount -= 1;
        }
    }

    printf("%d", wayAmount);
}

void ten() {
    int iterations, number;

    scanf("%d", &iterations);

    for (int i = 0; i < iterations; ++i) {
        scanf("%d", &number);

        int greatestCommonDivisor = number - 1;

        printf("%d 1\n", greatestCommonDivisor);
    }
}

void eleven() {
    int iterations;
    long long firstBunch, secondBunch, thirdBunch;

    scanf("%d", &iterations);

    for (int i = 0; i < iterations; ++i) {
        scanf("%lld %lld %lld", &firstBunch, &secondBunch, &thirdBunch);

        long long sweetAmount = (firstBunch + secondBunch + thirdBunch) / 2;

        printf("%lld\n", sweetAmount);
    }
}

void twelve() {
    long squareWidth, squareLength, tileSize;

    scanf("%ld %ld %ld", &squareWidth, &squareLength, &tileSize);

    long long widthTileAmount = (squareWidth / tileSize) + (1 * ((squareWidth % tileSize) > 0));
    long long lengthTileAmount = (squareLength / tileSize) + (1 * ((squareLength % tileSize) > 0));

    long long tileAmount = widthTileAmount * lengthTileAmount;

    printf("%lld", tileAmount);
}

void thirteen() {
    int schoolAmount;

    scanf("%d", &schoolAmount);

    int minRequiredSum = (schoolAmount - 1) / 2;

    printf("%d", minRequiredSum);
}

void fourteen() {
    long long guestAmount;

    scanf("%lld", &guestAmount);

    long long pizzaConsumerAmount = guestAmount + 1;

    long long cutAmount;

    if (pizzaConsumerAmount == 1) {
        cutAmount = 0;
    } else if (pizzaConsumerAmount % 2) {
        cutAmount = pizzaConsumerAmount;
    } else {
        cutAmount = pizzaConsumerAmount / 2;
    }

    printf("%lld", cutAmount);
}

void fifteen() {
    int iterations, minBound, maxBound, number;

    scanf("%d", &iterations);

    for (int i = 0; i < iterations; ++i) {
        scanf("%d %d %d", &minBound, &maxBound, &number);

        int result;

        if (number < minBound) {
            result = number;
        } else {
            result = number * ((maxBound / number) + 1);
        }

        printf("%d\n", result);
    }
}

void sixteen() {
    int iterations, firstCoinAmount, secondCoinAmount, firstCoinDenomination, requiredSum;

    scanf("%d", &iterations);

    for (int i = 0; i < iterations; ++i) {
        scanf("%d %d %d %d", &firstCoinAmount, &secondCoinAmount, &firstCoinDenomination, &requiredSum);

        int requiredFirstCoinAmount = requiredSum / firstCoinDenomination;
        int requiredSecondCoinAmount = requiredSum - ((requiredFirstCoinAmount > firstCoinAmount ? firstCoinAmount : requiredFirstCoinAmount) * firstCoinDenomination);

        printf(requiredSecondCoinAmount <= secondCoinAmount ? "YES\n" : "NO\n");
    }
}

void seventeen() {
    int iterations;
    long long singleDonutPrice, donutAmountInBox, donutBoxPrice;

    scanf("%d", &iterations);

    for (int i = 0; i < iterations; ++i) {
        scanf("%lld %lld %lld", &singleDonutPrice, &donutAmountInBox, &donutBoxPrice);

        long long resultOne = (singleDonutPrice < donutBoxPrice) ? 1 : -1;
        long long resultTwo = (donutBoxPrice < (singleDonutPrice * donutAmountInBox)) ? donutAmountInBox : -1;

        printf("%lld %lld\n", resultOne, resultTwo);
    }
}

void eightTeen() {
    int iterations;
    long long number, elementAmount;

    scanf("%d", &iterations);

    for (int i = 0; i < iterations; ++i) {
        scanf("%lld %lld", &number, &elementAmount);

        if (((number % 2) == (elementAmount % 2)) && ((elementAmount * elementAmount) <= number)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}

void nineteen() {
    int rectangleX, rectangleY;

    scanf("%d %d", &rectangleX, &rectangleY);

    int totalSize = abs(rectangleX) + abs(rectangleY);
    int firstX, firstY, secondX, secondY;

    if (rectangleX > 0) {
        firstX = 0;
        firstY = rectangleY > 0 ? totalSize : -totalSize;
        secondX = totalSize;
        secondY = 0;
    } else {
        firstX = -totalSize;
        firstY = 0;
        secondX = 0;
        secondY = rectangleY > 0 ? totalSize : -totalSize;
    }

    printf("%d %d %d %d", firstX, firstY, secondX, secondY);
}