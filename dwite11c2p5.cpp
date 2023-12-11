// DWITE '11 R2 #5 - Portals Check
// By: Dan Shan
// DSU using strings instead of integers
// Note: for strings this solution uses maps instead of the typical vector/array
#include<iostream>
#include<unordered_map>
using namespace std;
class ds{
public:
	unordered_map<string,string> p;
	string f(string s){
		if(p[s]!=s){
			p[s] = f(p[s]);
		}
		return p[s];
	}
	void u(string a, string b){
		p[f(a)] = f(b);
	}
};
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
for(int _=0;_<5;_++){
ds d;
int n;
cin >> n;
for(int i=0;i<n;i++){
	string q,a,b;
	cin >> q >> a >> b;
	if(d.p.find(a)==d.p.end())d.p[a]=a;
	if(d.p.find(b)==d.p.end())d.p[b]=b;
	if(q=="p") d.u(a,b);
	else printf("%sconnected\n",d.f(a)==d.f(b)?"":"not ");
}
}
}
