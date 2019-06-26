#include <stdio.h>

int main(int argc, char *argv[])
{
    int f0, f1, f2;
    f0 = 0 ; f1 = 1; f2 = 0;
    printf("%d\n",f0);
    printf("%d\n",f1);
    // initialize variables and write the while loop
    while (f2 < 100) {
        f2 = f0 + f1;
        printf("%d\n",f2);
        f0 = f1;
        f1 = f2;;
    }
    
    // Remember to update all variables within the loop

    return 0;
}
