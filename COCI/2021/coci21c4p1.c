// COCI '21 Contest 4 #1 Autići
// Author: Dan Shan
// Theory: it is optimal to use the friend with the cheapest part as the center
//         and connecting every other garage to it
// Application: multiply the cheapest by n-1 and add each other road 
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
    int n=scan();
    long long c=0,m=2e9;
    for(int i=0;i<n;i++){
        int ai=scan();
        if(ai<m) m=ai;
        c+=ai;
    }
    printf("%lld\n",c-m+(n-1)*m);
}
