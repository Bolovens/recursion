#include <stdio.h>

long long int jojonanci(long long int a, long long int b, long long int k) {
    if (a == 0) {
        return b;
    } else if (a == 1) {
        return k;
    } else if (a == 2) {
        return k - b;
    }

    return jojonanci(a - 1, b, k) - jojonanci(a - 2, b, k);
}

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        long long int a, b, k;
        scanf("%lld %lld %lld", &a, &b, &k);

        long long int result = jojonanci(a, b, k);
        printf("Case #%d: %lld\n", i, result);
    }
    
    return 0;
}