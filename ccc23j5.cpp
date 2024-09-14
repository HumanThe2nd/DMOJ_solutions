// CCC '23 J5 - CCC Word Hunt
// Author: Dan Shan
// Date: 2024-09-14
// straight BFS with up to 1 turn
// if starting and preceding letters are found BFS in direction of next letter
// BFS either straight, left or right for each starting letter
// if turning left or right add 1 to the turns
// if turns exceeds 1 then break search
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	string s;
    int r,c,res=0;
    cin >> s >> r >> c;
    char a[r][c];
    int l=s.length(),cx[]={0,1,1,1,0,-1,-1,-1},cy[]={1,1,0,-1,-1,-1,0,1};
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++) cin >> a[i][j];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]!=s[0]) continue;
            queue<int> qx,qy,qd,qt,ql; // distance, turn count & last direction
            for(int k=0;k<8;k++) {
                if(i+cx[k]>=0&&i+cx[k]<r&&j+cy[k]>=0&&j+cy[k]<c){ // run bfs if adjacent is correct
                    if(a[i+cx[k]][j+cy[k]]==s[1]){ // 
                        qx.emplace(i+cx[k]); qy.emplace(j+cy[k]);
                        qd.emplace(k); qt.emplace(0); // no turns yet
                        ql.emplace(2);
                    }
                }
            }
            while(!qx.empty()){
                int xi=qx.front(),yi=qy.front(),di=qd.front();
                int ti=qt.front(),li=ql.front();
                qx.pop(); qy.pop(); qd.pop(); 
                qt.pop(); ql.pop();
                if(li==l&&ti<2){ // word found and less than 1 turn
                    res++; continue;
                }
                int xii=xi+cx[di],yii=yi+cy[di];
                if(xii>=0&&xii<r&&yii>=0&&yii<c){ // check boundaries
                    if(a[xii][yii]==s[li]){ // straight
                        qx.emplace(xii); qy.emplace(yii);
                        qd.emplace(di); qt.emplace(ti); 
                        ql.emplace(li+1);
                    }
                }
                xii=xi+cx[(di+2)%8],yii=yi+cy[(di+2)%8];
                if(xii>=0&&xii<r&&yii>=0&&yii<c){ // check boundaries
                    if(a[xii][yii]==s[li]){ // left turn
                        qx.emplace(xii); qy.emplace(yii);
                        qd.emplace((di+2)%8); qt.emplace(ti+1); 
                        ql.emplace(li+1);
                    }
                }
                xii=xi+cx[(di+6)%8],yii=yi+cy[(di+6)%8];
                if(xii>=0&&xii<r&&yii>=0&&yii<c){ // check boundaries
                    if(a[xii][yii]==s[li]){ // right turn
                        qx.emplace(xii); qy.emplace(yii);
                        qd.emplace((di+6)%8); qt.emplace(ti+1); 
                        ql.emplace(li+1);
                    }
                }
            }
        }
    }
    printf("%d\n",res);
}
