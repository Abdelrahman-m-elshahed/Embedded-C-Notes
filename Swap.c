#include <stdio.h>

int main(void)
{
    int x,y;
    x = 5;
    y = 6;
    printf("X = %d, Y = %d\n",x,y);
    
    // approach #1 
    #if 0
    int tmp = x;
    x = y;
    y = tmp;
    printf("X = %d, Y = %d\n",x,y);
    #endif 
    
    // approach #2 
    #if 0
    x += y;
    y = x - y;
    x -= y;
    printf("X = %d, Y = %d\n",x,y);
    #endif
    
    // approach #3
    #if 0
    x ^= y;
    y = x ^ y;
    x ^= y; // x = x ^ y;
    printf("X = %d, Y = %d\n",x,y);
    #endif
}