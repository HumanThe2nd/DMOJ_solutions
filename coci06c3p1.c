/*
COCI '06 Contest 3 #1 Patuljci
Author: Dan Shan
Date: 2025-01-26
Brute force
Calculate sum with every 2 dwarfs removed
Time Complexity: (O(9^2)) -> O(1)
*/
#include <stdio.h>
int main(){
    int a[9],c=0;
    for(int i=0;i<9;i++) scanf("%d",&a[i]),c+=a[i];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(j==i) continue; // distinct removals
            if(a[i]+a[j]+100==c){
                for(int k=0;k<9;k++){
                    if(k==i||k==j) continue;
                    printf("%d\n",a[k]);
                }
                return 0;
            }
        }
    }
}
