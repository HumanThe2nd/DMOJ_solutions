// DWITE '10 R4 #3 - Binary Weight
// Author: Dan Shan
// Theory: Flip first 1 bit with a zero above it and move the smaller 1 bits down
//         If no zero exist above it, increase digit by 1 and move extra ones to back
//         f gives (number of 0s)+1
//         i-f gives (bumber if 1s)+1
#include <stdio.h>
#include <math.h>
int main() {
    for(int ti=0;ti<5;ti++){
        int n,a[32],l=0,f=0,s=0;
        scanf("%d",&n);
        while(n){
            a[l]=(n&1);
            l++; n>>=1;
        }
        for(int i=0;i<l;i++){
            if(a[i]) {
                s++; f++;
            }
            else f=0;
        }
        if(f==s){ // No zeros to swap
            int res=pow(2,l);
            for(int i=0;i<f-1;i++) res+=pow(2,i);
            printf("%d\n",res);
        }
        else{ // swap
            int res=0,f=0; // index 1 appeared
            for(int i=0;i<l;i++){ 
                if(!a[i]&&i&&f){ // local maximum 1
                    a[i]=1;
                    for(int j=0;j<i-f;j++) a[j]=1; // move reamining 1s down
                    for(int j=i-f;j<i;j++) a[j]=0;
                    break;
                }
                else if(a[i]&&!f) f=i+1;
            }
            for(int i=0;i<l;i++) res+=a[i]*pow(2,i);
            printf("%d\n",res);
        }
    }
}
