/*
Mock CCC '19 Contest 2 J1 - Tudor Drinks Some Tea
Author: Dan Shan
Date: 2025-02-09
Addition of 'P's
*/
#include <stdio.h>
int main() {
    int c=0;
	for(int ti=0;ti<5;ti++){
        char s=getchar();
        while(s!='P'&&s!='T') s=getchar();
        if(s=='P') c++;
    }
    printf("%d\n",c);
}
