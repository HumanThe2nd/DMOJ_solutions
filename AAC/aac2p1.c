// An Animal Contest 2 P1 - Koala Konundrum
// By: Dan Shan
// count odd freuencies of letters
#include <stdio.h>
int v[26];
int main() {
    int n,c=0;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    for(int i=0;i<n;i++)v[s[i]-'a']++;
    for(int i=0;i<26;i++) if(v[i]&1)c++;
    if(!c)c++;
    printf("%d\n",c);
}
