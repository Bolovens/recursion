#include <stdio.h>

int notFibonacci(int a, int b, int k) {
    if (k == 0) {
        return a;
    } else if (k == 1) {
        return b;
    } else if (k == 2) {
        return a + b;
    }

    return notFibonacci(a, b, k - 1) + notFibonacci(a, b, k - 2);
}

int main(int argc, char *argv[]) {
    int a, b, k;
    scanf("%d %d", &a, &b);
    scanf("%d", &k);

    int result = notFibonacci(a, b, k);
    printf("%d\n", result);
    
    return 0;
}