/*
CCO '07 P1 - Cows
AUthor: Dan Shan
Date: 2025-02-17
Convex Hull (Graham scan) + Shoelace theorem
Find vertice coordinates with convex hull
Use shoelace theorem to calculate area 
(and divide by 50 as specified)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma GCC optimize ("Ofast")
struct p{ // point
    int x,y;
};
struct p st; // start 
void swap(struct p *a, struct p *b){
    struct p temp=*a;
    *a=*b; *b=temp;
}
int dist(struct p a, struct p b){ // euclidian distance squared
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int ang(struct p a, struct p b, struct p c){ // cross product: turn direction
    int v=(b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
    if(!v) return 0; // collinear
    return v>0?1:2;
}
int cmp(const void *a, const void *b){ // angle sort comparator
    struct p *pa=(struct p*)a,*pb=(struct p*)b;
    int ord=ang(st,*pa,*pb);
    if(!ord) return dist(st,*pa)>=dist(st,*pb)?1:-1;
    return (ord==2)?-1:1;
}
int main() {
    int n,y=2e9,m=0;
    scanf("%d",&n);
    if(n<3) return puts("0\n"); // can't form polygon
    struct p a[n];
    for(int i=0;i<n;i++) {
        scanf("%d %d",&a[i].x,&a[i].y);
        if(a[i].y<y) y=a[i].y,m=i;
    } st=a[m];
    swap(&a[0],&a[m]);
    qsort(&a[1],n-1,sizeof(struct p),cmp);
    int s2=1;
    for(int i=1;i<n;i++){
        while(i<n-1&&ang(st,a[i],a[i+1])==0) i++;
        a[s2++]=a[i];
    }
    int r2=3;
    struct p stk[n+1];
    if(s2>2){ // convex hull
        stk[0]=a[0]; stk[1]=a[1]; stk[2]=a[2];
        for(int i=3;i<s2;i++){
            while(r2>1&&ang(stk[r2-2],stk[r2-1],a[i])!=2) r2--;
            stk[r2++]=a[i];
        }
    }
    else{
        r2=1;
        stk[0]=a[0];
        if(s2>1) r2++,stk[1]=a[1];
    }
    stk[r2++]=stk[0]; // create loop
    long long c=0;
    for(int i=1;i<r2;i++) c+=stk[i].y*stk[i-1].x-stk[i].x*stk[i-1].y;
    printf("%lld\n",c/100);
}
