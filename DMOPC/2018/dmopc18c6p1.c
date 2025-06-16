/*
DMOPC '18 Contest 6 P1 - DNA or RNA?
Author: Dan Shan
Date: 2025-06-15
1. (non-valid character present) or (U and T present): neither
2. Only U: RNA
3. Only T: DNA
4. Neither U or T: Both
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int n,d=0,r=0;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    for(int i=0;i<n;++i){
        if(s[i]=='T') d=1;
        else if(s[i]=='U') r=1;
        else if(s[i]!='C'&&s[i]!='G'&&s[i]!='A')return !puts("neither");
        if(d&&r) return !puts("neither");
    }
    if(r) puts("RNA");
    else if(d) puts("DNA");
    else puts("both");
}
