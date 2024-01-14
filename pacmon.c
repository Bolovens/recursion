#include <stdio.h>

int path[4][2] = {
    {1, 0}, {-1, 0}, {0, -1}, {0, 1}
};

int isValid(int row, int column, int posX, int posY) {
    return (posX >= 0 && posX < row && posY >= 0 && posY < column);
}

void search(char matrix[100][100], int row, int column, int posX, int posY, int *total) {
    if (!isValid(row, column, posX, posY) || matrix[posX][posY] == '#') return;

    if (matrix[posX][posY] == '*') {
        (*total)++;
    }

    matrix[posX][posY] = '#';

    for (int i = 0; i < 4; i++) {
        search(matrix, row, column, posX + path[i][0], posY + path[i][1], total);
    }
}

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        int row, column;
        scanf("%d %d", &row, &column);
        getchar();

        char matrix[100][100];
        int posX, posY;
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < column; k++) {
                scanf("%c", &matrix[j][k]);

                if (matrix[j][k] == 'P') {
                    posX = j;
                    posY = k;
                }
            }
            getchar();
        }

        int total = 0;
        search(matrix, row, column, posX, posY, &total);

        printf("Case #%d: %d\n", i, total);

        // for (int j = 0; j < row; j++) {
        //     for (int k = 0; k < column; k++) {
        //         printf("%c", matrix[j][k]);
        //     }
        //     printf("\n");
        // }
    }
    
    return 0;
}