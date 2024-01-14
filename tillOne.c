#include <stdio.h>

long long int tillOne(long long int number) {
    if (number == 1) {
        return 1;
    } else if (number % 2 != 0) {
        return tillOne(number - 1) + tillOne(number + 1);
    } else {
        return tillOne(number / 2);
    }
}

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);

    for (int i = 0; i < tc; i++) {
        long long int number;
        scanf("%lld", &number);

        long long int result = tillOne(number);
        printf("Case #%d: %d\n", i + 1, result);
    }
    
    return 0;
}