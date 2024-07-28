// Back To School '19: H🅰️r🅰️mbe
// Author: Dan Shan
// string length checker
#include <stdio.h>
#include <string.h>
int main() {
    int n,l=0,ind=0;
    scanf("%d",&n);
    char s[n][101],t[101];
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    scanf("%s",t);
    for(int i=0;i<n;i++){
        if(strlen(s[i])>l&&strlen(s[i])<=strlen(t)){
            l=strlen(s[i]); ind=i;
        }
    }
    printf("%s\n",s[ind]);
}
