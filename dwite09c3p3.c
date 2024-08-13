// DWITE '09 R3 #3 - Binary Test Strings 2
// Author: Dan Shan
// Goal: sum of 1s in all possible binary arrays where subaray s does not exist
// Theory: Brute force every number from (1,1024) adding the number of 1s if subarray does not occur
#include <stdio.h>
int main() {
    for(int ti=0;ti<5;ti++){
        char s[9];
        scanf("%s",s);
        int l=0,c=0; // input length
        while(s[l]!='\0') l++;
        for(int i=1;i<256;i++){
            int n=i,l2=0,f=1;
            int s2[8],ci=0;
            while(n){ // second number will be reversed
                s2[l2]=(n&1);
                ci+=s2[l2]; 
                n>>=1; l2++;
            }
            for(int j=l2;j<8;j++) s2[j]=0; // leading zeros
            for(int j=0;j<9-l;j++){
                for(int k=0;k<l;k++){
                    if((s[k]-'0')!=s2[7-k-j]) break;
                    if(k==l-1) f=0; // equal
                }
            }
            if(f) c+=ci; // add 1s if subarray s not found in number
        }
        printf("%d\n",c);
    }
}
