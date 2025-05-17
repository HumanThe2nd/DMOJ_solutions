// DWITE '10 R5 #2 - Safe from Rooks
// Author: Dan Shan
// res = empty columns*empty rows
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
        int R=scan(),C=scan(),r=scan();
        int rc[R+1]={},cc[C+1]={};
        for(int i=0;i<r;i++){
            int ri=scan(),ci=scan();
            rc[ri]=1; cc[ci]=1;
        }
        int c=0,c2=0;
        for(int i=1;i<=R;i++) c+=!rc[i];
        for(int i=1;i<=C;i++) c2+=!cc[i];
        printf("%d\n",c*c2);
    }
}
