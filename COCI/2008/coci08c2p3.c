/*
COCI '08 Contest 2 #3 Perket
By: Dan Shan
The problem is asking for minimum absolute difference between 
multiplication combinations of 1 array and addition combinations of the other
Theory: 
compare all combinations of the first array with all combinations of the second
*/
#include <stdio.h>
#define abs(a,b)(((a)-(b)>0)?((a)-(b)):((b)-(a)))
#define min(a,b)((a)<(b)?(a):(b))
int d=2e9,c=0,a[10],b[10];
void cmp(int s,int e,int v,int v2){
    if(v2){
    d = min(d,abs(v,v2));
    }
    for(int i=s;i<e;i++) cmp(i+1,e,v*a[i],v2+b[i]);
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d %d",&a[i],&b[i]);
    cmp(0,n,1,0);
    printf("%d\n",d);
}
