/*
Rock Climbing
Author: Dan Shan
Date: 2025-02-11
store last starting point to calculate distance
if jump impossible, double jump and decrement e
if double jump also impossible or used up, return impossible
return possible when end reached
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<22 // buffer size
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
int main(){
    buff();
    int n=scan(),m=scan(),e=scan(),l=0;
    for(int i=0;i<n;i++){
        int ai=scan();
        if(ai-l<=m) l=ai;
        else if(ai-l<=2*m&&e) l=ai,e--;
        else return puts("Unfair!")*0;
    }
    puts("Too easy!");
}
