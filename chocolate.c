/*
Chocolate Bar
Author: Dan Shan
Date: 2025-02-08
formula: cuts = n * m - 1
*/
#include <stdio.h>
int main() {
	int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        printf("%d\n",n*m-1);
    }
}
