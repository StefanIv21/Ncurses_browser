#include "comun.h"
int comparare(const void* s1,const void* s2)
{
    inceput **sa=(inceput**)s1; // convertim s1 la tipul inceput**
    inceput **sb=(inceput**)s2; // convertim s2 la tipul inceput**
    int cmp = strcmp( (*sa)->continut , (*sb)->continut );
    if(cmp == 0)
    {
      return ( (*sa)->nr_acc - (*sb)->nr_acc );
     
     }
    else
    return cmp;
}
int main()
{
    int i, dim;
    inceput *a = incarcare(&dim, &i);  // folosim functia "incarcare" din fisierul comun.c pt a memora in "a" toate datele necesare  preluate din site uri
    char terminator=' ';
    char buffer[30];  // bufferul unde citesc cuvintele date
    char *gasit;  // verific daca x se afla in continutul unui site
    inceput **v= (inceput**)malloc(dim*sizeof(inceput*)); // vector de pointeri la inceput(memorez pointeri la site urile ce contin cuvintele date)
    int nrgasite=0;  // dimensiunea vectorului de pointeri v
    while(terminator!='\n')
    {
        int ok = 1;  // verific ca un site sa nu fie adaugat de 2 ori in v
        scanf("%s",buffer);
        for(int j = 0;j < i; j++)
        {
            int incuv = 1;
            gasit= strstr(a[j].continut, buffer);
            if(gasit)
            {
                if(gasit != a[j].continut)  // verific ca nu se afla la inceput
                {  // veriifc daca cuvantul citit este complet sau parte dintr un alt cuvant 
                    if ('A' <= *(gasit-1) && *(gasit-1) <= 'Z' ) incuv = 0;
                    if('a' <=* (gasit-1)  &&  *(gasit-1) <= 'z' )  incuv = 0;
                }
                if('A' <= *(gasit+strlen(buffer)) &&  *(gasit+strlen(buffer)) <= 'Z' ) incuv = 0;
                if('a' <= *(gasit+strlen(buffer))  && *(gasit+strlen(buffer)) <= 'z' ) incuv = 0;
            }
            else incuv = 0;
            for(int k = 0 ; k < nrgasite ; k++) // daca au acelasi url inseamna ca site ul respectiv a fost deja adaugat in v
                if(strcmp(v[k]->URL, a[j].URL) == 0) ok = 0;
            if(incuv && ok )
            {
                v[nrgasite] = &a[j];
                nrgasite++;
            }
        }
        scanf("%c", &terminator);
    }
    qsort(v , nrgasite, sizeof(inceput*) ,comparare );  // functie de sortare  care ordoneza alfabetic site-urile in funtie de continut si desc dupa nr de  accesari daca au acelasi continut
    for(int j = 0; j < nrgasite; j++)
        printf("%s\n", v[j]->URL);
    curatare(a, v, i);  // eliberez memoria 
    return 0;
    }