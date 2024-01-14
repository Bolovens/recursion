#include <stdio.h>

int path[4][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int isValid(int posX, int posY, int row, int column) {
    return (posX >= 0 && posX < row && posY >= 0 && posY < column);
}

void search(char board[100][100], int posX, int posY, int row, int column, int *count) {
    if (!isValid(posX, posY, row, column) || board[posX][posY] == '#') return;

    board[posX][posY] = '#';
    (*count)++;

    for (int i = 0; i < 4; i++) {
        search(board, posX + path[i][0], posY + path[i][1], row, column, count);
    }
}

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        int row, column;
        scanf("%d %d", &row, &column);
        getchar();

        char board[100][100];
        int posX, posY;
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < column; k++) {
                scanf("%c", &board[j][k]);

                if (board[j][k] == 'S') {
                    posX = j;
                    posY = k;
                }
            }
            getchar();
        }

        int moves = -1;
        search(board, posX, posY, row, column, &moves);

        printf("Case #%d: %d\n", i, moves);
    }
    
    return 0;
}