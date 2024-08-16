// DWITE '10 R1 #3 - Power tiles
// Author: Dan Shan
// Theory: sweep larger dimension, remove sweeped rectangle until full rectangle is efficiently sweeped
#include <stdio.h>
int main() {
    for(int ti=0;ti<5;ti++){
        int n,m,c=0;
        scanf("%d %d",&n,&m);
        if(n<m){ // make n the max
            int t=n; 
            n=m; m=t;
        }
        while(m){
            int d=1,s=8192,sl=8192,n2=n,m2=m,ci=0;
            while(n2){
                if(s>m2||s>n2) s>>=1;
                else {
                    if(!ci) {
                        sl=s; m-=s; // subtract used rectangle
                    }
                    while(sl!=s) {
                        sl>>=1; d<<=1; // if decreased
                    }
                    //printf("%d %d\n",n,s);
                    n2-=s; ci+=d;
                }
            }
            c+=ci;
        }
        printf("%d\n",c);
    }
}
