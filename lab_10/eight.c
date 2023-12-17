#include <stdio.h>
#include "util.h"

long long binarySearch(const long long power, const long long count_moves, const long long first_move_price, const long long second_move_price) {
    long long left = 0,
              right = count_moves;

    while (left <= right) {
        long long middle = left + ((right - left) >> 1);
        long long summary_price = middle * first_move_price + (count_moves - middle) * second_move_price;
        long long summary_price_after = (middle + 1) * first_move_price + (count_moves - middle - 1) * second_move_price;

        if (summary_price <= power - 1 && summary_price_after >= power) {
            return middle;
        }

        if (summary_price < power) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int main() {
    int inputAmount = scanInt();

    long long power, moveAmount, firstMovePrice, secondMovePrice;

    for (int ind = 0; ind < inputAmount; ind++) {
        scanf("%lld %lld %lld %lld", &power, &moveAmount, &firstMovePrice, &secondMovePrice);

        long long max_first_moves;

        if ((moveAmount * firstMovePrice) <= (power - 1)) {
            max_first_moves = moveAmount;
        } else {
            max_first_moves = binarySearch(power, moveAmount, firstMovePrice, secondMovePrice);
        }

        printf("%lld\n", max_first_moves);
    }
}