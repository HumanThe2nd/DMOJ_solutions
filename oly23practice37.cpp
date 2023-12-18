// Friendship Puzzle
// By: Dan Shan
#include <iostream>
#include <vector>
class ds{
std::vector<int> p;
public:
	std::vector<int> s;
	ds(int n){
		p.resize(n+1);
		s.resize(n+1);
		for(int i=0;i<=n;i++){
			s[i]=1;
			p[i]=i;
		}
	}
	int f(int n){
		if(n!=p[n]){
			p[n]=f(p[n]);
		}
		return p[n];
	}
	void us(int a, int b){
		int pa = f(a);
		int pb = f(b);
		if(pa != pb){
			p[pa] = pb;
			s[pb] += s[pa];
		}
	}
};
int main(){
std::ios::sync_with_stdio(0);
std::cin.tie(0);
int n,m,si=1;
std::cin >> n >> m;
ds d(n);
for(int i=0;i<m;i++){
	int a,b;
	std::cin >> a >> b;
	d.us(a,b);
}
for(int i=1;i<=n;i++){
	if(d.s[d.f(i)]>si)si=d.s[d.f(i)];
}
std::cout<<si<<"\n";
}
