/*
ACM U of T Tryouts C3 D - A Frightening Evening
Author: Dan Shan
Date: 2024-12-22
Brute force simulation skipping each scene (or none)
If no scenes then no time is needed
*/
#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    while(n--){
        int d,m,h,l;
        scanf("%d %d %d %d",&d,&m,&h,&l);
        if(m==0){ // no key moments
            printf("0\n");
            continue;
        }
        int min=d;
        int t[m],f[m];
        for(int i=0;i<m;i++){
            scanf("%d %d",&t[i],&f[i]);
        }
        for(int i=0;i<=m;i++){ // try skipping each scene (or none)
        int c=0,fi=0,ti=0;
            for(int j=0;j<m;j++){
                if(j==i) continue; // simulate without this scene
                if(fi>=l) break; // left
                if(fi>=h) c+=t[j]-ti;
                fi+=f[j]; ti=t[j];
                if(fi<0) fi=0;
            }
            if(fi>=h&&fi<l) c+=d-ti;
            if(c<min) min=c;
        }
        printf("%d\n",min);
    }
}
