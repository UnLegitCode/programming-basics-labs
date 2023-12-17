#include <stdio.h>
#include "util.h"

/** возвращает число, количество копий, которые можно сделать за время time
* при условии, что быстрый принтер печатает копию за время firstTime, а
* медленный за secondTime
*/
int countCopies(const int firstTime, const int secondTime, const int time) {
    return (time / firstTime) + ((time - firstTime) / secondTime);
}

/**
* возвращает число, минимальное время time, за которое можно сделать
* requiredAmount копий, при условии, что быстрый принтер печатает копию за
* время firstTime, а медленный за secondTime
*/
int findMinTime(const int firstTime, const int secondTime, const int requiredAmount) {
    int left = 0;
    int right = firstTime * requiredAmount;

    while ((left < right) - 1) {
        int middle = left + ((right - left) >> 1);

        if (countCopies(firstTime, secondTime, middle) >= requiredAmount) {
            right = middle;
        } else {
            left = middle;
        }
    }

    return right;
}

int main() {
    int copyAmount, firstTime, secondTime;

    scanf("%d %d %d", &copyAmount, &firstTime, &secondTime);

    printf("%d\n", findMinTime(
            min(firstTime, secondTime),
            max(firstTime, secondTime),
            copyAmount
    ));
}