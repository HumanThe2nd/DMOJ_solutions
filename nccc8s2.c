/*
Mock CCC '21 S2 - Colorful Strings
Author: Dan Shan
Date: 2025-01-20
for each character store its frequency
total subsequences = product of each frequency incremented by 1
*/
#include <stdio.h>
long long a[26];
int main(){
    char c=getchar();
    while(c!='\n'){
        a[c-'a']++;
        c=getchar();
    }
    long long res=1;
    for(int i=0;i<26;i++){
        a[i]++;
        res*=a[i];
        res%=1000000007;
    }
    printf("%lld\n",res);
}
