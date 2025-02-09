/*
Mock CCC '19 Contest 2 J2 - Tudor Drinks Some More Tea
Author: Dan Shan
Date: 2025-02-09
Addition of segments of 'J'
*/
#include <stdio.h>
int main() {
    int c=0,l=0;
	for(int ti=0;ti<7;ti++){
        char s=getchar();
        while(s!='T'&&s!='J') s=getchar();
        if(s=='T') l=0;
        else if(!l) c++,l=1;
    }
    printf("%d\n",c);
}
