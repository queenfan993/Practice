#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* nums, int low, int high) {
    int pivot = nums[high];
    int i = low;
    int j = high - 1;
    
    while (1) {
        while (i <= j && nums[i] <= pivot)
            i++;
        while (i <= j && nums[j] >= pivot)
            j--;

        if (i > j)
            break;
        swap(&nums[i], &nums[j]);
    }
    swap(&nums[high], &nums[i]);
    return i;
}

void quickSort(int* nums, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(nums, low, high);
        quickSort(nums, low, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, high);
    }
}

void printArray(int* nums, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printArray(arr, n);

    return 0;
}