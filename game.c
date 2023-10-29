#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include  "function.h"
#include <locale.h>
#define DIGITS 4

int main()
{
    setlocale(LC_ALL, "rus");
    int secretNumber[DIGITS];
    int userInput[DIGITS];
    int bulls, cows;
    int attempts = 0;

    generateSecretNumber(secretNumber);

    while (true)
    {
        getUserInput(userInput);
        attempts++;

        countBullsAndCows(secretNumber, userInput, &bulls, &cows);

        printf ("Быки: %d, Коровы: %d\n", bulls, cows);

        if (bulls == DIGITS)
        {
            printf("Поздравляю! Вы угадали число за %d попыток.\n", attempts);
            break;
        }
    }

    return 0;
}
