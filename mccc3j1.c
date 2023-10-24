#include<stdio.h>
int main(){
int n,i,j;
scanf("%d %d %d",&n,&i,&j);
double ni = n - i*i;
if(ni<0)ni*=-1;
double nj = n - j*j;
if(nj<0)nj*=-1;
if(nj>ni)printf("1\n");
else printf("2\n");
}
