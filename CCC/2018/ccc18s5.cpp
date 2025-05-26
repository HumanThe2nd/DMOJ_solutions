/*
CCC '18 S5 - Maximum Strategic Savings
Author: Dan Shan
Date: 2025-05-25
Observation: Only need one portal per planet and one plane per city
2d grid with planets as rows and cities as columns
1. Kruskal's MST -> minimum in a row and multiply the number of *remaining* columns
2.                  minimum in a col and muluiply by number of *remaining* rows
Note: The 2 dimensions must be processed together to ensure optimal paths (*remaining* cols and rows are important)
subtract MST weight original weight to find maximum reduction
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
class ds{ // Disjoint set template
	std::vector<int> p; // parent
public:
	ds() = default; // allows creation without initializing to vairables
	explicit ds(int n){ // constructs a disjoint set
		p.resize(n);
		for(int i=0;i<n;i++){
			p[i] = i;
		}
	}
	int f(int i){
		if(i!=p[i]){
			p[i] = f(p[i]); // find parent using DFS
		}
		return p[i];
	}
	void us(int x, int y){ // union
		p[f(x)] = f(y);
	}
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,p,q;
    cin >> n >> m >> p >> q;
    ll res=0;
    ds row(n+1),col(m+1);
    priority_queue<tuple<ll,ll,ll,ll>,vector<tuple<ll,ll,ll,ll>>,greater<>> pq;
    while(p--){ // Columns
        ll ai,bi,ci;
        cin >> ai >> bi >> ci;
        pq.push({ci,0,ai,bi});
        res+=(ll)ci*n;
    }
    while(q--){ // Columns
        ll ai,bi,ci;
        cin >> ai >> bi >> ci;
        pq.push({ci,1,ai,bi});
        res+=(ll)ci*m;
    }
    while(pq.size()){
        auto x=pq.top(); pq.pop();
        ll ci=get<0>(x),ti=get<1>(x),ai=get<2>(x),bi=get<3>(x);
        if(ti){
            if(row.f(ai)==row.f(bi)) continue; // conncted
            res-=ci*m; n--;
            row.us(ai,bi);
        }
        else{
            if(col.f(ai)==col.f(bi)) continue; // conncted
            res-=ci*n; m--;
            col.us(ai,bi);
        }
    }
    cout << res << "\n";
}
