// SAC '21 Code Challenge P5 - Friends of Friends
// By: Dan Shan
// Disjoint set to track sizes
#include<iostream>
#include<vector>
int n,q;
class ds{
std::vector<int> p,s;
public:
ds(int n){
	p.resize(n+1);
	s.resize(n+1);
	for(int i=1;i<=n;i++){
		p[i]=i;
		s[i]=1;
	}
}
int f(int n){
	if(p[n]!=n){
		p[n] = f(p[n]);
	}
	return p[n];
}
int fs(int i){
	return s[f(i)];
}
void us(int a, int b){ // if condition very important
	if(f(b)!=f(a)) s[f(b)]+=s[f(a)]; // prevents duplication
	p[f(a)] = f(b);
}
};
int main(){
scanf("%d %d",&n,&q);
ds d(n);
for(int i=0;i<q;i++){
	int ins,a,b;
	scanf("%d",&ins);
	if(ins==1){ // add edge/union
		scanf("%d %d",&a,&b);
		d.us(a,b);
	}
	else{ // query size of set
		scanf("%d",&a);
		printf("%d\n",d.fs(a));
	}
}
}
