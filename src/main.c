//First, wrtite the Parameter(s). Press Enter. Then type in the numbers needed to be sorted. And then press Enter.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include <limits.h>
#define _CRT_SECURE_NO_WARNINGS

int main(int argc, char* argv[])
{
    int swaps, arraySize, reducedSize;
    int from = INT_MIN;

    int to = INT_MAX;
    int numArray[100];
    parseArgs(argc, argv, &from, &to);

    arraySize = parseInput(numArray);

    int copiedArray[100];

    copyArray(copiedArray, numArray, arraySize);
    reducedSize = reducedArraySize(copiedArray, from, to, arraySize);

    int reducedArray[100];

    reduceArray(copiedArray, reducedArray, from, to, arraySize);

    int sortedArray[100];
    copyArray(sortedArray, reducedArray, reducedSize);

    sort(sortedArray, reducedSize);

    printf("Reduced: ");
    printArray(reducedArray, reducedSize);
    printf("Sorted: ");
    printArray(sortedArray, reducedSize);

    swaps = arraycmp(sortedArray, reducedArray, reducedSize);
    system("pause");
    return swaps;
}
void parseArgs(int argc, char* argv[], int* from, int* to)
{
    int i;
    char setFrom = 0;
    char setTo = 0;
    if (argc < 2)
    {
        printf("ERROR: Less than one parameter provided.");
        exit(-1);
        system("pause");
    }

    if (argc > 3)
    {
        printf("ERROR: More than two parameters provided.");
        exit(-2);
        system("pause");
    }

    for (i = 1; i < argc; i++)
    {
        if (strncmp(argv[i], "--from=", 7) == 0)
        {
            if (setFrom == 1)
            {
                printf("ERROR: Same parameter provided more than once.");
                exit(-3);
            }
            if (strlen(argv[i]) > 7)
            {
                *from = atoi(argv[i] + 7);
            }
            else
            {
                *from = 0;
            }

            setFrom = 1;
        }
        else if (strncmp(argv[i], "--to=", 5) == 0)
        {
            if (setTo == 1)
            {
                printf("ERROR: Same parameter provided more than once.");
                exit(-3);
            }
            if (strlen(argv[i]) > 5)
            {
                *to = atoi(argv[i] + 5);
            }
            else
            {
                *to = 0;
            }

            setTo = 1;
        }

    }

    if (setFrom == 0 && setTo == 0)
    {
        printf("ERROR: Invalid parameters provided. Parameters must be in the form --from=<number> and --to=<number>.");
        exit(-4);
    }
}

int parseInput(int* arr)
{
    char reachedEnd = 0;
    int i = 0;
    int j;
    char c[10];
    while (1)
    {
        if (reachedEnd)
        {
            break;
        }
        j = 0;
        while (1)
        {
            if (j > 9)
            {
                printf("ERROR: Entered number too large.");
                exit(-5);
            }
            scanf("%c", &c[j]);
            if (c[j] == '\n')
            {
                c[j] = '\0';
                if (j != 0)
                {
                    arr[i] = atoi(c);
                    i++;
                }
                reachedEnd = 1;
                break;
            }
            if (c[j] == ' ')
            {
                c[j] = '\0';
                arr[i] = atoi(c);
                i++;
                break;
            }
            j++;
        }
    }

    return i;
}

void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void copyArray(int* toArray, int* fromArray, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        toArray[i] = fromArray[i];
    }
}

int reducedArraySize(int* arr, int from, int to, int size)
{
    int newSize = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] > from && arr[i] < to)
        {
            newSize++;
        }
    }
    return newSize;
}

void reduceArray(int* arr, int* newArr, int from, int to, int size)
{
    int i;
    int j = 0;
    printf("Stdout: ");
    for (i = 0; i < size; i++)
    {
        if (arr[i] > from && arr[i] < to)
        {
            newArr[j] = arr[i];
            j++;
        }
        else
        {
            printf("%d ", arr[i]);
        }

    }
    printf("\n");
}

int arraycmp(int* arr1, int* arr2, int size)
{
    int i;
    int swaps = 0;
    for (i = 0; i < size; i++)
    {
        if (arr1[i] != arr2[i])
        {
            swaps++;
        }
    }
    return swaps;
}
