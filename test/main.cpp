#include <iostream>
#include <stdio.h>
#include <math.h>
void sort(int* a, int length, int* b)
{
int i,j, t1, t;
for(j=0; j<length; j++)
for(i=0; i<length-1-j; i++)
if(a[i]<a[i+1])
{
 t=a[i];
 a[i]=a[i+1];
a[i+1]=t;
t1=b[i];
 b[i]=b[i+1];
 b[i+1]=t1;
 }
}
int main() {
    int n,a[24][2],i=0,j,sum[24],x,y,flag=0,answer,u,index[24];
    scanf("%d %d",&x,&y);
    scanf("%d",&n);
        for(i=0;i<=n;i++){
            scanf("%d %d",&a[i][0],&a[i][1]);
            sum[i]=abs(a[i][0]-x)+abs(a[i][1]-y);
        }
        sort(sum,n,index);
        flag=0;
        for(i=0;i<=n;i++)
        {

           if(flag==0) {

               answer += sum[i];
               flag=1;
           }
           else if(flag==1)
           {
               u=index[i];
               answer = answer+abs(a[u][0]-a[u-1][0])+abs(a[u][1]-a[u-1][1]);
                flag=0;
            }
        }
    printf("%d\n",answer);
    return 0;
}