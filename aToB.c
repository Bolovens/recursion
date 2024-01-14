#include <stdio.h>
#include <string.h>

int collatz(long long int a, long long int b, char *result) {
    if (a == b) {
        strcpy(result, "YES");
        return 1;
    } else if (a == 1) {
        return 1;
    }

    if (a % 2 == 0) {
        a /= 2;
    } else {
        a = a * 3 + 1;
    }

    return collatz(a, b, result);
}

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        long long int a, b;

        char result[4] = "NO";
        scanf("%lld %lld", &a, &b);

        int run = collatz(a, b, result);
        printf("Case #%d: %s\n", i, result);
    }
    
    return 0;
}