#include <stdio.h>
#include <string.h>
#include "util.h"

#define MAX_RECIPE_LENGTH 100

void getRecipe(char *recipe, int *n_bread, int *n_sausage, int *n_cheese) {
    int n_ingredients = strlen(recipe);
    *n_bread = 0;
    *n_sausage = 0;
    *n_cheese = 0;
    for (int ingredient_index = 0; ingredient_index < n_ingredients; ingredient_index++) {
        switch (recipe[ingredient_index]) {
            case 'B':
                (*n_bread)++;
                break;
            case 'S':
                (*n_sausage)++;
                break;
            case 'C':
                (*n_cheese)++;
                break;
        }
    }
}

int main() {
    char recipe[MAX_RECIPE_LENGTH + 1];

    int recipeBreadAmount, recipeSausageAmount, recipeCheeseAmount;

    gets(recipe);
    getRecipe(recipe, &recipeBreadAmount, &recipeSausageAmount, &recipeCheeseAmount);

    int breadAmount, sausageAmount, cheeseAmount;

    scanf("%d %d %d", &breadAmount, &sausageAmount, &cheeseAmount);

    int breadPrice, sausagePrice, cheesePrice;

    scanf("%d %d %d", &breadPrice, &sausagePrice, &cheesePrice);

    long long availableMoney = scanLL(),
              left = 0,
              right = availableMoney + breadAmount + sausageAmount + cheeseAmount;

    while ((right - left) > 1) {
        long long middle = left + ((right - left) >> 1),
                  requiredBreadPrice = maxLL((middle * recipeBreadAmount - breadAmount), 0) * breadPrice,
                  requiredSausagePrice = maxLL((middle * recipeSausageAmount - sausageAmount), 0) * sausagePrice,
                  requiredCheesePrice = maxLL((middle * recipeCheeseAmount - cheeseAmount), 0) * cheesePrice;

        if ((requiredBreadPrice + requiredSausagePrice + requiredCheesePrice) <= availableMoney) {
            left = middle;
        } else {
            right = middle;
        }
    }

    printf("%lld", left);
}