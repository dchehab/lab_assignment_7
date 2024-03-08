// David Chehab
// Lab 7 assignment
// 03/08/2024
#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp, total_swaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                // Increment swap count for swapped elements
                swaps[arr[j]]++;
                swaps[arr[j+1]]++;
                total_swaps += 2;
            }
        }
    }
    // Add the total number of swaps
    swaps[0] = total_swaps;
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, min_idx, temp, total_swaps = 0;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the elements
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        // Increment swap count for swapped elements
        swaps[arr[i]]++;
        swaps[arr[min_idx]]++;
        total_swaps += 2;
    }
    // Add the total number of swaps
    swaps[0] = total_swaps;
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    // Initialize swap counts for each possible value
    int swaps1[101] = {0}; // Assuming values range from 0 to 100
    int swaps2[101] = {0};

    // Perform Bubble Sort and track swaps for array1
    bubbleSort(array1, n1, swaps1);
    // Perform Bubble Sort and track swaps for array2
    bubbleSort(array2, n2, swaps2);

    printf("array1:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d\n", array1[i], swaps1[array1[i]]);
    }
    printf("Total number of swaps for array1: %d\n", swaps1[0]); // Total swaps

    printf("\narray2:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d\n", array2[i], swaps2[array2[i]]);
    }
    printf("Total number of swaps for array2: %d\n", swaps2[0]); // Total swaps

    return 0;
}
