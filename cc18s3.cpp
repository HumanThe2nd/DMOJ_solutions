// CCC '18 S3 - RoboThieves
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,cx[]={0,0,-1,1},cy[]={1,-1,0,0};
    scanf("%d %d",&n,&m);
    char s[n][m+1];
    int d[n][m],vis[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) vis[i][j]=0;
    }
    queue<int> qi,qj,qd,qci,qcj; qd.emplace(0);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        for(int j=0;j<m;j++){
            if(s[i][j]=='S'){
                qi.emplace(i),qj.emplace(j);
            }
            else if(s[i][j]=='C') {
                qci.emplace(i);
                qcj.emplace(j);
            }
        }
    }
    while(!qci.empty()){
        int ii = qci.front(),ji=qcj.front();
        qci.pop(); qcj.pop();
        for(int i=ii;i<n;i++){
            if(s[i][ji]=='W') break;
            if(s[i][ji]=='.') {
                s[i][ji]='v';
                d[i][ji]=-1;
                vis[i][ji]=1;
            }
            else if (s[i][ji] == 'S') s[i][ji] = 'W';
        }
        for(int i=ii;i>=0;i--){
            if(s[i][ji]=='W') break;
            if(s[i][ji]=='.') {
                s[i][ji]='v';
                d[i][ji]=-1;
                vis[i][ji]=1;
            }
            else if (s[i][ji] == 'S') s[i][ji] = 'W';
        }
        for(int j=ji;j<m;j++){
            if(s[ii][j]=='W') break;
            if(s[ii][j]=='.') {
                s[ii][j]='v';
                d[ii][j]=-1;
                vis[ii][j]=1;
            }
            else if (s[ii][j] == 'S') s[ii][j] = 'W';
        }
        for(int j=ji;j>=0;j--) {
            if (s[ii][j] == 'W') break;
            if (s[ii][j] == '.') {
                s[ii][j] = 'v';
                d[ii][j] = -1;
                vis[ii][j] = 1;
            }
            else if (s[ii][j] == 'S') s[ii][j] = 'W';
        }
            s[ii][ji] = 'W';
    }
    while(!qi.empty()){
        int ii = qi.front(),ji = qj.front(),di = qd.front();
        qi.pop(); qj.pop(); qd.pop();
        int cnt=0;
        while(s[ii][ji]=='U'||s[ii][ji]=='L'||s[ii][ji]=='R'||s[ii][ji]=='D'){
            if(s[ii][ji]=='U') ii--;
            else if(s[ii][ji]=='D') ii++;
            else if(s[ii][ji]=='L') ji--;
            else if(s[ii][ji]=='R') ji++;
            if(ii>=n||ii<0||ji>=m||ji<0||cnt>1e4+2) break;
            cnt++;
            vis[ii][ji]=1;
        }
        if(ii>=n||ii<0||ji>=m||ji<0||cnt>1e4+2) continue;
        if(s[ii][ji]=='W'||s[ii][ji]=='v') continue;
        if(s[ii][ji]=='.'){
            s[ii][ji]='v';
            d[ii][ji]=di;
        }
        for(int i=0;i<4;i++){
            int ci = ii+cx[i],cj = ji+cy[i];
            if(ci>=n||ci<0||cj>=m||cj<0) continue;
            if(s[ci][cj]!='v'&&s[ci][cj]!='W'&&!vis[ci][cj]){
                vis[ci][cj]=1;
                qi.emplace(ci); qj.emplace(cj); qd.emplace(di+1);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='v') printf("%d\n",d[i][j]);
            else if(s[i][j]=='.') printf("-1\n");
        }
    }
}
