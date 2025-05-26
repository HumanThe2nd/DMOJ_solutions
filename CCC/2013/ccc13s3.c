/*
CCC '13 S3 - Chances of Winning
Author: Dan Shan
Date: 2025-05-26
For every remaining game:
    Update all previous games with the 3 new possible outcomes 
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int q[2000][4],l=0,r=1,v[5][5];
int main(){
    int t,g,res=0;
    scanf("%d %d",&t,&g); t--;
    for(int i=0;i<g;++i){
        int ai,bi,s1,s2;
        scanf("%d %d %d %d",&ai,&bi,&s1,&s2);
        ai--; bi--;
        if(s1==s2) q[0][ai]++,q[0][bi]++;
        else if(s1>s2) q[0][ai]+=3;
        else q[0][bi]+=3;
        v[ai][bi]=1;
        v[bi][ai]=1;
    }
    for(int ti=g;ti<6;++ti){
        for(int i=0;i<3;++i){ // team 1
            for(int j=i+1;j<4;++j){ // team 2
                if(v[i][j]) continue; 
                v[i][j]=1; // found unplayed pair
                int ri=r;
                for(int ii=l;ii<ri;++ii){
                    for(int k=0;k<4;++k) q[r][k]=q[ii][k];
                    q[r++][i]+=3;
                    for(int k=0;k<4;++k) q[r][k]=q[ii][k];
                    q[r++][j]+=3;
                    for(int k=0;k<4;++k) q[r][k]=q[ii][k];
                    q[r][i]++,q[r++][j]++;
                }
                l=ri; i=4; break; // next combination
            }
        }
    }
    for(int i=l;i<r;++i){
        int w=1;
        for(int j=0;j<4;++j){
            if(j==t||q[i][j]<q[i][t]) continue;
            w=0; break; // fav team doesn't win
        }
        res+=w;
    }
    printf("%d\n",res);
}
