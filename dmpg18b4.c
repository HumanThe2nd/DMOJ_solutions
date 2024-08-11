// DMPG '18 B4 - Shimnanigans
// Author: Dan Shan
// check averages and max values 
// Time complexity: O(n+m)
// With provided constraints, O(n*m) would also pass
#include <stdio.h>
#define abs(a)((a)>=0?(a):-(a))
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
int main() {
    int n,m,x,res=-1,max=-1;
    double min=1e9;
    scanf("%d %d %d",&n,&m,&x);
    int a[n],c=0;
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        c+=a[i];
        if(a[i]>max) max=a[i];
    }
    while(m--){
        int ai;
        scanf("%d",&ai);
        double d=(double)c/(n*ai);
        double diff=abs(d*100-x)/100;
        if(d<0.5||ai<max||diff>min) continue;
        if(diff==min&&ai<res) continue;
        min=diff; res=ai;
    }
    if(res==-1) printf("Shimnanigans have failed");
    else printf("%d\n",res);
}
