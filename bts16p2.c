/*
Back To School '16: Paradox
Author: Dan Shan
Date: 2025-03-12
Heavy implmentation
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main(){
    int n,t=0,f=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int ai;
        char si[7];
        scanf("%d",&ai);
        if(ai<4) scanf("%s",si);
        if(ai==1){
            if(si[0]=='t'){
                if(t<1) puts("true"),t=i;
                else puts("false");
            }
            else{
                if(f<1) puts("true"),f=i;
                else puts("false");
            }
        }
        else if(ai==2){
            if(si[0]=='t'){
                if(t>0) puts("true"),t=0;
                else puts("false");
            }
            else{
                if(f>0) puts("true"),f=0;
                else puts("false");
            }
        }
        else if(ai==3){
            if(si[0]=='t'){
                if(!t) puts("-1");
                else if(f) puts("1");
                else puts("0");
            }
            else{
                if(!f) puts("-1");
                else puts("0");
            }
        }
        else{
            if(t&&f) puts("false true");
            else if(t) puts("true");
            else if(f) puts("false");
            else putchar('\n');
        }
    }
}
