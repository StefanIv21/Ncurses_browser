#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <unistd.h>
typedef struct 
{
    char URL[51],titlu[51],*continut,colour[20],background[20];
    int nr_acc,checksum;
}site;

void meniu(site *,char [],int);