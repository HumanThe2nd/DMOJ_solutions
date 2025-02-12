/*
Cheerio Contest 1 S3 - Stock Trading
Author: Dan Shan
Date: 2025-02-12
For every point 'X' except the first, use it as a start
iterate its preceding points in descending order updating max and min slope with the point 'X'
if any preceding points >= max or <= min then it is valid
Time Complexity: O(n^2)
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<20 // buffer size
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
    int n=scan(),c=0;
    int t[n],p[n];
    t[0]=scan(); p[0]=scan();
    for(int i=1;i<n;i++) {
        t[i]=scan(); p[i]=scan();
        long double mn=((long double)p[i]-p[i-1])/(t[i]-t[i-1]),mx=mn; // max and min slope with previous
        for(int j=i-1;j>=0;j--){ // check all combinations with previous points
            long double mi=((long double)p[i]-p[j])/(t[i]-t[j]);
            if(mi>=mx){
                c++; mx=mi;
                continue;
            }
            if(mi<=mn){
                c++; mn=mi;
                continue;
            }
        }
    }
    printf("%d\n",c);
}
