/*
WC '15 Contest 4 J2 - Mission Briefing
Author: Dan Shan
Date: 2025-07-08
1. Create visited array of each agent
2. Update and count agents
*/
#include <stdio.h>
int v[10],c=0;
int main() {
    char s[2001];
    scanf("%s",s);
    for(int i=2;i<2001;++i){
        if(s[i]=='\0') break;
        if(s[i]>'0'&&s[i]<='9'&&s[i-1]=='0'&&s[i-2]=='0') v[s[i]-'0']=1;
    }
    for(int i=1;i<=9;++i) c+=v[i];
    printf("%d\n",c);
}
