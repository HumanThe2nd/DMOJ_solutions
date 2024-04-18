// DMOPC '20 Contest 1 P3 - Victor's Algorithm
// By: Dan Shan
#include <stdio.h>
int main() {
    int n,l;
    scanf("%d",&n);
    int a[n],m=-2e9;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>m){
            m=a[i]; l=i;
        }
    }
    long long c=0;
    for(int i=1;i<l;i++){
        if(a[i]<a[i-1]){
            c+=a[i-1]-a[i];
            a[i]=a[i-1];
        }
    }
    for(int i=n-2;i>l;i--){
        if(a[i]<a[i+1]){
            c+=a[i+1]-a[i];
            a[i]=a[i+1];
        }
    }
    printf("%lld\n",c);
}
