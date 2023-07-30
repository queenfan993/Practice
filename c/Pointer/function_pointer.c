#include <stdio.h>
#include <stdlib.h>

typedef int (*MathFunction)(int, int);

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    MathFunction func_ptr; 
    func_ptr = add; 

    printf("Result: %d\n", func_ptr(3, 2));

    func_ptr = subtract; 
    printf("Result: %d\n", func_ptr(3, 2));

    //without typedef
    int (*operation[2]) (int, int) = {add, subtract};
    //operation[0] = add;
    //operation[1] = subtract;
    printf("Result: %d\n", operation[0](3, 2));
    printf("Result: %d\n", operation[1](3, 2));

    return 0;
}
