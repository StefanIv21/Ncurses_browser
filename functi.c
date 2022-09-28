
#include "functi.h"
int task2(site *sites2,site *sites,int n,int nr,char cuv[][50])
{
    int i,j,k=0;
    char *gasit;
    for(i=0; i<n; i++)
    {
        int ok=0;
        for(j=0; j<nr; j++)
        {
            int incuv=1;
             gasit= strstr(sites[i].continut, cuv[j]);
            if(gasit)
            {
                if(gasit != sites[i].continut)  
                {  
                    if ('A' <= *(gasit-1) && *(gasit-1) <= 'Z' ) incuv = 0;
                    if('a' <=* (gasit-1)  &&  *(gasit-1) <= 'z' )  incuv = 0;
                }
                if('A' <= *(gasit+strlen(cuv[j])) &&  *(gasit+strlen(cuv[j])) <= 'Z' ) incuv = 0;
                if('a' <= *(gasit+strlen(cuv[j]))  && *(gasit+strlen(cuv[j])) <= 'z' ) incuv = 0;
            }
            else incuv = 0;
            if(incuv )
            ok=1;
        }
        if(ok==1)
        {
            sites2[k]=sites[i];
            k++;
        }
    }
    return k;
}
int comp2(site site1, site site2)
{
    int cmp = strcmp(site1.continut,site2.continut);
    if(cmp == 0)
    {
      return ( site1.nr_acc - site1.nr_acc );
     
     }
    else
    return cmp;
   
}

void sortare(site *sort,site *sites2,int n,int (*comp)(site site1, site site2))
{
    int i;
    int ok=1;
    while(ok!=0)
    {
        ok=0;
        for(i=0; i<n-1; i++)
            if(comp(sites2[i],sites2[i+1])>0)
            {
                site aux= sites2[i];
                sites2[i]=sites2[i+1];
                sites2[i+1]=aux;
                ok=1;
            }
    }
    for(i=0; i<n; i++)
        sort[i]=sites2[i]; 
}
int task3(site *sites2,site *sites,int n,int nrsecv,int nrscad,int nr,char cuv[][50],char secv[][20],char scad[][20])
{
    int i,j,k=0;
    char *gasit;
    for(i=0; i<n; i++)
    {
        int ok=0;
        for(j=0; j<nrsecv; j++)
            if(strstr(sites[i].continut,secv[j])!=0)
                ok=1;
        for(j=0; j<nr; j++)
        {
            int incuv=1;
             gasit= strstr(sites[i].continut, cuv[j]);
            if(gasit)
            {
                if(gasit != sites[i].continut)  
                {  
                    if ('A' <= *(gasit-1) && *(gasit-1) <= 'Z' ) incuv = 0;
                    if('a' <=* (gasit-1)  &&  *(gasit-1) <= 'z' )  incuv = 0;
                }
                if('A' <= *(gasit+strlen(cuv[j])) &&  *(gasit+strlen(cuv[j])) <= 'Z' ) incuv = 0;
                if('a' <= *(gasit+strlen(cuv[j]))  && *(gasit+strlen(cuv[j])) <= 'z' ) incuv = 0;
            }
            else incuv = 0;
            if(incuv )
            ok=1;
        }
        for(j=0; j<nrscad; j++)
        {
            int incuv=1;
             gasit= strstr(sites[i].continut, scad[j]);
            if(gasit)
            {
                if(gasit != sites[i].continut) 
                {  
                    if ('A' <= *(gasit-1) && *(gasit-1) <= 'Z' ) incuv = 0;
                    if('a' <=* (gasit-1)  &&  *(gasit-1) <= 'z' )  incuv = 0;
                }
                if('A' <= *(gasit+strlen(scad[j])) &&  *(gasit+strlen(scad[j])) <= 'Z' ) incuv = 0;
                if('a' <= *(gasit+strlen(scad[j]))  && *(gasit+strlen(scad[j])) <= 'z' ) incuv = 0;
            }
            else incuv = 0;
            if(incuv)
            ok=0;
        }
        if(ok==1)
        {
            sites2[k]=sites[i];
            k++;
        }
    }
    return k;
}
int comp3(site site1, site site2)
{
       return -(site1.nr_acc-site2.nr_acc);
}
void print(site sites)
{
    if(has_colors()==FALSE)
    {
        endwin();
        exit(1);
    }
    start_color();
    int culoare=0;
    init_pair(5,COLOR_WHITE,COLOR_BLACK);culoare=5;
    if(strcmp(sites.colour,"red")==0)
    {
        init_pair(1,COLOR_RED,COLOR_BLUE);culoare=1;
    }
    else if(strcmp(sites.colour,"green")==0)
    {
        init_pair(2,COLOR_GREEN,COLOR_WHITE);culoare=2;
    }
    else{
     
    
    if(strcmp(sites.background,"blue")==0)
    {
            init_pair(3,COLOR_WHITE,COLOR_BLUE);culoare=3;
    }
    if(strcmp(sites.background,"yellow")==0)
    {
            init_pair(4,COLOR_WHITE,COLOR_YELLOW);culoare=4;
    }
        
    }
    
    if(culoare==0) 
    {
        clear();
        attron(A_BOLD);
        mvprintw(0,30,sites.titlu);
        attroff(A_BOLD);
        mvprintw(1,0,sites.continut);
        mvprintw(15,35,"Legenda");
        mvprintw(16,10,"b:Back");
        int letter;
        while(1)
        {
            letter=getch();
            if(letter=='b')
            break;
        }
        refresh();
    }
    else   
    {
        clear();
        attron(A_BOLD);
        mvprintw(0,30,sites.titlu);
        attroff(A_BOLD);
        attron(COLOR_PAIR(culoare));
        mvprintw(1,0,sites.continut);
        attroff(COLOR_PAIR(culoare));
        mvprintw(15,35,"Legenda");
        mvprintw(17,10,"b:Back");
        refresh();
        int letter;
        while(1)
        {
            letter=getch();
            if(letter=='b')
            break;
        }
    }
}
void found(site *sort,char input[],int n,char cuv[][50])
{
    if(n==0)
    {
        clear();
        mvprintw(0,20,"Sorry, B to return.");
        refresh();
        int letter1=0;
        while(1)
            {
                letter1=getch();
                if(letter1=='b')
                break;
            }
    }
    else{
        clear();
        int i=0;
        int current=0;
        int letter=0;
        mvprintw(0,10,"Sites containing ");
        mvprintw(0,28,input);
        mvprintw(0,28+strlen(input),":");
        for(i=0;i<n;i++)
            {
                 mvprintw((i+1)*3,14,sort[i].URL);
                 mvprintw((i+1)*3,15+strlen(sort[i].URL),sort[i].titlu);
            }
        mvprintw(3,7,"->");
        mvprintw(30,20,"Legenda:");
        mvprintw(33,10,"b:Back");
        mvprintw(34,10,"Up,Down");
        refresh();
        while(1)
        {
            letter=getch();
            if(letter=='b')
                break;
            if(letter== KEY_UP)
                {
                    if(current>0)
                    current--;
                else
                    current=n-1;
                }
            if(letter== KEY_DOWN)
                current=(current+1)%n;
            if(letter=='\n')
            {
                print(sort[current]);
                clear();
                mvprintw(0,10,"Sites containing ");
                mvprintw(0,28,input);
                mvprintw(0,28+strlen(input),":");
                for(i=0;i<n;i++)
                {
                    mvprintw((i+1)*3,14,sort[i].URL);
                    mvprintw((i+1)*3,15+strlen(sort[i].URL),sort[i].titlu);
                }
                mvprintw(30,20,"Legenda:");
                mvprintw(33,10,"b:Back");
                mvprintw(34,10,"Up,Down");
                refresh();
            }
            for(i=0;i<n;i++)
                mvprintw(3*(i+1),7,"  ");
            mvprintw(3*(current+1),7,"->");
            refresh();
        }
    }
}
void simple(site *sites,char input[],int n)
{
    site *sites2;
    char cuvinte[10][50];
    int i=0,k=0;
    char *p=strtok(input," ");
    while(p != NULL)
    {
        if(p[0]=='-')
            p=strtok(NULL," ");
        else
            strcpy(cuvinte[i],p);
        p=strtok(NULL," ");
        i++;
    }
    sites2=malloc(n*sizeof(site));
    k=task2(sites2,sites,n,i,cuvinte);
    site *sorted = malloc(k*sizeof(site));
    int (*cmp2)(site,site) = comp2;
    sortare(sorted,sites2,k,cmp2);
    found(sorted,input,k,cuvinte);
    free(sorted);
    free(sites2);

}
void advance(site *sites, char input[],int n)
{
     int k=0;
     site *sites2;
    char cuvinte[10][50],secv[10][20],scad[10][20];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<20;j++)
        {
            secv[i][j]=0;
            cuvinte[i][j]=0;
            scad[i][j]=0;
        }
    }
    int nr=0,nrsecv=0,nrscad=0;
    char *p=strtok(input," ");
    while(p != NULL)
    {
        if(p[0]=='"')
        {
            strcat(secv[nrsecv],p+1);
            while(p[strlen(p)-1]!='"')
            {
                p=strtok(NULL," ");
                if(p[strlen(p)-1]!='"')
                    strcat(secv[nrsecv],p);
                strcat(secv[nrsecv]," ");
            }
            p[strlen(p)-1]='\0';
            strcat(secv[nrsecv],p);
            nrsecv++;
        }
        else if(p[0]=='-')
            strcpy(scad[nrscad++],p+1);
        else strcpy(cuvinte[nr++],p);
        p=strtok(NULL," ");
    }
    sites2=malloc(n*sizeof(site));
    k=task3(sites2,sites,n,nrsecv,nrscad,nr,cuvinte,secv,scad);
    site *sorted;
    sorted=malloc(k*sizeof(site));
    int (*cmp3)(site,site)=comp3;
    sortare(sorted,sites2,k,cmp3);
    found(sorted,input,k,cuvinte);
    free(sorted);
    free(sites2);
}
void meniu(site *sites,char input[],int n)
{
    int letter=0;
    clear();
    mvprintw(1,30,"Browser-ul lui Biju");
     mvprintw(15,35,"Legenda:");
     mvprintw(16,10,"s:Simple");
     mvprintw(17,10,"a:Advance");
    refresh();
    while(1)
    {
        letter=getch();
        if(letter=='s')
            {
                simple(sites,input,n);
                break;
            }
        else if(letter='a')
            {
                advance(sites,input,n);
                break;
            }
        else
        {
            clear();
            mvprintw(1,20,"Browser-ul lui Biju");
            mvprintw(20,35,"Legenda:");
            mvprintw(21,10,"s:Simple");
            mvprintw(22,10,"a: Lansati o cautare avansata");
            refresh();
        }

    }
}