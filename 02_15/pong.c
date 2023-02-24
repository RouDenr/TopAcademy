#include <stdio.h>

const int x = 41;
const int y = 11;

int is_player(int x, int y, int pl_x, int pl_y) {
    if (x == pl_x) {
        if (y == pl_y || y == pl_y + 1 || y == pl_y - 1) {
            return 1;
        }
    }
    return 0;
}

void print_pole(int x, int y,
                int pl_x, int pl_y,
                int pl_2_x, int pl_2_y,
                int b_x, int b_y) {

    for (int i = 0; i <= y; ++i) {

        for (int j = 0; j <= x; ++j) {
            if (i == 0 || i == y) {
                // std::cout << "*";
                printf("*");
            } else if (j == 0 || j == x) {
                printf("*");
            } else if (is_player(j, i, pl_x, pl_y)) {
                printf("|");
                // std::cout << "|";
            } else if (is_player(j, i, pl_2_x, pl_2_y)) {
                printf("|");
                // std::cout << "|";
            } else if (i == b_y && j == b_x) {
                printf("@");
                // std::cout << "@";
            } else {
                printf(" ");
                // std::cout << " ";
            }
        }
        printf("\n");
        // std::cout << "\n";
    }
}

void move_ball(int *b_x, int *b_y,
                int pl_x, int pl_y,
                int pl_2_x, int pl_2_y,
                int *dir_x) {
    *b_x += *dir_x;

    if (is_player(*b_x, *b_y, pl_x + 1, pl_y)) {
        *dir_x = -*dir_x;
    } else if (is_player(*b_x, *b_y, pl_2_x - 1, pl_2_y)) {
        *dir_x = -*dir_x;
    } else if (b_x <= 0 || b_x >= x ) {
        *b_x = x / 2;
        *b_y = y / 2;
    }

}

int main() {


    int pl_x = 2;
    int pl_y = y / 2;

    int pl_2_x = x - 2;
    int pl_2_y = y / 2;

    int b_x = x / 2;
    int b_y = y / 2;

    int dir_x = -1;

    int end = 0;

    while (!end) {

        print_pole(x, y, pl_x, pl_y, pl_2_x, pl_2_y, b_x, b_y);

        char in;
        in = getchar();
        // std::cin >> in;
        if (in == 'a') {
            if (pl_y > 2)
                pl_y--;
        } else if (in == 'z') {
            if (pl_y < y - 2)
                pl_y++;
        } else if (in == 'q') {
            end = 1;
        }

        move_ball(&b_x, &b_y, pl_x, pl_y, pl_2_x, pl_2_y, &dir_x);

        system("clear");
    }
    return 0;
}

