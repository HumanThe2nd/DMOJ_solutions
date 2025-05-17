/*
DWITE '07 R2 #3 - Floor Plan
Author: HumanThe2nd
Date: 2025-04-03
BFS starting at each numbered cell
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main() {
    int n,m,xi[5],yi[5],dx[]={0,0,-1,1},dy[]={-1,1,0,0};
    scanf("%d %d",&n,&m);
    char g[n][m+1];
    for(int i=0;i<n;i++){
        scanf("%s",g[i]);
        for(int j=0;j<m;j++){
            if(g[i][j]>'0'&&g[i][j]<'6'){
                xi[g[i][j]-'1']=i;
                yi[g[i][j]-'1']=j;
                g[i][j]='#';
            }
        }
    }
    for(int ti=0;ti<5;ti++){
        int qx[1601],qy[1601],l=0,r=1;
        qx[0]=xi[ti]; qy[0]=yi[ti];
        while(l<r){
            int x=qx[l],y=qy[l++];
            for(int i=0;i<4;i++){
                int xii=x+dx[i],yii=y+dy[i];
                if(xii<0||yii<0||xii>=n||yii>=m) continue; // out of bounds
                if(g[xii][yii]=='.'){
                    g[xii][yii]='#';
                    qx[r]=xii; qy[r++]=yii;
                }
            }
        }
        printf("%d\n",r);
    }
}
