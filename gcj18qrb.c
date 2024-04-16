// Google Code Jam '18 Qualification Round Problem B - Trouble Sort
// By: Dan Shan
// parity checking
#include <stdio.h>
#include <stdlib.h>
#define min(a,b)((a)<(b)?(a):(b))
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
int cmp(const void*a,const void*b){
   return(*(int*)a-*(int*)b);
}
int main() {
    int t=scan();
    for(int ti=1;ti<=t;ti++){
        int n=scan();
        int a[n/2+1],a2[n/2],o[n]; 
        a[n/2]=2e9; // placeholder
        for(int i=0;i<n;i++){
            o[i]=scan();
            if(i&1)a2[i/2]=o[i];
            else a[i/2]=o[i];
        }
        qsort(a,n/2+1,sizeof(int),cmp);
        qsort(a2,n/2,sizeof(int),cmp);
        qsort(o,n,sizeof(int),cmp);
        printf("Case #%d: ",ti);
        int f=0;
        for(int i=0;i<n;i++){
            if(i&1){
                if(a2[i/2]!=o[i]){
                    printf("%d\n",i);
                    f=1; break;
                }
            }
            else{
                if(a[i/2]!=o[i]){
                    printf("%d\n",i);
                    f=1; break;
                }
            }
        }
        if(!f) printf("OK\n");
    }
}
