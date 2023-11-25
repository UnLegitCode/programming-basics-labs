#include <stdio.h>
#include <math.h>

long long ceilFrac(long long a, long long b) {
    return a % b ? a / b + 1 : a / b;
}

void one3() {
    float heightAboveWater, horizontalShift;

    scanf("%f %f", &heightAboveWater, &horizontalShift);

    float result = (horizontalShift * horizontalShift - heightAboveWater * heightAboveWater) / (2 * heightAboveWater);

    printf("%f", result);
}

void two3() {
    int evenStepAmount, oddStepAmount;

    scanf("%d %d", &evenStepAmount, &oddStepAmount);

    if ((evenStepAmount == 0 && oddStepAmount == 0) || abs(evenStepAmount - oddStepAmount) > 1) {
        printf("NO");
    } else {
        printf("YES");
    }
}

void three3() {
    int startHours, startMinutes, endHours, endMinutes;

    scanf("%d:%d", &startHours, &startMinutes);
    scanf("%d:%d", &endHours, &endMinutes);

    int startTime = (startHours * 60) + startMinutes;
    int endTime = (endHours * 60) + endMinutes;
    int halfTime = (startTime + endTime) / 2;
    int halfHours = halfTime / 60;
    int halfMinutes = halfTime % 60;

    printf("%02d:%02d", halfHours, halfMinutes);
}

void four3() {
    long long sashaChijikAmount, mashaChijikAmount, coconutPrice;

    scanf("%lld %lld %lld", &sashaChijikAmount, &mashaChijikAmount, &coconutPrice);

    long long coconutAmount = (sashaChijikAmount / coconutPrice) + (mashaChijikAmount / coconutPrice);
    long long sashaChijikRemainder = sashaChijikAmount % coconutPrice;
    long long mashaChijikRemainder = mashaChijikAmount % coconutPrice;
    long long totalRemainder = sashaChijikRemainder + mashaChijikRemainder;
    long long minGivenChijikAmount = 0;

    if (totalRemainder >= coconutPrice) {
        coconutAmount++;
        minGivenChijikAmount = coconutPrice - ((sashaChijikRemainder > mashaChijikRemainder) ? sashaChijikRemainder : mashaChijikRemainder);
    }

    printf("%lld %lld", coconutAmount, minGivenChijikAmount);
}

void five3() {
    int roomAmount, maxRadiatorAmount, minRequiredSectionAmount;

    scanf("%d", &roomAmount);

    for (int i = 0; i < roomAmount; ++i) {
        scanf("%d %d", &maxRadiatorAmount, &minRequiredSectionAmount);

        int maxSections = minRequiredSectionAmount / maxRadiatorAmount;
        int additionalSectionAmount = minRequiredSectionAmount % maxRadiatorAmount;
        int minCost = ((maxSections + 1) * (maxSections + 1)) * additionalSectionAmount +
                      (maxRadiatorAmount - additionalSectionAmount) * maxSections * maxSections;

        printf("%d\n", minCost);
    }
}

void six3() {
    long long startCabinAmount, delegationAmount, cabinConstructionPrice, cabinDestructionPrice;

    scanf("%lld %lld %lld %lld", &startCabinAmount, &delegationAmount, &cabinConstructionPrice, &cabinDestructionPrice);

    long long cost = 0;

    if ((startCabinAmount % delegationAmount) != 0) {
        long long construction = (delegationAmount - startCabinAmount % delegationAmount) * cabinConstructionPrice;
        long long deconstruction = (startCabinAmount % delegationAmount) * cabinDestructionPrice;

        if (construction < deconstruction) {
            cost = construction;
        } else {
            cost = deconstruction;
        }
    }

    printf("%lld", cost);
}

void seven3() {
    int bugDonaldsVisitorAmount, beaverKingVisitorAmount, bothVisitorAmount, studentAmount;

    scanf("%d %d %d %d", &bugDonaldsVisitorAmount, &beaverKingVisitorAmount, &bothVisitorAmount, &studentAmount);

    int firstRestaurant = bugDonaldsVisitorAmount - bothVisitorAmount;
    int secondRestaurant = beaverKingVisitorAmount - bothVisitorAmount;
    int remainingStudent = studentAmount - firstRestaurant - secondRestaurant - bothVisitorAmount;
    int failedExam = -1;

    if (firstRestaurant >= 0 && secondRestaurant >= 0 && remainingStudent > 0) {
        failedExam = remainingStudent;
    }

    printf("%d", failedExam);
}

void eight3() {
    long long dotAmount, square;

    scanf("%lld %lld", &dotAmount, &square);

    long long height = (square > dotAmount) * ceilFrac(square, dotAmount) + (square <= dotAmount);

    printf("%lld", height);
}

void nine3() {
    long long toyAmount, expectedToyPairPrice;

    scanf("%lld %lld", &toyAmount, &expectedToyPairPrice);

    long long wayAmount = 0;

    if (expectedToyPairPrice <= toyAmount) {
        wayAmount = (expectedToyPairPrice - 1) / 2;
    } else if ((expectedToyPairPrice - toyAmount - 1) < ((expectedToyPairPrice - 1) / 2)) {
        wayAmount = (expectedToyPairPrice - 1) / 2 - (expectedToyPairPrice - toyAmount - 1);
    }

    printf("%lld", wayAmount);
}

void ten3() {
    int videoFrameVolume, netSpeed, videoDurationSecs;

    scanf("%d %d %d", &videoFrameVolume, &netSpeed, &videoDurationSecs);

    int seconds = ceilFrac(videoFrameVolume * videoDurationSecs, netSpeed) - videoDurationSecs;

    printf("%d", seconds);
}

void eleven3() {
    int iterations, firstHumanNumber, secondHumanNumber, thirdHumanNumber, humanNumber;

    scanf("%d", &iterations);

    for (int i = 0; i < iterations; ++i) {
        scanf("%d %d %d", &firstHumanNumber, &secondHumanNumber, &thirdHumanNumber);

        int people = 2 * abs(firstHumanNumber - secondHumanNumber);

        if (firstHumanNumber > people || secondHumanNumber > people || thirdHumanNumber > people) {
            humanNumber = -1;
        } else if (thirdHumanNumber < people / 2) {
            humanNumber = thirdHumanNumber + people / 2;
        } else if (thirdHumanNumber > people / 2) {
            humanNumber = thirdHumanNumber - people / 2;
        } else {
            humanNumber = people;
        }

        if (humanNumber > people || humanNumber == firstHumanNumber || humanNumber == secondHumanNumber) {
            humanNumber = -1;
        }

        printf("%d\n", humanNumber);
    }
}

void twelve3() {
    int iterations;
    long long participantAmount, interval, duration, people;

    scanf("%d", &iterations);

    for (int i = 0; i < iterations; ++i) {
        scanf("%lld %lld %lld", &participantAmount, &interval, &duration);

        long long durToInterval = duration / interval;

        if (durToInterval < participantAmount) {
            people = durToInterval * (participantAmount - durToInterval) + (durToInterval - 1) * durToInterval / 2;
        } else {
            people = participantAmount - 1 + (participantAmount - 2) * (participantAmount - 1) / 2;
        }

        printf("%lld\n", people);
    }
}

void thirteen3() {
    int trapdoorAmount, trapdoorNumber, moves;

    scanf("%d %d", &trapdoorAmount, &trapdoorNumber);

    if (trapdoorAmount - trapdoorNumber >= trapdoorNumber) {
        moves = trapdoorAmount * 3 + trapdoorNumber - 1;
    } else {
        moves = trapdoorAmount * 4 - trapdoorNumber;
    }

    printf("%d", moves);
}

void fourteen3() {
    int iterations;
    long long rowAmount, columnAmount, cellNumber, rowPosition, columnPosition, cellPosition;

    scanf("%d", &iterations);

    for (int i = 0; i < iterations; ++i) {
        scanf("%lld %lld %lld", &rowAmount, &columnAmount, &cellNumber);

        rowPosition = (cellNumber % rowAmount) ? (cellNumber / rowAmount + 1) : (cellNumber / rowAmount);
        columnPosition = cellNumber - (1 + (rowPosition - 1) * rowAmount) + 1;
        cellPosition = rowPosition + columnAmount * (columnPosition - 1);

        printf("%lld\n", cellPosition);
    }
}