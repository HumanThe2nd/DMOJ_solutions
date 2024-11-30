// CCC '98 S2 - Cross Number Puzzle
// Author: Dan Shan
// Date: 2024-09-30
// The calculator along with the text outputted by it.
/* text output:
8128
153 370 371 407
*/
#include <stdio.h>
int main() {
	for(int i=1000;i<10000;i++){
        int c=1;
        for(int j=2;j<=i/2;j++){
            if(!(i%j)) c+=j;
        }
        if(c==i||i==6) printf("%d\n",c);
    }
    for(int i=100;i<1000;i++){
        int a=i%10,b=(i/10)%10,c=i/100;
        a*=a*a; b*=b*b; c*=c*c;
        if(i==a+b+c) printf("%d ",i);
    }
    printf("\n");
}
