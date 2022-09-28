#include "comun.h"
int comparare(const void* s1,const void* s2)
{
    inceput **sa=(inceput**)s1; // convertim s1 la tipul inceput**
    inceput **sb=(inceput**)s2; // convertim s2 la tipul inceput**
    //verificam daca pointerii sunt nuli si ii punem la finalul vectorului v
    if(*sa == NULL) return -1;
    if(*sb == NULL) return 1;
    return -((*sa)->nr_acc-(*sb)->nr_acc);
}
int main()
{
  int  i, dim;
  inceput *a = incarcare(&dim, &i);  // folosim functia "incarcare" din fisierul comun.c pt a memora in "a" toate datele necesare  preluate din site uri
  char terminator=' ';
  char buffer[30];  // bufferul unde citesc cuvintele date
  char *gasit;  // verific daca x se afla in continutul unui site
  inceput **v= (inceput**) malloc (dim * sizeof(inceput*));  // vector de pointeri la inceput(memorez pointeri la site urile ce continv cuvintele date)
  int nrgasite = 0;  // dimensiunea vectorului de pointeri v
  while(terminator!='\n')
  {
    int ok=1,elim = 0;  // verific ca un site sa nu fie adaugat de 2 ori in v  ,iar cu "elim"  memorez ce cuvant trebuie eliminat
    char start;  // citesc fiecare caracter de la inceputul unui cuvant
    scanf("%c", &start);
    if(start == '"')
    {
      char ghilimea;  // citesc fiecare caracter din cuvant pana la ghilimea si il pun in x
      scanf("%c", &ghilimea);
      int i = 0;
      while(ghilimea != '"')
      {
        buffer[i] = ghilimea;
        i++;
        scanf("%c", &ghilimea);
      }
    }
    else if(start == '-') 
    {
      scanf("%s", buffer);
      elim = 1;
    }
    else 
    {
      buffer[0] = start;
      scanf("%s", &buffer[1]);
    }
    for(int j=0;j<i;j++)
    {
      int incuv = 1;  // cu incuv veriifc daca cuvantul citit este complet sau parte dintr un alt cuvant
      ok=1; 
      gasit=strstr(a[j].continut, buffer);
      if(gasit)
      {
        if(gasit != a[j].continut)  // verific ca nu se afla la inceput
        {  // veriifc daca cuvantul citit este complet sau parte dintr un alt cuvant 
          if ('A' <=  *(gasit-1)   &&   *(gasit-1)  <=  'Z' )incuv = 0;
          if('a'  <=  *(gasit-1)  &&   *(gasit-1)   <=  'z' )incuv = 0;
        }
        if('A'  <=  *(gasit+strlen(buffer))  &&   *(gasit+strlen(buffer))  <=  'Z') incuv = 0;
        if('a'  <=  *(gasit+strlen(buffer))   &&  *(gasit+strlen(buffer))  <=  'z') incuv = 0;
      }
      else incuv = 0;
      if(!elim) 
      {
        for(int k = 0;k < nrgasite ; k++)  // daca au acelasi url inseamna ca site ul respectiv a fost deja adaugat in v
          if(strcmp(v[k]->URL, a[j].URL)==0) ok = 0;
      }
      if(incuv && ok)
      {
        if(!elim)
        {
          v[nrgasite] = &a[j];
          nrgasite++;
        }
        else 
        {
          for(int y = 0; y < nrgasite ; y++)  // transformam site urile din v care contin cuvantul cu "-" in pointeri nuli
            if(v[y] == &a[j]) v[y]=NULL;
        }
      }
    }
    scanf("%c",&terminator);
  }
  qsort(v ,nrgasite ,sizeof(inceput*) , comparare);  // functie de sortare  care ordoneza  desc site urile dupa  nr de accesari 
  for(int j =0 ;j < nrgasite ; j++)
   if(v[j] != NULL) printf("%s\n", v[j]->URL);
  curatare(a, v, i);  // eliberez memoria
  return 0;
}