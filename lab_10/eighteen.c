#include <stdio.h>
#include "util.h"

int binarySearch(const long long power_heroes[], const int end, const long long number) {
    int left = 0,
        right = end;

    while (left <= right) {
        int middle = left + ((right - left) >> 1);

        if (power_heroes[middle] < number) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return right;
}

int main() {
    int heroAmount = scanInt();
    long long* heroPowers = scanNumArrayLL(heroAmount);
    long long totalPower = sumLL(heroPowers, heroAmount);
    int dragonAmount = scanInt();

    sortLLArray(heroPowers, heroAmount);

    long long dragonProtection, dragonPower, power, firstPrice, secondPrice, position;

    while (dragonAmount--) {
        scanf("%lld %lld", &dragonProtection, &dragonPower);

        position = maxLL(binarySearch(heroPowers, heroAmount - 1, dragonProtection), 0);

        power = heroPowers[position];

        firstPrice = maxLL(dragonPower - (totalPower - power), 0) + maxLL(dragonProtection - power, 0);

        power = heroPowers[maxLL(position + 1, heroAmount - 1)];

        secondPrice = maxLL(dragonPower - (totalPower - power), 0) + maxLL(dragonProtection - power, 0);

        printf("%lld\n", minLL(firstPrice, secondPrice));
    }
}