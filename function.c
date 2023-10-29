#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>

#define DIGITS 4

void generateSecretNumber(int secretNumber[])
{
    int digits[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int maxIndex = 9;

    srand(time(NULL));

    for (int i = 0; i < DIGITS; i++)
    {
        int randomIndex = rand() % (maxIndex + 1);
        secretNumber[i] = digits[randomIndex];
        digits[randomIndex] = digits[maxIndex];
        maxIndex--;
    }
}

int isValidInput(int number)
{
    if (number >= 1000 && number <= 9999)
    {
        return 1;
    }
    else
    {
        printf("Не является четырехзначным числом!\n");
        return 0;
    }
}

void getUserInput(int* userInput)
{
    int number;
    do
    {
        printf("Введите 4-значное число: ");
        scanf_s("%d", &number);
    } while (!isValidInput(number));

    for (int i = DIGITS - 1; i >= 0; i--)
    {
        userInput[i] = number % 10;
        number /= 10;
    }
}

void countBullsAndCows(const int secretNumber[], const int userInput[], int* bulls, int* cows)
{
    *bulls = 0;
    *cows = 0;

    for (int i = 0; i < DIGITS; i++)
    {
        if (secretNumber[i] == userInput[i])
        {
            (*bulls)++;
        }
        else
        {
            for (int j = 0; j < DIGITS; j++)
            {
                if (secretNumber[i] == userInput[j])
                {
                    (*cows)++;
                    break;
                }
            }
        }
    }
}
