/*
COCI '10 Contest 1 #2 Profesor
Author: Dan Shan
Date: 2025-09-19

1. Create freuqency table of each grade
2. For each desk: update frequency table, update max, then zero the frequencies that don't occur
3. Return max
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<24 // Templates
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // Fast input
    long long num=0,neg=1;
    while((*ptr<'0'||*ptr>'9')&&*ptr!='-')++ptr; // Skip non-digit characters
    while(*ptr=='-')++ptr,neg*=-1;
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num*neg;
}
int main() {
    buff();
    int n = scan(), f[] = {0, 0, 0, 0, 0, 0}, g = 5, mx = 0;
    for(int i = 0; i < n; ++i){
        int ai = scan(), bi = scan();
        for(int j = 1; j < 6; ++j){
            if(j !=ai && j != bi) f[j] = 0; // end of chain
            else {
                ++f[j]; // continue or start chain
                if(f[j] > mx || (f[j] == mx && j < g)){
                    mx = f[j]; g = j;
                }
            }
        }
    }
    printf("%d %d\n", mx, g);
}
