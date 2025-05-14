// DMOPC '21 Contest 6 P1 - Bigger Big Integer
// By: Dan Shan
#include <stdio.h>
int main() {
int n;
scanf("%d",&n);
char s[n+1];
scanf("%s",s);
for(int i=1;i<n;i++){
    if(s[i-1]<s[i]){
        char temp = s[i];
        s[i]=s[i-1]; s[i-1]=temp;
        break;
    }
}
printf("%s\n",s);
}
