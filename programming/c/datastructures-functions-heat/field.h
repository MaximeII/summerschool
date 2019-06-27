#ifndef FIELD_H_
#define FIELD_H_

#define NX 258
#define NY 258

typedef struct {

    int nx;
    int ny;
    double dx;
    double dy;
    double dx2;
    double dy2;
    double data[NX][NY];

} field;

#endif
