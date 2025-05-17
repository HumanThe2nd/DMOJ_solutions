// COCI '06 Contest 2 #2 ABC
// Author: Dan Shan
#include <stdio.h>
int main() {
    int a[3];
    char s[4];
    scanf("%d%d%d%s",&a[0],&a[1],&a[2],s);
    if(a[1]<a[0]){
        int t=a[0];
        a[0]=a[1]; a[1]=t;
    }
    if(a[2]<a[0]){
        int t=a[0];
        a[0]=a[2]; a[2]=t;
    }
    if(a[2]<a[1]){
        int t=a[1];
        a[1]=a[2]; a[2]=t;
    }
    printf("%d %d %d\n",a[s[0]-'A'],a[s[1]-'A'],a[s[2]-'A']);
}
