#include<iostream>
#include<unordered_map>
int main(){
	int n,c=0;
	scanf("%d",&n);
	std::unordered_map<int,int> m;
	for(int i=0;i<n;i++){
		int w,h;
		scanf("%d %d",&w,&h);
		if(m.find(w)==m.end()||m[w]<h)m[w]=h;
	}
	for(auto x:m){
		c+=x.second;
	}
	printf("%d\n",c);
}
