// CCC '03 S5 - Trucking Troubles
// By: Dan Shan
// kruskals algorithm for minimum spanning trees but maximum instead
// roads are given and not all nodes are needed so we store and grow tree
// until all nodes are found and return the minimum of the paths
#include<bits/stdc++.h>
using namespace std;
class ds{
vector<int> p;
vector<string> r;
public:
	ds(int n){
		p.resize(n+1);
		for(int i=1;i<=n;i++){
			p[i]=i;
		}
	}
	int f(int s){
		if(p[s]!=s){
			p[s] = f(p[s]);
		}
		return p[s];
	}
	void u(int a, int b){ // if unsafe don't connect
		p[f(a)] = f(b);
	}
};
class road{
public:
	int a,b,c;
};
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int c,r,d,m=INT_MAX;
cin>>c>>r>>d;
ds dsu(c);
vector<road> roads;
for(int i=0;i<r;i++){
	road r;
	cin >> r.a >> r.b >> r.c;
	roads.push_back(r);
} // sorts in ascending order
sort(roads.begin(),roads.end(),[&](road a,road b){return a.c<b.c;});
vector<int> destinations(d);
for(int i=0;i<d;i++) cin >> destinations[i];
while(!destinations.empty()){
	if(dsu.f(1)==dsu.f(destinations.back()))
		destinations.pop_back();
	else{ // vectors are read backwards
		road ri = roads.back();
		roads.pop_back();
		dsu.u(ri.a,ri.b);
		m = min(m,ri.c);
	}
}
printf("%d\n",m);
}
