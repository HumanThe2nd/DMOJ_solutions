// Exam Prep
// By: Dan Shan
// disjoint sets tracking sizes and sum of values
// note: scanf/printf reaches TLE in c++ for this solution and cin/cout was substituted instead
#include<iostream>
#include<vector>
using namespace std;
using ll = long long int;
ll n,q; vector<ll> ai,p,s; // s for full sum, adj for adjacents
class ds{
public:
ds(ll n){
	p.resize(n+1);s.resize(n+1);ai.resize(n+1);
	for(ll i=1;i<=n;i++){
		p[i]=i;
		s[i]=1;
	}
}
ll f(ll n){
	if(p[n]!=n){
		p[n] = f(p[n]);
	}
	return p[n];
}
void us(ll a, ll b){
	if(f(b)!=f(a)) { // if condition very important
		s[f(b)]+=s[f(a)]; // prevents duplication
		ai[f(b)]+=ai[f(a)];
	}
	p[f(a)] = f(b);
}
};
int main(){
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
cin >> n >> q;
ds d(n);
for(ll i=1;i<=n;i++)cin>>ai[i];
for(ll i=0;i<q;i++){
	ll ins,a,b;
	cin >> ins;
	if(ins==1){ // add edge/union
		cin>>a>>b;
		d.us(a,b);
	}
	else if(ins==2){ // query size of set
		cin >> a;
		cout << s[d.f(a)] << "\n";
	}
	else{
		cin >> a;
		cout << ai[d.f(a)] << "\n";
	}
}
}
