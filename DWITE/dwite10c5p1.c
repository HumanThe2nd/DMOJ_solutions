// DWITE '10 R5 #1 - Colourful Words
// Author: Dan Shan
#include <stdio.h>
int scan() {
    int num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
int main() {
    for(int ti=0;ti<5;ti++){
        char s[9],s2[9],s3[6];
        int r=0,g=0,b=0;
        scanf("%s %s %s",s,s2,s3);
        for(int i=0;i<6;i++){
            if(s3[i]=='\0') break;
            if(s3[i]=='r')r=1;
            else if(s3[i]=='g')g=1;
            else if(s3[i]=='b')b=1;
        }
        for(int i=0;i<9;i++){
            if(s[i]=='\0') break;
            if((s2[i]=='r'&&r)||(s2[i]=='b'&&b)||(s2[i]=='g'&&g)) putchar_unlocked('_');
            else putchar_unlocked(s[i]);
        }
        putchar_unlocked('\n');
    }
}
