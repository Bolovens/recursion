#include <stdio.h>

int odd (int n) {
    if (n == 0) {
        return 0;
    } else if (n % 2 != 0) {
        return 1;
    }

    return odd(n - 2) + odd(n - 1);
}

int main(int argc, char *argv[]) {
    int num;
    scanf("%d", &num);

    int result = odd(num);
    printf("%d\n", result);
    
    return 0;
}