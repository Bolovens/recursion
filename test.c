#include <stdio.h>

int path[8][2] = {
    {-1, 2}, {1,2}, {-2, 1}, {2,1},
    {-2, -1}, {2, -1}, {-1, -2}, {1, -2}
};

int isValid(int xHorse, int yHorse) {
    return (xHorse >= 0 && xHorse < 8 && yHorse >= 0 && yHorse < 8);
}

int search(int board[8][8], int xHorse, int yHorse, int xTarget, int yTarget, int moves) {
    if (board[xHorse][yHorse] == 2 || !isValid(xHorse, yHorse) || board[xHorse][yHorse] == 1 || moves == 6) return moves;

    board[xHorse][yHorse] = 1;

    int result = 0;
    for (int i = 0; i < 8; i++) {
        int x = xHorse + path[i][0];
        int y = yHorse + path[i][1];
        result = search(board, x, y, xTarget, yTarget, moves + 1);
        if (result == 6 || board[x][y] == 2) break;
    }

    return result;
}

int main(int argc, char *argv[]) {
    
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        char horse[3];
        char target[3];

        scanf("%s %s", horse, target);

        int xHorse = horse[0] - 'A';
        int yHorse = horse[1] - '1';

        int xTarget = target[0] - 'A';
        int yTarget = target[1] - '1';

        int board[8][8] = {0};

        board[xTarget][yTarget] = 2;

        int moves = search(board, xHorse, yHorse, xTarget, yTarget, 0);

        printf("Case #%d: %d\n", i, moves);

        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                printf("%d", board[j][k]);
            }
            printf("\n");
        }
    }
    
    return 0;
}