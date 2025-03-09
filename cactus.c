/*
Mighty Cactus
Author: HumanThe2nd
Date: 2025-03-09
Prefix Sum Array: Damage recieved at each moment
Pick optimal armor at each moment
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
long long psa[1000002];
int main(){
    buff();
    long long n=scan(),m=scan(),k=scan(),mx=0;
    double t[k],a[k],dt=0;
    for(int i=0;i<k;i++){
        long long ti=scan(),ai=scan();
        t[i]=ti;
        a[i]=(double)(100-ai)/100;
    }
    while(m--){
        long long s=scan(),l=scan(),d=scan();
        psa[s]+=d; psa[s+l]-=d;
        if(s+l>mx) mx=s+l;
    }
    for(int i=0;i<=mx;i++){
        psa[i+1]+=psa[i];
        double di=psa[i],mn=di;
        for(int j=0;j<k;j++){
            double df=(di-t[j])*a[j];
            if(df<0) df=0;
            if(df<mn) mn=df;
        }
        dt-=mn; // minimum dmg
        if((double)n+dt<=0) return puts("Act Like A Cactus.")*0;
    }
    printf("%0.2lf\n",(double)n+dt);
}
