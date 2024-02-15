#include<stdio.h>
#include<stdlib.h>
int n,k;
int cmp(const void *a, const void *b){
    if((*(int*)a)%k-(*(int*)b)%k==0)
        return (*(int*)a-*(int*)b);
    return ((*(int*)a)%k-(*(int*)b)%k);
}
int main() {
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    for(int i=0;i<n;i++)
        printf("%d%s",a[i],i==n-1?"\n":" ");
}
