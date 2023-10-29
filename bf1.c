// List Minimum
// By: Dan Shan
// Solved using a visited array 
#include <stdio.h>
int n,v[1001];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        v[in]=1;
    }
    for(int i=0;i<=1000;i++){
        if(v[i])printf("%d\n",i);
    }
}
