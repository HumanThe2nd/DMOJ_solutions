// DMPG '17 S2 - Anime Conventions
// By: Dan Shan
// Template disjoint sets data structure  
#include<iostream>
#include<vector>
class ds{
	std::vector<int> p; // parent

public:
	ds(int n){ // constructs a disjoint set
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
int main(){
std::cin.tie(0);
std::cin.sync_with_stdio(0);
int n,q;
std::cin >> n >> q;
ds dset = ds(n+1);
for(int i=0;i<q;i++){
	int a,b;
	std::string s;
	std::cin >> s >> a >> b;
	if(s=="A") dset.us(a,b);
	else if(dset.f(a)==dset.f(b))printf("Y\n");
	else printf("N\n");
}
}
