/*
BlueBook - Cost
Author: HumanThe2nd
Date: 2025-03-22
If statements + math equation
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(n<31) puts("38");
        else if(n<51) puts("55");
        else if(n<101) puts("73");
        else printf("%d\n",73+(n-51)/50*24);
    }
}
