#include <stdio.h>
#include "util.h"

double binarySearch(int ropeAmount, int pieceAmount, int ropes[]) {
    double result = 0,
           left = 0,
           right = findMax(ropes, ropeAmount);

    while ((right - left) > EPS) {
        const double middle = (left + right) / 2;

        int pieces = 0;

        for (int i = 0; i < ropeAmount; i++) {
            pieces += ropes[i] / middle;
        }

        if (pieces >= pieceAmount) {
            left = middle;
            result = middle;
        } else {
            right = middle;
        }
    }

    return result;
}

int main() {
    int ropeAmount, pieceAmount;

    scanf("%d %d", &ropeAmount, &pieceAmount);

    int* ropes = scanNumArray(ropeAmount);

    printf("%.6f", binarySearch(ropeAmount, pieceAmount, ropes));
}