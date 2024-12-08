// CCC '14 S4 - Tinted Glass Window
// Author: Dan Shan
// Date: 2024-09-24
// Coordinate compression + difference array (2d)
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	long long n,t;
    cin >> n >> t;
    long long xi[n],yi[n],xf[n],yf[n],ti[n];
    set<long long> x,y;
    for(int i=0;i<n;i++){
        cin >> xi[i] >> yi[i] >> xf[i] >> yf[i] >> ti[i];
        x.insert(xi[i]); y.insert(yi[i]);
        x.insert(xf[i]); y.insert(yf[i]);
    }
    map<long long, long long> mx,my; // value to index
    vector<long long> px, py;
    for(auto val: x)px.emplace_back(val);
    for(auto val: y)py.emplace_back(val);
    for (int i=0;i<py.size();i++) {
        my[py[i]]=i+1;
    }
    for (int i=0;i<px.size();i++) {
        mx[px[i]]=i+1;
    }
    long long diff[py.size()+1][px.size()+1]={};
    for(int i=0;i<n;i++){
        long long x1=mx[xi[i]],y1=my[yi[i]],x2=mx[xf[i]],y2=my[yf[i]],t1=ti[i];
        diff[y1][x1]+=t1; diff[y2][x2]+=t1;
        diff[y1][x2]-=t1; diff[y2][x1]-=t1;
    }
    long long c=0; 
    for(int i=1;i<=py.size();i++){
        for(int j=1;j<=px.size();j++){
            diff[i][j]+=diff[i][j-1]+diff[i-1][j]-diff[i-1][j-1];
            if(diff[i][j]>=t) {
                c+=(py[i]-py[i-1])*(px[j]-px[j-1]);
            }
        }
    }
    cout << c << "\n";
}
