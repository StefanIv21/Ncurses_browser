#include "functi.h"
int main()
{
  int dim=3,poz=0;
  site *sites;
  sites = malloc(dim*(sizeof(site)));
  FILE *master = fopen("master.txt","r");
  char nume[30];
  int i = 0;
  int bites=0;
  while(fgets(nume,30,master))
    {
      char totul[1000],totul2[1000],totul3[1000];
      nume[strlen(nume)-1]=0;
      char linie[100];
      FILE *fisier=fopen(nume,"r");
        if(poz == dim) 
        {
            dim = dim + 3;
            sites=(site*)realloc(sites,dim*sizeof(site));
        }
      fscanf(fisier,"%s %d %d %d \n",sites[i].URL,&bites,&sites[i].nr_acc,&sites[i].checksum);
      totul[0]=0;
      totul2[0]=0;
      totul3[0]=0;
      while(fgets(linie,100,fisier))
      {
        strcat(totul,linie);
        strcat(totul3,linie);
      }
      strcpy(totul2,totul);
     
      char *aux = totul;
      int count = 0;
      while ((aux = strchr(aux, '>')) != NULL)  
        {
          aux++;
          count++;
          if(count == 2)
            {
              aux[strchr(aux, '<') - aux] = 0;
              strcpy(sites[i].titlu,aux); 
              break;
            }
        }
      char *aux2 = totul2;
      count  =0;
      while ((aux2 = strchr(aux2, '>')) != NULL) 
      {
        aux2++;
        count++;
        if(count == 4)
        {
          sites[i].continut=(char*) malloc ( (strlen(aux2)+1) * sizeof(char));
          aux2[ strchr(aux2,'<') - aux2 ] = 0;
          strcpy(sites[i].continut, aux2); 
          break;  
        }
      }
      int ok=1;
      char *culoare1,*culoare2;
    
       char *culb1,*culb2;
       
        if(strstr(totul3,"color:")!=0)
        {
            culoare1=strchr(totul3,'"')+7;
            culoare2=strchr(totul3,';');
            ok=0;
        }
        
        if(ok==0);
          strncpy(sites[i].colour,culoare1,culoare2-culoare1);
        sites[i].colour[culoare2-culoare1]=0;


        int okb=1;
        if(strstr(totul3,"background-color:")!=0)
        {
            culb1=strstr(totul3,"background-color:")+17;
            culb2=strrchr(totul3,';');
            okb=0;
        }        
       
        if(okb=0);
          strncpy(sites[i].background,culb1,culb2-culb1);
        sites[i].background[culb2-culb1]=0;
          
      i++;
      poz++;
      fclose(fisier);
      
    }
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);
    int letter;
    int inputlenght=0;
    char input[43];
    for(int j=0;j<40;j++)
        input[j]=0; 
    mvprintw(5,35,"Legenda:");
    mvprintw(10,12,"c:START");
    mvprintw(11,12,"q:EXIT");
    refresh();
    while(1)
    {
        letter=getch();
        if(letter == 'c')
        {
            clear();
            mvprintw(1,30,"Browser-ul lui Biju");
            mvprintw(5,20,"+-----------------------------------------+");
            mvprintw(7,20,"+-----------------------------------------+");
            mvprintw(6,20,"|");
            mvprintw(6,62,"|");
            mvprintw(15,35,"Legenda:");
            mvprintw(16,10,"q:EXIT");
            mvprintw(17,10,"Enter:AFTER STRING");
            move(6,21);
            refresh();
            break;
        }
        if(letter == 'q')
            break;
    }
    while(1)
    {
      letter=getch();
      if(letter=='q')break;

        else if(letter== KEY_BACKSPACE)
        {
          if(inputlenght>0);
            {
              inputlenght--;
              input[strlen(input)-1]=0;
              mvprintw(6,21,"                                     ");
              mvprintw(6,21,input);
              refresh();
            }
        }
        else if(letter=='\n')
        {
            meniu(sites,input,i);
            clear();
            for(int j=0;j<40;j++)
                input[j]=0; 
            inputlenght=0;  
            mvprintw(1,30,"Browser-ul lui Biju");
            mvprintw(5,20,"+-----------------------------------------+");
            mvprintw(7,20,"+-----------------------------------------+");
            mvprintw(6,20,"|");
            mvprintw(6,62,"|");
            mvprintw(15,35,"Legenda:");
            mvprintw(16,10,"q: EXIT");
            mvprintw(17,10,"Enter:AFTER STRING");
            move(6,21);
            refresh();
        }
        else
        {
        if(inputlenght<38)
          input[inputlenght++]=letter;
        mvprintw(6,21,"                                        ");
        mvprintw(6,21,input);
        } 
    }
    clear();
    endwin();
    for(int j=0;j<i;j++)
	  free(sites[j].continut);
    free(sites);
}