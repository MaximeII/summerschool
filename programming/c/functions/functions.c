#include <stdio.h>

void add_one_to_both(int *a, int *b) {
    (*a)++;
    (*b)++;
}


int main(void) {
    int a,b;
    a = 3;
    b = 4;
    add_one_to_both(&a,&b);

    printf(" a = %d, b = %d\n ",a,b);

   return 0;
}
