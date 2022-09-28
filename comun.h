#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct // initializam structura ce contine baza de date
{
    char URL[51],titlu[51],*continut;
    int nr_acc,checks,bites;
}inceput;

inceput *incarcare(int*, int*);  
void curatare(inceput*, inceput**, int);