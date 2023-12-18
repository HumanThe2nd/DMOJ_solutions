// Excel Column Index
// By: Dan Shan
#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
char s[13];
scanf("%s",s);
int l = strlen(s);
long long int c=0;
for(int i=l;i>0;i--){
    c+=(s[i-1]-'A'+1)*(long long int)pow(26,l-i);
}
printf("%lld\n",c);
}
