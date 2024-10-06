#include<stdio.h>
int n,i,j;
int a[10][10];
int p[10][10];
int write_data()
{
printf("the path matrix is shown below\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
    printf("%d",p[i][j]);
printf(" ");
}
printf("\n");
}
return 0;
}
void path_matrix()
{
int i,j,k;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
p[i][j]=a[i][j];
}
for(k=1;k<=n;k++)
{
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(p[i][k]==1&&p[k][j]==1)
p[i][j]=1;
}
}
}
}
int main()
{
printf("enter the no. of nodes\n");
scanf("%d",&n);
printf("enter the adjacency matrix\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
}
}
path_matrix();
write_data();
return 0;
}
