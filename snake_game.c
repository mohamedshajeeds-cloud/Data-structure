#include <stdio.h>
#include <stdlib.h>
#define W 12
#define H 8
#define MAX 100
int x[MAX], y[MAX];
int len = 3, fx, fy, score = 0;
int onSnake(int a, int b) {
    int i;
    for (i = 0; i < len; i++) {
        if (x[i] == a && y[i] == b)
        return 1;
    }
    return 0;
}
void placeFood() {
    do {
        fx = rand() % W;
        fy = rand() % H;
    } while (onSnake(fx, fy));
}
void draw() {
    int i, j;
    printf("\n");
    for (i = 0; i < W + 2; i++) printf("#");
    printf("\n");
    for (j = 0; j < H; j++) {
        printf("#");
        for (i = 0; i < W; i++) {
            if (i == x[0] && j == y[0]) printf("O");
            else if (onSnake(i, j)) printf("o");
            else if (i == fx && j == fy) printf("*");
            else printf(" ");
        }
        printf("#\n");
    }
    for (i = 0; i < W + 2; i++) printf("#");
    printf("\nScore: %d\n", score);
}
int main() {
    int i, dx = 1, dy = 0, nx, ny;
    char ch;
    srand(1);
    x[0] = 5; y[0] = 4;
    x[1] = 4; y[1] = 4;
    x[2] = 3; y[2] = 4;
    placeFood();
    printf("--- SNAKE GAME ---\n");
    printf("Move: w=Up a=Left s=Down d=Right q=Quit\n");
    while (1) {
        draw();
        printf("Enter move: ");
        scanf(" %c", &ch);
        if (ch == 'q') break;
        if (ch == 'w' && dy != 1)  { dx = 0; dy = -1; }
        else if (ch == 's' && dy != -1) { dx = 0; dy = 1; }
        else if (ch == 'a' && dx != 1)  { dx = -1; dy = 0; }
        else if (ch == 'd' && dx != -1) { dx = 1; dy = 0; }
        nx = x[0] + dx;
        ny = y[0] + dy;
        if (nx < 0 || nx >= W || ny < 0 || ny >= H || onSnake(nx, ny)) {
            printf("\nGAME OVER! Final Score: %d\n", score);
            return 0;
        }
        if (nx == fx && ny == fy) {
            len++;
            score += 10;
            placeFood();
        }
        for (i = len - 1; i > 0; i--) {
            x[i] = x[i - 1];
            y[i] = y[i - 1];
        }
        x[0] = nx;
        y[0] = ny;
    }
    printf("\nGame exited. Final Score: %d\n", score);
    return 0;
}
