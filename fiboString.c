#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *fiboString(int n, char zero[], char first[]) {
    if (n == 1) {
        return strdup(first);
    } else if (n == 0) {
        return strdup(zero);
    } 

    char *result = malloc(10000 * sizeof(char));
    char *left = fiboString(n - 1, zero, first);
    char *right = fiboString(n - 2, zero, first);

    strcpy(result, left);
    strcat(result, right);

    free(left);
    free(right);

    return result;
}
    

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        int n;
        char zero[16], first[16];
        scanf("%d %s %s", &n, zero, first);
        getchar();
        
        char *result = fiboString(n, zero, first);
        printf("Case #%d: %s\n", i, result);

        free(result);
    }
    return 0;
}
