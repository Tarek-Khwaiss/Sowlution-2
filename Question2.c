#include "stdlib.h"
#include "math.h"

// problem 3
void sortedByIndex(int arr[SIZE])
{
    // indexSize is the variable used to know how much should we loop over the number of occurrences
    int indexSize = 0;

    int countArray[COUNT];
    int sortedArray[SIZE];

    // initialize the array
    for (int i = 0; i < COUNT; i++)
    {
        countArray[i] = 0;
    }

    // initializing sortedArray
    for (int i = 0; i < SIZE; i++)
    {
        sortedArray[i] = 0;
    }

    // setting up the count array
    for (int i = 0; i < SIZE; i++)
    {
        countArray[arr[i]] += 1;
    }

    // testing the countArray
    for (int i = 0; i < COUNT; i++)
    {
        printf("%d ", countArray[i]);
    }

    int startPos = 0;

    // sorting countArray
    for (int i = 0; i < COUNT; i++)
    {
        indexSize = countArray[i];

        for (int j = 0; j < indexSize; j++)
        {
            sortedArray[startPos] = i;
            startPos++;
        }
    }

    printf("\n");

    // printing sortedArray
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d", sortedArray[i]);
    }
}

int main()
{
    int given[] = {1,
                   2,
                   2,
                   3,
                   3,
                   3,
                   0,
                   0,
                   0,
                   0,
                   0,
                   0,
                   4,
                   4,
                   4,
                   4,
                   5,
                   5,
                   5,
                   5};
    sortedByIndex(given);
}