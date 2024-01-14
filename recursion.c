#include <stdio.h>

long long int recursion (long long int number, long long int* counter) {
    if (number == 0) {
        return 1;
    } else if (number ==  1) {
        return 2;
    }  else {
        if (number % 3 == 0) {
            (*counter)++;
        }

        if (number % 5 == 0) {
            return number * 2;
        } else {
            return recursion(number - 1, counter) + number + recursion(number - 2, counter) + number - 2;
        }
    }
}

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);

    for (int i = 0; i < tc; i++) {
        long long int num;
        scanf("%lld", &num);

        long long int counter = 0;
        long long int result = recursion(num, &counter);

        printf("Case #%d: ", i + 1);
        printf("%lld %lld\n", result, counter);
    }
}