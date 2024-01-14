#include <stdio.h>

void check(int array[], int index, int length, int total) {
    if (index > length) {
        return;
    }

    total += array[index];

    int count = 0;
    if(index * 2 <= length) {
        check(array, index * 2, length, total);
    } else {
        count++;
    }

    if((index * 2) + 1 <= length) {
        check(array, (index * 2) + 1, length, total);
    } else {
        count++;
    }

    if(count == 2){
        printf("%d\n", total);
    }
}

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        int length;
        scanf("%d", &length);

        int array[length + 5];
        for (int j = 1; j <= length; j++) {
            scanf("%d", &array[j]);
        }

        printf("Case #%d:\n", i);
        check(array, 1, length, 0);
    }
    
    return 0;
}