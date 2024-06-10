// Cheerio Contest 1 J2 - Phys Ed Class
// Author: Dan Shan
// Minimum Absolute Difference
#include <stdio.h>
#define abs(a)((a)<0?-(a):(a))
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
int main(int argc, char *argv[]) {
    int n=scan(),t=scan();
    int m=2e9,w=n;
    char s[n][21];
    while(n--){
        scanf("%s",s[n]);
        int ai=scan(); ai=abs(ai-t);
        if(ai<m){
            m=ai; w=n;
        }
    }
    printf("%s\n",s[w]);
}
