#include <stdio.h>
int main() {
    int n,c=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        if(a[i]==a[(i+n/2)%n]) c++;
    }
    printf("%d\n",c);
}
