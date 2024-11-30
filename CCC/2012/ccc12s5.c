// CCC '12 S5 - Mouse Journey
// By: Dan Shan
#include<stdio.h>
int d[25][25];
int main(){
    int r,c,k;
    scanf("%d %d %d",&r,&c,&k);
    for(int i=0;i<k;i++){
    	int ri,ci;
    	scanf("%d %d",&ri,&ci);
    	d[ri-1][ci-1]=-1; // block the path
    }
    d[0][0]=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(d[i][j]<0) continue;
            if(i>0 && d[i-1][j]>=0) d[i][j]+=d[i-1][j];
            if(j>0 && d[i][j-1]>=0) d[i][j]+=d[i][j-1];
        }
    }
    printf("%d\n",d[r-1][c-1]);
}
