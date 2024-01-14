#include <stdio.h>

typedef struct Data {
    int x, y, distance;
} Move;

int path[8][2] = {
    {-1, 2}, {1, 2}, {-2, 1}, {2, 1},
    {-2, -1}, {2, -1}, {-1, -2}, {1, -2}
};

int isValid(int x, int y) {
    return (x >= 0) && (x < 8) && (y >= 0) && (y < 8);
}

int bfs(int xHorse, int yHorse, int xTarget, int yTarget) {
    int visited[8][8] = {0};
    int head = 0, tail = 0;
    Move queue[65];

    queue[head].x = xHorse;
    queue[head].y = yHorse;
    queue[head].distance = 0;
    visited[xHorse][yHorse] = 1;
    tail++;

    while (head < tail) {
        if ((xTarget == queue[head].x) && (yTarget == queue[head].y)) {
            return queue[head].distance;
        }

        for (int i = 0; i < 8; i++) {
            int x = queue[head].x + path[i][0];
            int y = queue[head].y + path[i][1];

            if (!visited[x][y] && isValid(x, y)) {
                visited[x][y] = 1;
                queue[tail].x = x;
                queue[tail].y = y;
                queue[tail].distance = queue[head].distance + 1;
                tail++;
            }
        }

        head++;
    }
}
 
int main(int argc, char *argv[]){
    int tc;
    scanf("%d", &tc);
    getchar();

    for (int i = 1; i <= tc; i++) {
        char horse[3], target[3];
        scanf("%s %s", horse, target);

        int xHorse = horse[0] - 'A';
        int yHorse = horse[1] - '1';
        int xTarget = target[0] - 'A';
        int yTarget = target[1] - '1';

        int result = bfs(xHorse, yHorse, xTarget, yTarget);
        printf("Case #%d: %d\n", i, result);
    }
    
    return 0;
}