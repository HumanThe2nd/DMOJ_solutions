// CCC '06 J5 - CCC Othello
// Author: Dan Shan
// Date: 2024-09-15
// iterate down each direction checking if same color is found
// if so make all colors between 2 points the said color
// note: if edge is reached then colors are unflipped so 2 iterations must be done
// first to check depth and if same color ending exists before flipping
#include <stdio.h>
int a[8][8], cur=2; // 1: white, 2: black
int main() {
	char s[2];
    int n,b=0,w=0;
    scanf("%s %d",s,&n);
    if(s[0]=='a'){
        a[3][3]=1; a[4][4]=1;
        a[3][4]=2; a[4][3]=2;
    }
    else if(s[0]=='b'){
        for(int i=0;i<8;i++) {
            a[8-i-1][i]=1; a[i][i]=2;
        }
    }
    else{
        for(int i=0;i<8;i++){
            a[i][2]=2; a[i][3]=2;
            a[i][4]=1; a[i][5]=1;
        }
    }
    int dx[]={0,0,-1,-1,-1,1,1,1},dy[]={-1,1,-1,0,1,-1,0,1};
    while(n--){
        int r,c;
        scanf("%d %d",&r,&c);
        r--; c--; // 0 index
        a[r][c]=cur;
        if(cur==2) cur=1;
        else cur=2; // switch turns
        for(int i=0;i<8;i++){ // flip adjacents
            int xi=r,yi=c,l=0;
            while(1){
                xi+=dx[i]; yi+=dy[i];
                if(xi<0||xi>7||yi<0||yi>7||!a[xi][yi]) { // out of bounds or empty
                    l=0; break;
                }
                if(a[xi][yi]!=cur) break; // end reached
                l++;
            }
            for(int j=0;j<=l;j++){
                if(cur==1) a[r+dx[i]*j][c+dy[i]*j]=2;
                else a[r+dx[i]*j][c+dy[i]*j]=1;
            }
        }
    }
    for(int i=0;i<8;i++){ // count colors
        for(int j=0;j<8;j++){
            b+=a[i][j]==2;
            w+=a[i][j]==1;
        }
    }
    printf("%d %d\n",b,w);
}
