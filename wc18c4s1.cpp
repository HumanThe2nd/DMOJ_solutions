// WC '18 Contest 4 S1 - World of StarCraft
// by: Dan Shan
// Modified DSU
// only connect 2 nodes if they have the same character value
#include<iostream>
#include<vector>
using namespace std;
class ds{
vector<int> p;
vector<string> r;
public:
	ds(int n,string s){
		r.resize(n+1);
		p.resize(n+1);
		for(int i=1;i<=n;i++){
			p[i]=i;
			r[i]=s[i-1];
		}
	}
	int f(int s){
		if(p[s]!=s){
			p[s] = f(p[s]);
		}
		return p[s];
	}
	string fr(int s){
		if(p[s]!=s){
			p[s] = f(p[s]);
		}
		return r[s];
	}
	void u(int a, int b){ // if unsafe don't connect
		if (fr(a)==fr(b))
		p[f(a)] = f(b);
	}
};
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int n,m,k,c=0;
string s;
cin >> n >> m >> k >> s;
ds d(n,s);
for(int i=0;i<m;i++){
	int a,b;
	cin >> a >> b;
	d.u(a,b);
}
for(int i=0;i<k;i++){
	int a,b;
	cin >> a >> b;
	if(d.f(a)==d.f(b))c++;
}
printf("%d\n",c);
}
