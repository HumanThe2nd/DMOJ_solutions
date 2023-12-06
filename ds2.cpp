// Disjoint Set Test
// By: Dan Shan
// Kruskals algorithm for minimum spanning trees without weighting
#include<iostream>
#include<vector>
int n,m;
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
std::vector<int> out;
scanf("%d %d",&n,&m);
ds d(n);
for(int i=1;i<=m;i++){
	int a,b;
	scanf("%d %d",&a,&b);
	if(d.f(a)!=d.f(b))
		out.push_back(i);
	d.u(a,b); // add to tree
}
if((int)out.size()!=n-1) printf("Disconnected Graph\n");
else{
	for(int i=0;i<n-1;i++){
		printf("%d\n",out[i]);
	}
}
}
