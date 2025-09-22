/*
BlueBook - Voting
Author: Dan Shan
Date: 2025-09-21

Create frequency array of each character
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int n, v[7];
int main() {
    scanf("%d",&n);
    while(n--){
        char si[2];
        scanf("%s",si);
        if(si[0] < 'A' || si[0] > 'F') ++v[6];
        else ++v[si[0]-'A'];
    }
    for(int i = 0; i < 7; ++i) printf("%d\n",v[i]);
}
