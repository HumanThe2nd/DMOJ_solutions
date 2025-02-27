/*
COCI '06 Contest 3 #2 N-puzzle
Author: Dan Shan
Date: 2025-02-13
for each letter, add absolute difference in row position and absolute difference in columns
modulus on the letter's ascii can be used to determine original position intuitively
return total sum excluding the period
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int abs(int a){
    return a<0?-a:a;
}
int main() {
    int c=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            char s=getchar();
            if(s=='.') continue;
            int si=s-'A';
            c+=abs(si/4-i)+abs(si%4-j);
        }
        getchar();
        
    }
    printf("%d\n",c);
}
