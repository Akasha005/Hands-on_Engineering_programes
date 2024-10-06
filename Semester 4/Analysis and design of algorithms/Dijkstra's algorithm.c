#include<stdio.h>
void dijstra(int n, int v, int cost[10][10], int d[])
{
int count,u,i,j,s[10],min;
for(i=1;i<=n;i++)
{
s[i]=0;
d[i]=cost[v][i];
}
s[v]=1;
d[v]=1;
count=2;
while(count<=n)
{
min=999;
for(j=1;j<=n;j++)
if(d[j]<min && s[j]==0)
{
min=d[j];
u=j;
}
s[u]=1;
count++;
for(j=1;j<=n;j++)
if((d[u]+cost[u][j]<d[j])&&s[j]==0)
d[j]=d[u]+cost[u][j];
}
}
int main( )
{
int n,i,j,v,c[10][10],d[10];
printf("Enter the no of nodes");
scanf("%d", &n);
printf("Enter the cost adjacency matrix\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d", &c[i][j]);
printf("Enter the source vertex");
scanf("%d", &v);
dijstra(n,v,c,d);
printf("The shortest path");
for(j=1;j<=n;j++)
if(j!=v)
printf("\n%d->%d=%d", v,j,d[j]);
return 0;
}
