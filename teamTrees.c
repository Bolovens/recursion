#include <stdio.h>

long long int teamTrees(long long int* array, int length, int index) {
    if (index == length) {
        return 0;
    }

    long long int total = array[index];
    return total + teamTrees(array, length, index + 1);
}

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        int length;
        scanf("%d", &length);

        long long int array[length];
        for (int j = 0; j < length; j++) {
            scanf("%lld", &array[j]);
        }

        long long int result = teamTrees(array, length, 0);
        printf("Case #%d: %d\n", i, result);
    }
    
    return 0;
}