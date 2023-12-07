// MMCC '15 P1 - Inaho
// By: Dan Shan
// Rollback disjoint sets
#include<iostream>
#include<stack>
const int MM=500001;
int p[MM],s[MM];
std::stack<std::pair<int,int>> h;
void Init(int N){
	for(int i=0;i<=N;i++){
		p[i]=i;
		s[i]=1;
	}
}
int f(int n){
	if(p[n]!=n){    
		return f(p[n]);
	}
	return n;
}
void AddEdge(int U, int V){
	U = f(U); V = f(V);
	h.push({U,V});
	if(U!=V){
		if(s[U]<s[V]){ // swap
			int temp = V;
			V = U; U = temp;
		}
		s[U]+=s[V];
		p[V]=p[U];
	}
}
void RemoveLastEdge(){
	int tf= h.top().first,ts=h.top().second;
	if(tf!=ts){
	if(p[tf]==tf){
	int temp = ts;
	ts = tf; tf = temp; 
	}
	s[ts]-=s[tf];
	p[tf]=tf;
	}
	h.pop();
}
int GetSize(int U){
	return s[f(U)];
}
