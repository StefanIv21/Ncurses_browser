#include "comun.h"
// functie de incarcare in memoria datele site -urilor
// returneaza un pointer unde sunt salvate date site -urilor
// d-dimensiunea vectorului alocat dinamic
// nrsite-numar de elemente din vector
inceput* incarcare(int *d, int *nrsite) 
{
   int i = 0,poz = 0,dim = 3;
   char fisier[31], totul[1000]="", linie[101]; // in vectorul  "fisier" retinem liniile citite,in "totul" copiem tot continul unui site,iar in "linie" retinem fiecare linie din site ul citit
   inceput  *a=(inceput*) malloc (3 * sizeof(inceput)); // alocam dinamic vectorul de tip inceput
   FILE *fp;
   FILE *f;
   fp = fopen("master.txt", "r"); // deschidem fisierul master.txt
   while(fgets(fisier , 30, fp) != NULL) // citim fiecare linie 
   {
      if(fisier[strlen(fisier) - 1] == '\n')
      fisier[strlen(fisier) - 1] = '\0';
      f = fopen(fisier,"r"); // deschidem site -urile citite
      if(poz == dim){ // alocam dinamic vectorul de inceput "a" in caz ca am ajuns la dimensiune maxima
         dim = dim + 3;
         a = (inceput*) realloc (a, dim * sizeof(inceput));
      }
      fscanf(f, "%s %d %d %d",a[i].URL  ,&a[i].bites,  &a[i].nr_acc,  &a[i].checks);
      while(fgets(linie, 100, f) !=  NULL)  // citim fiecare linie din site 
      {
         strcat(totul, linie);  // concatenam continutul site ului 
      }
      char *aux = totul;
      int count  =0;
      while ((aux = strchr(aux, '>')) != NULL)  // am extras continut care se afla intre al doilea > si al treilea <
      {
      aux++;
      count++;
      if(count == 4)
      {
         a[i].continut=(char*) malloc ( (strlen(aux)+1) * sizeof(char));
         aux[ strchr(aux,'<') - aux ] = 0;
         strcpy(a[i].continut, aux); 
         break;  
      }
      }
      totul[0]='\0';
      i++;
      poz++;
      fclose(f);
   }
   fclose(fp);
   *d = dim;
   *nrsite = i;
   return a;
}
void curatare(inceput *a, inceput **v, int n) {  // functie care elibereaza memoria
   for(int i = 0; i < n; i++)
      free(a[i].continut);
   free(a);
   free(v);
}






