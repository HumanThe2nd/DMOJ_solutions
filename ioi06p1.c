/*
IOI '06 P1 - Deciphering the Mayan Writing
Author: HumanThe2nd
Date: 2025-04-27
Store frequencies of sliding window through second string
Note: I submitted a GPT modified version of this code on DMOJ which runs faster, below is my original code
Time Complexity: O(46*(S+G)) -> O(S)
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target("avx2") 
int a[26],A[26];
inline int check(){ // if character frequencies match
    for(int i=0;i<26;i++) if(a[i]||A[i]) return 0;
    return 1;
}
int main() {
    int n,m,c=0;
    scanf("%d %d",&n,&m);
    char s[n+1],s2[m+1];
    scanf("%s %s",s,s2);
    for(int i=0;i<n;i++){
        if(s[i]>='a') a[s[i]-'a']++;
        else A[s[i]-'A']++;
    }
    for(int i=0;i<n;i++){
        if(s2[i]>='a') a[s2[i]-'a']--;
        else A[s2[i]-'A']--;
    }
    c+=check();
    for(int i=n;i<m;i++){
        if(s2[i-n]>='a') a[s2[i-n]-'a']++;
        else A[s2[i-n]-'A']++;
        if(s2[i]>='a') a[s2[i]-'a']--;
        else A[s2[i]-'A']--;
        c+=check();
    }
    printf("%d\n",c);
}
