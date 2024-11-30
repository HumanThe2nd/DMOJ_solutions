// CCC '11 J2 - Who Has Seen The Wind
// Author: Dan Shan
// Date: 2024-09-09
// Brute force integer inputs and outputs within range for a function
#include <stdio.h>
int main() {
	int h,m;
    scanf("%d %d",&h,&m);
    for(int t=1;t<=m;t++){
        int a=-6*t*t*t*t+h*t*t*t+2*t*t+t;
        if(a<=0) return printf("The balloon first touches ground at hour:\n%d\n",t)*0;
    }
    printf("The balloon does not touch ground in the given time.");
}
