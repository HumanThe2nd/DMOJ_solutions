//============================================================================
// Name        : Death Gun
// Author      : Dan Shan
//============================================================================
// Goal: BFS starting from each smallest node in order
// Approach: Kahn Algorithm + priority queue
#include<bits/stdc++.h>
std::unordered_map<std::string,int> names; // name and order
std::unordered_map<std::string, std::vector<std::string>> adj;
std::unordered_map<std::string, int> indegree;
std::priority_queue<std::pair<int,std::string>, std::vector<std::pair<int,std::string>>,
std::greater<std::pair<int,std::string>>> q; // order and name
int n,c=1;
int main(){
std::cin.sync_with_stdio(0);
std::cin.tie(0);
std::cin>>n;
for(int i=0;i<n;i++){
	std::string a,b;
	std::cin>>b>>a;
	adj[a].push_back(b);
	if(names.find(a)==names.end()){
		names[a]=c;
		c++;
	}
	if(names.find(b)==names.end()){
		names[b]=c;
		c++;
	}
	if(indegree.find(b)==indegree.end())indegree[b]=1;
	else indegree[b]++;
}
for(auto s: names){
	if(indegree.find(s.first)==indegree.end())q.push(make_pair(s.second,s.first));
}
while(!q.empty()){
	std::pair<int,std::string> s = q.top();
	q.pop();
	std::cout<<s.second<<"\n";
	for(std::string x: adj[s.second]){
		indegree[x]--;
		if(indegree[x]==0)q.push(make_pair(names[x],x));
	}
}
}
