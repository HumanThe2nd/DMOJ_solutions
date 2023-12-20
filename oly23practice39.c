// Obsessive Equalizing Disorder
// By: Dan Shan
// we must edit elements in increasing order of index as you can never edit a factor of a number such as 1
// therefore we start at 2 for each element edit inself to match 1 which can't change then adjust its multiples respectively
#include<stdio.h>
int main() {
int n,f;
long long int c=0;
scanf("%d %d",&n,&f);
int a[n];
for(int i=1;i<n;i++){
    scanf("%d",&a[i]);
}
for(int i=1;i<n;i++) {
    if (a[i] == f)continue;
    if (a[i] > f) {
        int d = a[i]-f;
        c+=d;
        for (int j = i; j < n; j+=i+1) {
            a[j]-=d;
        }
    } else {
        int d = f-a[i];
        c+=d;
        for (int j = i; j < n; j+=i+1) {
            a[j]+=d;
        }
    }
}
printf("%lld\n",c);
}
