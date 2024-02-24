// DMOPC '20 Contest 5 P1 - Home Row
// By: Dan Shan
#include <stdio.h>
const int M = 1e6;
int main() {
    char s[M+1],t[M+1];
    scanf("%s %s",s,t);
    int l1=0,l2=0,m;
    for(int i=0;i<M;i++){
        if(s[i]=='\0')break;
        l1++;
    }
    for(int i=0;i<M;i++){
        if(t[i]=='\0')break;
        l2++;
    }
    m=l1<l2?l1:l2;
    for(int i=0;i<m;i++){
        if(s[i]!=t[i])break;
        l1--;l2--;
    }
    printf("%d\n",l1+l2);
}
