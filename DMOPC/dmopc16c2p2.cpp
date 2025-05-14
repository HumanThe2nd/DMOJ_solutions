//============================================================================
// Name        : DMOPC '16 Contest 2 P2 - Ebola Outbreak
// Author      : Dan Shan
//============================================================================
// solved using disjoint set data structure
// connect all nodes in a group with 1 to the same parent and compare each parent
// to the parent of one afterwards to track the set
#include<iostream>
#include<vector>
int n,m;
struct ds{
	std::vector<int> p; // parent
public:
	ds(int n){
	p.resize(n+1);
	for(int i=0;i<=n;i++){
		p[i]=i;
	}
	}
	int f(int a){
	if(a!=p[a]){
		p[a] = f(p[a]);
	}
	return p[a];
	}
	void u(int a,int b){
		p[f(a)] = f(b);
	}
};
int main(){
	scanf("%d %d",&n,&m);
	ds d(n);
	for(int i=0;i<m;i++){
		int ni;
		scanf("%d",&ni);
		int c[ni];
		for(int j=0;j<ni;j++){
			scanf("%d",&c[j]);
        if(j)d.u(c[j],c[j-1]);
		}
	}
	std::vector<int> out;
	for(int i=1;i<=n;i++)
		if(d.f(i)==d.f(1))out.emplace_back(i);
	printf("%d\n",(int)out.size());
	for(int i=0;i<(int)out.size()-1;i++){
		printf("%d ",out[i]);
	}
	printf("%d\n",out.back());
}
