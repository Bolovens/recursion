#include <stdio.h>

int fiboCount(int n, int *i) {
    (*i)++;

    if (n == 0){
        return 0;
    } else if (n == 1) {
        return 1;
    }

    return fiboCount(n - 1, i) + fiboCount(n - 2, i);
}

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        int num;
        scanf("%d", &num);

        int count = 0;
        int result = fiboCount(num, &count);
        printf("Case #%d: %d\n", i, count);
    }
    
    return 0;
}