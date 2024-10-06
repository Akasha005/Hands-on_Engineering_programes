# include <stdio.h>
int a,b,i,j,u,v,n;
int visited[10],edge=1, min, mincost=0, cost[10][10];
void kruskal(int n, int cost[10][10])
{
{
printf("The edge of the spanning tree are \n");
while(edge<n)
for(i=1,min=999;i<=n;i++)
for(j=1;j<=n;j++)
if(cost[i][j]<min)
{
min=cost[i][j];
a=u=i;
b=v=j;
}
while(visited[u])
u=visited[u];
while(visited[v])
v=visited[v];
if(u!=v)
{
edge++;
printf("\n Edge (%d,%d)=%d", a,b,min);
mincost=mincost+min;
visited[v]=u;
}
cost[a][b]=cost[b][a]=999;
}
printf("\n The minimum cost =%d", mincost);
}
int main( )
{
printf("Enter the number of vertices:\n");
scanf("%d", &n);
printf("Enter the cost adjacency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d", &cost[i][j]);
kruskal(n,cost);
return 0;
}
