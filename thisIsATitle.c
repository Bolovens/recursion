#include <stdio.h>
#include <string.h>

void thisIsATitle(char* string, int length, int index, char* result) {
    if (index == length) {
        result[index] = '\0';
        return;
    }

    result[index] = string[length - 1 - index];
    thisIsATitle(string, length, index + 1, result);
}

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);
    getchar();

    for (int i = 1; i <= tc; i++) {
        char string[1005];
        scanf("%[^\n]s", string);
        getchar();

        int length = strlen(string);
        char result[1005];
        thisIsATitle(string, length, 0, result);
        printf("Case #%d: %s\n", i, result);
    }
    
    return 0;
}