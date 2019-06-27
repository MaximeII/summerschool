#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b, c;
    // declare a pointer variable and assign it to address of e.g. a
    int *p = &a;
    a = 4;
    b = 7; 
    // Evaluate expressions using both the original and the pointer variable
    c = 2 * a + b;
    int d = 2 * (*p) + b;  
    // and investigate the value / value pointed to
    printf(" With int: %d\n",c);
    printf(" With pointer: %d\n",d);
    printf(" Adress: %d\n",p);

    return 0;
}
