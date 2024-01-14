#include <stdio.h>
#include <string.h>

void palindrome(char *string, char *result, int length, int index) {
    if (index == length / 2) {
        return;
    }

    if (string[index] != string[length - 1 - index]) {
        strcpy(result, "no");
        return;
    } 

    palindrome(string, result, length, index + 1);
}

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);
    getchar();

    for (int i = 0; i < tc; i++) {
        char string[1005];
        scanf("%s", string);
        getchar();

        int length = strlen(string);
        char result[4] = "yes";
        palindrome(string, result, length, 0);
        
        printf("Case #%d: %s\n", i + 1, result);
    }
    
    return 0;
}