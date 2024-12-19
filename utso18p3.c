/*
UTS Open '18 P3 - Restaurants
Author: Dan Shan
Date: 2024-12-18
Sliding window for minimum marked cells in range
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
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
int a[1000001];
int main() {
    int n=scan(),t=scan(),k=scan(),v=scan(),c=0,res=0;
    while(v--){
        int ai=scan();
        a[ai]=1;
    }
    for(int i=1;i<=t;i++){
        c+=a[i];
    }
    for(int i=t;i>0;i--){
        if(c>=k) break;
        if(!a[i]) {
            c++;
            res++;
        }
        a[i]=1;
    }
    for(int i=t+1;i<=n;i++){
        c+=a[i];
        c-=a[i-t];
        if(c<k){
            c++; res++;
            a[i]=1;
        }
    }
    printf("%d\n",res);
}
