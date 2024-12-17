/*
ICPC ECNA 2005 D - Queens, Knights and Pawns
Author: Dan Shan
Date: 2024-12-16
Brute force simulation on a 2d grid
Fill in pawns and knights first marking blocked spots
(blocked spots and unsafe spots are different things)
fill in queen positions spotting each direction at blocked cells
Note: This program simulates each queen direction manually, it may be simplified
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
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
int main() {
    int dx[]={-2,-1,1,2,2,1,-1,-2},dy[]={1,2,2,1,-1,-2,-2,-1},ti=1;
    while(1){
        int n=scan(),m=scan();
        if(!n||!m) break; // input finished
        int v[n][m]={},c=n*m,mx=n;
        if(m>mx) mx=m;
        int kq=scan();
        int qk[2][kq];
        for(int ki=0;ki<kq;ki++){
            qk[0][ki]=scan(),qk[1][ki]=scan();
        }
        int kk=scan();
        for(int ki=0;ki<kk;ki++){
            int xi=scan(),yi=scan();
            xi--; yi--; // 1 to 0 index
            if(!v[xi][yi]) c--; 
            v[xi][yi]=2; // piece blocking
            for(int i=0;i<8;i++){
                int xii=xi+dx[i],yii=yi+dy[i];
                if(xii<0||xii>=n||yii<0||yii>=m) continue; // out of bounds
                if(v[xii][yii]) continue;
                c--; v[xii][yii]=1;
            }
        }
        int kp=scan();
        for(int ki=0;ki<kp;ki++){
            int xi=scan(),yi=scan();
            xi--; yi--;
            if(!v[xi][yi]) c--; 
            v[xi][yi]=2; // piece blocking
        }
        for(int ki=0;ki<kq;ki++){
            int xi=qk[0][ki],yi=qk[1][ki],f=0,f1=0,f2=0,f3=0,f4=0,f5=0,f6=0,f7=0;
            xi--; yi--; // 1 to 0 index
            if(!v[xi][yi]){
                c--; v[xi][yi]=2;
            }
            for(int i=1;i<mx;i++){
                if(xi+i<n){ // down
                    if(v[xi+i][yi]==2) f=1; // blocked
                    if(!v[xi+i][yi]&&!f){
                        c--; v[xi+i][yi]=1;
                    }
                }
                if(xi-i>=0){ // up
                    if(v[xi-i][yi]==2) f1=1; // blocked
                    if(!v[xi-i][yi]&&!f1){
                        c--; v[xi-i][yi]=1;
                    }
                }
                if(yi+i<m){ // right
                    if(v[xi][yi+i]==2) f6=1; // blocked
                    if(!v[xi][yi+i]&&!f6){
                        c--; v[xi][yi+i]=1;
                    }
                }
                if(yi-i>=0){ // left
                    if(v[xi][yi-i]==2) f7=1; // blocked
                    if(!v[xi][yi-i]&&!f7){
                        c--; v[xi][yi-i]=1;
                    }
                }
                if(yi-i>=0){
                    if(xi-i>=0){ // up left
                        if(v[xi-i][yi-i]==2) f2=1; // blocked
                        if(!v[xi-i][yi-i]&&!f2){
                            c--; v[xi-i][yi-i]=1;
                        }
                    }
                    if(xi+i<n){ // down left
                        if(v[xi+i][yi-i]==2) f3=1; // blocked
                        if(!v[xi+i][yi-i]&&!f3){
                            c--; v[xi+i][yi-i]=1;
                        }
                    }
                }
                if(yi+i<m){
                    if(xi-i>=0){ // up right
                        if(v[xi-i][yi+i]==2) f4=1; // blocked
                        if(!v[xi-i][yi+i]&&!f4){
                            c--; v[xi-i][yi+i]=1;
                        }
                    }
                    if(xi+i<n){ // down right
                        if(v[xi+i][yi+i]==2) f5=1; // blocked
                        if(!v[xi+i][yi+i]&&!f5) {
                            c--; v[xi+i][yi+i]=1;
                        }
                    }
                }
            }
        }
        printf("Board %d has %d safe squares.",ti++,c);
        putchar_unlocked('\n');
    }
}
