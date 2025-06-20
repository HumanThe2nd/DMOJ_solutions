// DMOPC '22 Contest 1 P1 - Up-down Sequence
// Author: Dan Shan
// check parity of up/down nodes emitting zeros
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
    int t=scan();
    while(t--){
        int n=scan(),f=1,s=2;
        int q[n+1],l=0,r=0;
        while(n--){
            q[r]=scan();
            if(!q[r]) l=r;
            else if(r-l){
                if(s==2) {
                    if(q[r]>q[r-1])s=(r&1);
                    else s=!(r&1); // mark parity of up node
                }
                if(q[r]==q[r-1]) f=0;
                else if(q[r]>q[r-1]&&s!=(r&1)) f=0;
                else if(q[r]<q[r-1]&&s==(r&1)) f=0;
            }
            r++;
            if(!q[r-1]) l=r;
        }
        printf("%s\n",f?"YES":"NO");
    }
}
