#include<stdio.h>
#include<stdlib.h>

int e_prim(int n)
{
    if(n==1)return 0;
    int d;
    for(d=2;d<n/2;d++)
    {
        if(n%d==0)return 0;
    }
    return 1;
}
void  extrage(int *a,int *p,int **m,int n)
{
    int k=0;
    for(int i=0;i<n;i++)

    {
    if(e_prim(m[i][i])==1 )
    {
       a[k]=m[i][i];
       k++;
    }
    }
    *p=k;
}
int main()
{
    int *a,**m,f,b,i,j,n,k;
    scanf("%d",&n);
    m=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    m[i]=(int*)malloc(n*sizeof(int));
    a=(int*)malloc((n*n)*sizeof(int));
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&m[i][j]);
    extrage(a,&k,m,n);
    for(i=0;i<k;i++)
    printf("%d",a[i]);

    return 0;

}