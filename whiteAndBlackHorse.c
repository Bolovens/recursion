#include <stdio.h>

void printBoard(int board[9][9], int x, int y) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isValid(int board[9][9], int x, int y, int horse) {
    if ((x >= 0 && x <= 7 && y >= 0 && y <= 7) || (board[x][y] == horse)) {
        return 1;
    } else {
        return 0;
    }
}

int path[8][2] = {
    {-1, 2}, {1,2}, {-2, 1}, {2,1},
    {-2, -1}, {2, -1}, {-1, -2}, {1, -2}
};

void findPath(int board[9][9], int x, int y, int step, int maxStep, int horse, int *check) {
    if (!isValid(board, x, y, horse) || step > maxStep || *check == 1) {
        return;
    } 

    if (horse == 2 && board[x][y] == 1) {
        *check = 1;
        return;
    }

    board[x][y] = horse;

    for (int i = 0; i < 8; i++) {
        if (isValid(board, x + path[i][0], y + path[i][1], horse)) {
            findPath(board, x + path[i][0], y + path[i][1], step + 1, maxStep, horse, check);
        }
    }
}

int main(int argc, char argv[]) {
    int tc;
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        int pos[9][9] = {0};

        int steps;
        scanf("%d", &steps);
        getchar();

        char horse1[3];
        char horse2[3];
        scanf("%s %s", horse1, horse2);

        int x1, x2, y1, y2;
        x1 = horse1[0] - 'A';
        x2 = horse2[0] - 'A';
        y1 = horse1[1] - '1';
        y2 = horse2[1] - '1';

        pos[x1][y1] = 1;
        pos[x2][y2] = 2;
        
        int check = 0;

        if (steps > 8) {
            steps = 8;
        }
        
        findPath(pos, x1, y1, 0, steps, 1, &check);
        findPath(pos, x2, y2, 0, steps, 2, &check);

        printf("Case #%d: ", i);
        if (check) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}