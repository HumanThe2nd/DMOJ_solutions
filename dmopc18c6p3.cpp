// DMOPC '18 Contest 6 P3 - Wish Upon a Star
// By: Dan Shan
// Using disjoint sets to count extraneous edges in a tree
#include<iostream>
#include<vector>
int n,m,e;
class ds{
std::vector<int> p;
public:
	ds(int n){
		p.resize(n+1);
		for(int i=0;i<=n;i++){
			p[i]=i;
		}
	}
	int f(int n){
		if(p[n]!=n){
			p[n] = f(p[n]);
		}
		return p[n];
	}
	void u(int a, int b){
		p[f(a)]=f(b);
	}
};
int main(){
scanf("%d %d",&n,&m);
ds d(n);
for(int i=1;i<=m;i++){
	int a,b;
	scanf("%d %d",&a,&b);
	if(d.f(a)==d.f(b))
		e++; // count extraneous edges
	d.u(a,b); // add to tree
}
printf("%s",e<2?"YES":"NO");
}
