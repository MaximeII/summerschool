#include <stdio.h>
#include "field.h"
#include "pngwriter.h"

#define DX 0.01
#define DY 0.01

void init_field(field *f,int  nx, int ny)
{
    int i, j;
    
    f->nx = nx;
    f->ny = ny;
    f->dx = DX;
    f->dy = DY;
    f->dx2 = DX * DX;
    f->dy2 = DY * DY; 
    
    // Initialize first the zeros
    for (i=0;i<f->nx;i++) {
        for (j=0;j<f->ny;j++) {
            f->data[i][j] = 0.0;
        }
    }

    // Initial conditions for left and right
    for (i=0;i<f->nx;i++) {
        f->data[i][0]  = 20.0;
        f->data[i][f->ny-1] = 70.0;
    }

    // and top and bottom boundaries
    for (j=0;j<f->ny;j++) {
        f->data[0][j]  = 85.0;
        f->data[f->ny-1][j] = 5.0;
    }

}

void Laplacian(field *f) {

    int i,j;
    double laplacian[NX][NY];

    // Zero out the outer boundary of laplacian
    for (i = 0; i < NX; i++) {
        laplacian[i][0] = laplacian[i][NY - 1] = 0.0;
    }
    for (j = 0; i < NY; j++) {
        laplacian[0][j] = laplacian[NX - 1][j] = 0.0;
    }

    // Evaluate the Laplacian
    for (i = 1; i < f->nx - 2; i++) {
        for ( j = 1; j < f->ny - 2; j++) {
            laplacian[i][j] = (f->data[i-1][j] - 2*f->data[i][j] + f->data[i+1][j])/(f->dx2) + (f->data[i][j-1] - 2*f->data[i][j] + f->data[i][j+1])/(f->dy2);
        }
    }

    // Update field
    for (i = 1; i < f->nx - 2; i++) {
        for ( j = 1; j < f->ny - 2; j++) {
            f->data[i][j] = laplacian[i][j];
        }
    }
}


void save_field(field *f) {

    int error_code;

    // Call the png writer routine
    error_code = save_png((double *) f->data, f->nx, f->ny, "datastructures_functions_heat-a_b.png", 'c');

    if (error_code == 0) {
        printf("Wrote the output file datastructures_functions_heat-a_b.png\n");
    } else {
        printf("Error while writing output file datastructures_functions_heat-a_b.png\n");
    }

}



int main(void) {

   field f;

   init_field(&f,NX,NY);
   Laplacian(&f);
   save_field(&f);

   return 0;
}

