// DMOPC '22 Contest 2 P1 - DMOPC Crisis
// By: Dan Shan
#include <stdio.h>
int main() {
    int n,c=0;
    scanf("%d",&n);
    char s[n+1]; s[n]='\0';
    for(int i=0;i<n;i++){
        if(!(i%4)||i%4==1)s[i]='_';
        else {
            s[i]='M';
            c++;
        }
    }
    printf("%d\n%s\n",c,s);
}
