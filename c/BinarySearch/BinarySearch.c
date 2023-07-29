#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    const int target = 7;
    const int index = 2000;

    //general 
    int left = -1, right = index + 1;
    printf("general\n");
    while(left + 1 != right) {
        int mid = (left + right)/2;
        printf("left: %d, mid: %d, right: %d,\n", left, mid, right);
        if(target >= mid) {
            left = mid;
        } else {
            right = mid;
        }  
    }
    int mid = (left + right)/2;
    printf("left: %d, mid: %d, right: %d,\n", left, mid, right);

    /*
    left = -1, right = index;
    printf("mid = left + (right - left)/2\n");
    while(left < right) {
        int mid = left + (right - left)/2;
        printf("left: %d, mid: %d, right: %d,\n", left, mid, right);
        if(target > mid){
            left = mid;
        } else {
            right = mid - 1;
        } 
    }

    left = -1, right = index;
    printf("mid = right - (right - left)/2\n");
    while(left < right) {
        int mid = right - (right - left)/2;
        printf("left: %d, mid: %d, right: %d,\n", left, mid, right);
        if(target > mid){
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    
    left = -1, right = index;
    printf("mid = (left + right)/2\n");
    while(left < right) {
        int mid = (left + right)/2;
        printf("left: %d, mid: %d, right: %d,\n", left, mid, right);
        if(target > mid){
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    */

    return 0;
}
