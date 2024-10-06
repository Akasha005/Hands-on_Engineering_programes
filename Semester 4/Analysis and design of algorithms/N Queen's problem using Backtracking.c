#include<stdio.h>
#include<stdlib.h>
int x[10],n;
int display()
{
int i,j;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
if(x[i]==j)
printf("\tQ");
else
printf("\t x");
printf("\n\n");
}
printf("\n\n");
return 0;
}
int place(int k, int i)
{
int j;
for(j=1;j<=k-1;j++)
if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
return 0;
return 1;
}
int nqueen(int k)
{
int i;
for(i=1;i<=n;i++)
if(place(k,i))
{
x[k]=i;
if(k==n)
display();
nqueen(k+1);
}
}
int main()
{
printf("enter the no. of queens\n");
scanf("%d",&n);
if(n==1||n==2||n==3)
printf(" nqueen solution doesnot exist\n");
else
printf("solution for nqueen\n");
nqueen(1);
}
