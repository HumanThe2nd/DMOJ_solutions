// Cheerio Contest 1 J1 - Pronounceable Words
// Author: Dan Shan
#include <stdio.h>
int main() {
    char s[1001];
    scanf("%s",s);
    int f=s[0]=='a';
    if(s[0]=='e') f=1;
    else if(s[0]=='i') f=1;
    else if(s[0]=='o') f=1;
    else if(s[0]=='u') f=1;
    for(int i=1;i<1001;i++){
        if(s[i]=='\0') break;
        int fi=s[i]=='a';
        if(s[i]=='e') fi=1;
        else if(s[i]=='i') fi=1;
        else if(s[i]=='o') fi=1;
        else if(s[i]=='u') fi=1;
        if(f==fi) return printf("NO\n")*0;
        f=fi;
    }
    printf("YES\n");
}
