/*
OTHS Coding Competition 2 P5 - Coffee Jelly
Author: Dan Shan
Date: 2024-08-04
My intended approach:
Define a room as a group of connected open cells
1. BFS/DFS from each person to mark their rooms as walls
2. 2nd BFS/DFS to count valid remaining rooms
*/
#include <stdio.h>
int v[1000][1001],qx[]={0,0,1,-1},qy[]={1,-1,0,0};
int main(int argc, char** argv) {
    int R,C,c=0;
    scanf("%d %d\n",&R,&C);
    for(int i=0;i<R;i++){
        char s[1001];
        scanf("%s",s);
        for(int j=0;j<C;j++){
            v[i][j]=s[j]=='X';
            if(s[j]=='*') v[i][j]=2;
        }
    }
    for(int i=0;i<R;i++){ // first BFS turn all connected cells to danger node to walls without adding
        for(int j=0;j<C;j++){
            if(v[i][j]!=2) continue;
            int l=0,r=1,ql[1000001],qr[1000001];
            ql[0]=i; qr[0]=j; v[i][j]=1;
            while(l!=r){
                int xi=ql[l],yi=qr[l]; l++;
                for(int k=0;k<4;k++){
                    int xii=xi+qx[k],yii=yi+qy[k];
                    if(xii<0||yii<0||xii>=R||yii>=C||v[xii][yii]) continue;
                    ql[r]=xii; qr[r]=yii; r++;
                    v[xii][yii]=1;
                }
            }
        }
    }
    for(int i=0;i<R;i++){ // second BFS count remaining open spaces
        for(int j=0;j<C;j++){
            if(v[i][j]) continue; 
            int l=0,r=1,ql[1000001],qr[1000001];
            c++; v[i][j]=1;
            ql[0]=i; qr[0]=j;
            while(l!=r){
                int xi=ql[l],yi=qr[l]; l++;
                for(int k=0;k<4;k++){
                    int xii=xi+qx[k],yii=yi+qy[k];
                    if(xii<0||yii<0||xii>=R||yii>=C||v[xii][yii]) continue;
                    ql[r]=xii; qr[r]=yii; r++;
                    v[xii][yii]=1;
                }
            }
        }
    }
    printf("%d\n",c);
}
