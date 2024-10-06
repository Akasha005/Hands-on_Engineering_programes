# include<stdio.h>
int n,a[10][10];
void min_spa_tree()
{
int i,j,u,v,min,sum,k;
int t[10][2],p[10],d[10],s[10],source;
min=9999;
source=0;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(a[i][j]!=0 && a[i][j]<=min)
{
min=a[i][j];
source=i;
}
}
}
{
for(i=1;i<=n;i++)
d[i]=a[source][i];
s[i]=0;
p[i]=source;
}
s[source]=1;
sum=0;
k=1;
for(i=1;i<n;i++)
{
min=9999;
u=-1;
for(j=1;j<=n;j++)
{
if(s[j]==0)
{
{
if(d[j]<=min)
min=d[j];
u=j;
}
}
}
t[k][1]=u;
t[k][2]=p[u];
k++;
sum+=a[u][p[u]];
s[u]=1;
for(v=1;v<=n;v++)
{
if(s[v]==0 && a[u][v]<d[v])
{
d[v]=a[u][v];
p[v]=u;
}
}
}
if(sum>=9999)
printf("spanning tree does not exits\n");
else
{
printf("spanning tree exists and min spanning tree is \n");
for(i=1;i<n;i++)
{
printf("%d", t[i][1]);
printf(" ");
printf("%d", t[i][2]);
printf("\n");
}
printf("The cost of the spanning tree is %d", sum);
printf("\n");
}
}
int main( )
{
int i,j;
printf("Enter the no of nodes\n");
scanf("%d", &n);
printf("Enter the cost adjacency matrix\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d", &a[i][j]);
}
}
min_spa_tree( );
return 0;
}
