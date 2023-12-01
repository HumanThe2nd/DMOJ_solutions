// Mock CCC '18 Contest 3 J3/S1 - A String Problem
// By: Dan Shan
// uses ascii values to count letters
#include<stdio.h>
#include <string.h>
char s[101],v[26];
int main() {
    scanf("%s",s);
    int c = strlen(s),m=0,m2=0;
    for(int i=0;i<c;i++){
        v[s[i]-'a']++;
        if(v[s[i]-'a']>m)m=v[s[i]-'a'];
        else if(v[s[i]-'a']>m2)m2=v[s[i]-'a'];
    }
    printf("%d\n",c-m-m2);
}
