#include <stdio.h>

int main(int argc, char *argv[])
{
    // declare integers, floats, and doubles
    int a = 3;
    float b = 4.3;
    double c = 3.8932;

    // evaluate expressions, e.g. c = a + 2.5 * b
    double d = a + 2.5 * c;
 
    // and print out results. Try to combine integers, floats
    printf(" a = %d, c = %f, d = a + 2.5 * c = %f\n ", a,c,d);
    // and doubles and investigate what happens in type conversions
    printf(" b = %d\n",b);
    return 0;
}
