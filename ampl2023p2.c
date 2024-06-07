// Amplitude Hackathon '23 Problem 2 - Gigatron Lag
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
int p[1025];
int main() {
	int n=scan();
    for(int i=0;i<n;i++){
        char s[11];
        scanf("%s",s);
        if(s[0]=='M'){
            int m=0;
            for(int i=1;i<1025;i++) if(p[i]>m) m=p[i];
            printf("%d\n",m);
            continue;
        }
        int x;
        x=scan();
        if(s[0]=='L') {
            if(p[x]>0) printf("%d\n",p[x]);
            else printf("0\n");
        }
        else if(s[0]=='A'){
            if(s[3]=='A'){
                for(int i=1;i<1025;i++)p[i]+=x;
            }
            else{
                int ai=scan();
                p[x]+=ai;
            } 
        }
        else{
            if(s[7]=='A') {
                for(int i=1;i<1025;i++){
                    p[i]-=x;
                    if(p[i]<0)p[i]=0;
                }
            }
            else{
                int ai=scan();
                p[x]-=ai;
                if(p[x]<0) p[x]=0;
            }
        }
    }
}
