// VMSS '15 #2 - Tomb Robbing
// Author: Dan Shan
// Template grid BFS
#include <stdio.h>
int v[100][101],qx[]={0,0,1,-1},qy[]={1,-1,0,0};
int main() {
    int R,C,c=0;
    scanf("%d %d",&R,&C);
    for(int i=0;i<R;i++){
        char s[101];
        scanf("%s",s);
        for(int j=0;j<C;j++){
            v[i][j]=s[j]=='X';
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(v[i][j]) continue;
            int l=0,r=1,ql[10001],qr[10001];
            c++;
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
