#include <stdio.h>

int main(void)
{
    int x = 8;
    int y = x ^ 1;
    if(y + x == x - 1 || y + x == x + 1)
        printf("Big Endianness\n");
    else
        printf("Little Endianness\n");
}