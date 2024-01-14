#include <stdio.h>

int ackermann(int a, int b) {
    if (a == 0) {
        return b += 1;
    } else if (a > 0 && b == 0) {
        return ackermann(a - 1, 1);
    } else if (a > 0 && b > 0) {
        return ackermann(a - 1, ackermann(a, b - 1));
    }
}

int main(int argc, char *argv[]) {
    int a, b;
    scanf("%d %d", &a, &b);

    int result = ackermann(a, b);
    printf("result: %d\n", result);
    return 0;
}