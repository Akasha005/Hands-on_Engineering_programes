#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define maxsize 3000
void merge(int a[],int low,int mid,int high)
{
int i,j,k,p;
int b[maxsize];
i=k=low;
j=mid+1;
while(i<=mid && j<=high)
{
if(a[i]<=a[j])
{
b[k]=a[i];
i=i+1;
}
else
{
b[k]=a[j];
j=j+1;
}
k=k+1;
}
if(i>mid)
for(p=j;p<=high;p++)
{
b[k]=a[p];
k=k+1;
}
else
{
for(p=i;p<=mid;p++)
b[k]=a[p];
k=k+1;
}
for(i=low;i<=high;i++)
a[i]=b[i];
}
void mergesort(int a[],int low, int high)
{
int mid;
if(low<high)
{
    usleep(50000);
mid=(low+high)/2;
mergesort(a,low,mid-1);
mergesort(a,mid+1,high);
merge(a,low,mid,high);
}
}
int main()
{
int a[maxsize],i,n;
double runtime=0;
printf("Enter the number of elements to sort\n");
scanf("%d", &n);
srand(1);
for(i=1;i<=n;i++)
a[i]=rand()%100;
printf("The randomly generated numbers are:\n");
for(i=1;i<=n;i++)
printf("%d\n", a[i]);
{
time_t start=time(NULL);
mergesort(a,1,n);
time_t end=time(NULL);
runtime=difftime(end,start);
}
printf("The sorted elements are :\n");
for(i=1;i<=n;i++)
printf("%d\n", a[i]);
printf("Time taken to sort=%f\n",runtime );
return 0;
}
