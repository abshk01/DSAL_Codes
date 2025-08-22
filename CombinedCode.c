// Experiment 2 - Bubble, Selection and Insertion Sort with switch-case
#include <stdio.h>
#define MAXSIZE 100

void BubbleSort();
void SelectionSort();
void InsertionSort();

void swap(int*, int*);
void swapArth(int*, int*);
void swapBit(int*, int*);

int arr[MAXSIZE], size, order;

int main() {
    int choice;

    printf("Enter the number of elements (Max %d): ", MAXSIZE);
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter Element %d -> ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Select sorting algorithm:\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Selection Sort\n");
    printf("3 - Insertion Sort\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);

    printf("Sort order: 1 - Ascending, 2 - Descending\n");
    printf("Enter order (1/2): ");
    scanf("%d", &order);

    switch (choice) {
        case 1:
            printf("\nPerforming Bubble Sort...\n");
            BubbleSort();
            break;
        case 2:
            printf("\nPerforming Selection Sort...\n");
            SelectionSort();
            break;
        case 3:
            printf("\nPerforming Insertion Sort...\n");
            InsertionSort();
            break;
        default:
            printf("Invalid choice! Exiting program.\n");
            return 1;
    }

    printf("\nSorted list:\n");
    for (int i = 0; i < size; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Bubble Sort with no arguments
void BubbleSort() {
    int i, j;

    if (order != 2) {
        if (order != 1) {
            printf("Invalid order selected, defaulting to Ascending order.\n");
        }
        for (i = 0; i < size - 1; i++) {
            for (j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
    } else {
        printf("Sorting in Descending Order\n");
        for (i = 0; i < size - 1; i++) {
            for (j = 0; j < size - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    swapArth(&arr[j], &arr[j + 1]);
                }
            }
        }
    }
}

// Selection Sort with no arguments
void SelectionSort() {
    int i, j, minIndex;

    if (order != 2) {
        if (order != 1) {
            printf("Invalid order selected, defaulting to Ascending order.\n");
        }
        // Ascending Order
        for (i = 0; i < size - 1; i++) {
            minIndex = i;
            for (j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }
            if (minIndex != i) {
                swap(&arr[i], &arr[minIndex]);
            }
        }
    } else {
        printf("Sorting in Descending Order\n");
        // Descending Order
        for (i = 0; i < size - 1; i++) {
            minIndex = i;
            for (j = i + 1; j < size; j++) {
                if (arr[j] > arr[minIndex])
                    minIndex = j;
            }
            if (minIndex != i) {
                swapArth(&arr[i], &arr[minIndex]);
            }
        }
    }
}

// Insertion Sort with no arguments
void InsertionSort() {
    int i, key, j;

    if (order != 2) {
        if (order != 1) {
            printf("Invalid order selected, defaulting to Ascending order.\n");
        }
        // Ascending Order
        for (i = 1; i < size; i++) {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    } else {
        printf("Sorting in Descending Order\n");
        // Descending Order
        for (i = 1; i < size; i++) {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
}

// Swap using temp variable
void swap(int* num1, int* num2) {
    int temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}

// Swap using arithmetic operations
void swapArth(int* num1, int* num2) {
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}

// Swap using bitwise XOR (Unused in current code but kept for reference)
void swapBit(int* num1, int* num2) {
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}
