//============================================================================
// Name        : Road Network
// Author      : Dan Shan
//============================================================================
// Goal: find shortest tree to connect all nodes and output distance
// Approach: minimum spanning tree using kruskal's algorithm
//           count initial edges and keep adding min acyclic edges until max
#include<bits/stdc++.h>
class ds{
std::vector<int> p;
public:
ds(int n){ // constructs disjoint set
	p.resize(n);
	for(int i=0;i<n;i++) p[i]=i;
}
int f(int n){ // find
	if(n!=p[n]){
		p[n]=f(p[n]);
	}
	return p[n];
}
void us(int x, int y){ // connect
	p[f(x)] = f(y);
}
};
int main(){
int n,m,c=1; // counter
double t=0; // total distance
scanf("%d %d",&n,&m);
int x[n],y[n]; // x and y coordinates of node at each index
ds g = ds(n);
for(int i=0;i<n;i++){
scanf("%d %d",&x[i],&y[i]);
}
for(int i=0;i<m;i++){
	int a,b;
	scanf("%d %d",&a,&b);
	if(g.f(--a)!=g.f(--b)) c++; // count premade edges
	g.us(a,b);
} // sorts distances mapped to a list of pairs with that distance
std::map<double,std::vector<std::pair<int,int>>> map;
for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){
		if(g.f(i)!=g.f(j)){ // distance using pythagorean
	double dist = pow(pow(x[i]-x[j],2)+pow(y[i]-y[j],2),0.5);
	map[dist].push_back(std::make_pair(i,j));
		}
	}
}
for(auto x: map){ // connect until all nodes are connected
	if(c==n) break;
	for(auto y:x.second){
		if(c==n) break;
		if(g.f(y.first)!=g.f(y.second)){
			g.us(y.first,y.second);
			c++; // increase edges
			t+=x.first; // increase total
		}
	}
}
printf("%.2lf",t);
}
