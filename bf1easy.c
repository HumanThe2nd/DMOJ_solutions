// List Minimum (Easy)
// By: Dan Shan
// note: we can notice the second line is useless
// print all numbers from 1 to n inclusive
#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)printf("%d ",i);
    printf("%d\n",n);
}
