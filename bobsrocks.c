/*
Bob's Rocks
Author: HumanThe2nd
Date: 2025-03-10
Frequency arrays
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<24 // buffer size
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // fast input template
    long long num=0;
    while(*ptr<'0'||*ptr>'9')++ptr; // Skip non-digit characters
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num;
}
int f[51],m=0;
int main(){
    buff();
    int n=scan();
    for(int i=0;i<n;i++){
        int ai=scan();
        f[ai]++;
        if(f[ai]*ai>m) m=f[ai]*ai;
    }
    for(int i=50;i>=0;i--){
        if(i*f[i]==m) return printf("%d\n",i)*0;
    }
}
