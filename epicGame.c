#include <stdio.h>

int epicGame(long long int number, long long int *count) {
    (*count)++;

    if (number == 1) {
        return number;
    }

    if (number % 2 == 0) {
        number /= 2;
    } else {
        number = number * 3 + 1;
    }

    return epicGame(number, count);
}

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        long long int num;
        scanf("%lld", &num);

        long long int count = 0;
        int result = epicGame(num, &count);
        
        printf("Case #%d: ", i);
        if (count % 2 == 0) {
            printf("Jojo\n");
        } else {
            printf("Lili\n");
        }
    }
    
    return 0;
}