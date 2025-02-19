// CCC '17 S4 - Minimum Cost Flow
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
struct dsu {
    vector<int> p;
    dsu(int s):p(s+1){
        iota(p.begin(),p.end(),0);
    }
    int f(int x){
        if(x!=p[x]){
           p[x]=f(p[x]);
        }
        return p[x];
    }
    void us(int x,int y){
        p[f(x)]=f(y);
    }
};
struct R{  // road
    int a,b,c,t,v;
    R(int a,int b,int c,int t,int v):a(a),b(b),c(c),t(t),v(v){}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int n,m,d;
    cin >> n >> m >> d;
    dsu ds(n),ds2(n);
    vector<R> rs;
    for(int i=0;i<m;i++) {
        int a,b,c,t;
        cin >> a >> b >> c;
        t=i>=n-1;
        rs.push_back(R(a,b,c,t,i));
    }
    stable_sort(rs.begin(), rs.end(),[&](R r1,R r2){return r1.c < r2.c;});
    int cnt=1,s=0,cl=0;
    for (auto ri : rs) {
    	cl=ri.c; // heaviest edge
        if (ds.f(ri.a) != ds.f(ri.b)) {
            ds.us(ri.a, ri.b);
            s+=ri.t;
            cnt++;
        }
        if(cnt==n)break;
    }
    if(d){
    for(auto ri: rs){
        if(ds2.f(ri.a)!=ds2.f(ri.b)){
    	if(ri.c<cl||(ri.c==cl&&!ri.t)){
    		ds2.us(ri.a,ri.b);
    		}
    	else if(ri.c<=d&&!ri.t){
    		cout<<s-1<<"\n";
    		return 0;
    	}
        }
    }
    }
    cout << s << "\n";
    return 0;
}
