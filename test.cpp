#include <iostream>

int main() {
    int x = 0xFFFFFFFA;
    char y = (char)x;
    printf("%x\n", y);

    return 0;
}