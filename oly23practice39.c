// Obsessive Equalizing Disorder
// By: Dan Shan
// we must edit elements in increasing order of index as you can never edit a factor of a number
// we note that 1 is a factor of every index therefore we skip it and use its value as the value to chnage evrything else to
// therefore we start at 2 for each element edit it to index 1 which can't change then adjust its multiples accordingly
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
