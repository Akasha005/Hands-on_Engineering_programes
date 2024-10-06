#include<stdio.h>
void find_indegree(int n,int a[10][10],int indegree[])
{
int i,j,sum;
for(j=1;j<=n;j++)
{
sum=0;
for(i=1;i<=n;i++)
sum=sum+a[i][j];
indegree[j]=sum;
}
}
void topological(int n,int a[10][10])
{
int i,k,u,v,top,t[10],indegree[10],s[10];
find_indegree(n,a,indegree);
top=-1;
k=1;
for(i=1;i<=n;i++)
if(indegree[i]==0)
s[++top]=i;
while(top!=-1)
{
u=s[top--];
t[k++]=u;
for(v=1;v<=n;v++)
{
if(a[u][v]==1)
{
indegree[v]--;
if(indegree[v]==0)
s[++top]=v;
}
}
}
printf("THE TOPOLOGICAL SEQUENCE IS \n");
for(i=1;i<=n;i++)
printf("%d\t",t[i]);
}
int main()
{
int i,j,n,a[10][10];
printf("ENTER THE NUMBER OF NODES\n");
scanf("%d",&n);
printf("ENTER THE ADJACENCY MATRIX\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
topological(n,a);
return 0;
}
