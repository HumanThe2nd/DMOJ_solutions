/*
DWITE '09 R7 #1 - Binary Equipment
Author: HumanThe2nd
Date: 2025-03-21
if "Equipped" bitwise or with 2 to the power of "Item" equals itself, the bit is present
otherwise it isn't
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    for(int t=0;t<5;t++){
        int a,b,c=1;
        scanf("%d %d",&a,&b);
        for(int j=0;j<b;j++) c<<=1;
        if((a|c)==a) puts("1");
        else puts("0");
    }
}
