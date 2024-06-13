// Hardcore Grinding
// Author: Dan Shan
// use difference array to query
// take running sum and record its maximum
// this code stores the maximum end time to save time iterating
#include<stdio.h>
int scan() {
    int num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
int d[10000001];
int main(int argc, char *argv[]) {
    int n=scan(),m=0;
    for(int i=0;i<n;i++){
        int si=scan(),fi=scan();
        d[si]++; d[fi]--;
        if(fi>m)m=fi;
    } int cur=0,res=0;
    for(int i=0;i<=m;i++){
        cur+=d[i];
        if(cur>res) res=cur;
    }
    printf("%d\n",res);
}
