#include <stdio.h>
#include <stdlib.h>


int search(int numbers[], int low, int high, int value) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (numbers[mid] == value) return mid;
        if (numbers[mid] > value) return search(numbers, low, mid - 1, value);

        return search(numbers, mid + 1, high, value);
    }

    return -1;
}


void printArray(int numbers[], int sz) {
    int i;
    printf("Number array : ");
    for (i = 0; i < sz; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(void) {
    int numInputs, countOfNums, value, index;
    FILE* inFile = fopen("input.txt", "r");
    if (inFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fscanf(inFile, "%d\n", &numInputs);

    while (numInputs-- > 0) {
        fscanf(inFile, "%d\n", &countOfNums);
        int* numArray = (int *) malloc(countOfNums * sizeof(int));
        if (numArray == NULL) {
            printf("Memory allocation failed\n");
            fclose(inFile);
            return 1;
        }

        float average = 0;
        for (int i = 0; i < countOfNums; i++) {
            fscanf(inFile, "%d", &value);
            numArray[i] = value;
            average += numArray[i];
        }
        average /= countOfNums;

        printArray(numArray, countOfNums);
        index = search(numArray, 0, countOfNums - 1, (int)average);
        if (index >= 0) {
            printf("Item %d exists in the number array at index %d!\n", (int)average, index);
        } else {
            printf("Item %d does not exist in the number array!\n", (int)average);
        }

        free(numArray);
    }

    fclose(inFile);
    return 0;
}
