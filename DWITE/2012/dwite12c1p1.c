/*
DWITE '12 R1 #1 - Candy Piles
Author: Dan Shan
Date: 2025-08-12
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    for(int i=0;i<5;++i){
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;++j){
            for(int k=0;k<=j;++k){
                putchar('*');
            } putchar('\n');
        }
        for(int j=n-1;j>0;--j){
            for(int k=0;k<j;++k){
                putchar('*');
            } putchar('\n');
        }
    }
}
