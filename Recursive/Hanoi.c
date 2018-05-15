#include <stdio.h>

void hanoi(int n, char A, char B, char C);
void move(char from, char to);

int main() {
    int n = 3;
    hanoi(n,'A','B','C');
    return 0;
}

void hanoi(int n, char A, char B, char C) {
    if (n == 1)  {
        move(A, C);
        return;
    }
    hanoi(n - 1, A, C, B);
    move(A,C);
    hanoi(n - 1, B, A, C);
}

void move(char from, char to) {
    printf("%c => %c\n", from, to);
}
