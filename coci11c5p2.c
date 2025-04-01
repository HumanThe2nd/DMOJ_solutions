/*
COCI '11 Contest 5 #2 Eko
Author: HumanThe2nd
Date: 2025-04-01
Binary search maximum valid height
Time Complexity: O(N *log(N)) 
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
int main() {
    buff();
    long long n=scan(),m=scan();
    long long a[n],l=0,r=0;
    for(int i=0;i<n;i++){
        a[i]=scan();
        if(a[i]>r) r=a[i];
    }
    while(l<r){
        long long mid=(l+r+1)>>1,c=0;
        for(int i=0;i<n;i++){
            if(a[i]>mid) c+=a[i]-mid;
        }
        if(c<m) r=mid-1;
        else l=mid;
    }
    printf("%lld\n",l);
}
