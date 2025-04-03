/*
Bob Hates Triangles
Author: HumanThe2nd
Date: 2025-04-02
direct from larger node to smaller or vice versa
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
void print(int n) { // output template
    if(!n) putchar('0');
    char s[10];
    int i=0;
    while(n>0){
        s[i++]=(n%10)+'0';
        n/=10;
    }
    while (--i >= 0) {
        putchar(s[i]);
    }
}
int main() {
    buff();
    long long n=scan(),m=scan();
    for(int i=0;i<m;i++){
        int ai=scan(),bi=scan();
        if(ai>bi){
            print(ai);
            putchar(' ');
            print(bi);
            putchar('\n');
        }
        else {
            print(bi);
            putchar(' ');
            print(ai);
            putchar('\n');
        }
    }
}
