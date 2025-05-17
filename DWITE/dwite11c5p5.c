/*
DWITE '11 R5 #5 - Binary Weight
Author: Dan Shan
Date: 2025-02-06
Find first 0 with a preceding 1 and flip
shift all previous 1s to the bottom
Sample:
1111
11: 101
100: 1000
1010: 1100
111: 1011
1000: 10000
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    for(int ti=0;ti<5;ti++){
        int ai,a[32],l=0,p=1,f=0;;
        scanf("%d",&ai);
        while(ai){ // convert to binary
            a[l++]=(ai&1);
            ai>>=1;
        } a[l]=0;
        for(int i=0;i<=l;i++){ // operate
            if(!a[i]&&f){
                a[i]=1;
                for(int j=0;j<i-f;j++) a[j]=1; // move remaining 1s down
                for(int j=i-f;j<i;j++) a[j]=0;
                    break;
                break;
            }
            else if(a[i]&&!f) f=i+1;
        } if(a[l]) l++;
        ai=0;
        for(int i=0;i<l;i++){ // revert
        ai+=a[i]*p; p<<=1;
        }
        printf("%d\n",ai);
    }
}
