#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int root) {
    int largest = root; 
    int left = 2 * root + 1; 
    int right = 2 * root + 2; 


    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }


    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }


    if (largest != root) {
        swap(&arr[root], &arr[largest]);
        heapify(arr, size, largest);
    }
}


void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); 
        heapify(arr, i, 0); 
    }
}


int main() {
    int arr[] = {6, 2, 8, 1, 4, 9, 3, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("origin：");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapSort(arr, size);

    printf("sorted：");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}