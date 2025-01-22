/*
BSSPC '22 P3 - Searching for Seats
Author: Dan Shan 
Date: 2025-01-22
Frequency array of every cell
For each occupied seat reducee its frequency and increase frequency of cells beside it
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
int a[1001][1001],dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
int main(){
    buff();
    int n=scan(),m=scan(),k=scan(),c=0;
    while(k--){
        int ai=scan(),bi=scan();
        a[--ai][--bi]-=8; // seat taken
        for(int i=0;i<8;i++){
            int xi=ai+dx[i],yi=bi+dy[i];
            if(xi<0||yi<0||xi>=n||yi>=m) continue;
            a[xi][yi]++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]>2) c++;
        }
    }
    printf("%d\n",c);
}
