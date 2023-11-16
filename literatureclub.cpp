//============================================================================
// Name        : Literature Club
// Author      : Dan Shan
//============================================================================
// Goal: count words from each section that appear
// Approach use an integer as each name to store names and convert back to names
// when printing
// Important note: trigger words may be shared so an int vector is used instead of ints
#include<bits/stdc++.h>
using namespace std;
int n,k,w,c[4],m=1;
int main(){
unordered_map<string,vector<int>> map; // maps word to names
cin>>n>>k>>w;
for(int i=0;i<4;i++){
for(int j=0;j<w;j++){
	string word;
	cin>>word;
	map[word].push_back(i);
}
}
for(int i=0;i<n*k;i++){
string word;
cin>>word;
if(map.find(word)==map.end())continue;
for(auto x:map[word]){
	c[x]++;
	if(c[x]>m)m=c[x];
}
map.erase(word);
}
if(c[0]==m) cout<<"Sayori\n";
if(c[1]==m) cout<<"Natsuki\n";
if(c[2]==m) cout<<"Yuri\n";
if(c[3]==m) cout<<"Monika\n";
}
