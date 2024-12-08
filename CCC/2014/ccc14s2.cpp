//============================================================================
// Name        : CCC '14 S2 - Assigning Partners
// Author      : Dan Shan
//============================================================================
// Goal: Check if pairs are arranged correctly
// Approach: take in 2 vectors of names and storing and comparing each pair
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	int n;
	bool g=1;
	cin>>n;
	if(n%2) g=0;
	unordered_map<string, string> pairs;
	vector<string> l1,l2;
	for(int i=0;i<n;i++){
		string in;
		cin>>in;
		l1.push_back(in);
	}
	for(int i=0;i<n;i++){
		string in;
		cin>>in;
		l2.push_back(in);
	}
	for(int i=0;i<n;i++){
		if(l1[i]==l2[i]) {g=0;break;}
		if(pairs.find(l1[i])==pairs.end()
		&&pairs.find(l2[i])==pairs.end())pairs[l1[i]]=l2[i];
		else if(pairs.find(l1[i])==pairs.end()
      &&pairs[l2[i]]!=l1[i]) {g=0;break;}
		else if(pairs.find(l2[i])==pairs.end()&&
      pairs[l1[i]]!=l2[i]) {g=0;break;}

	}
	if(g)printf("good\n");
	else printf("bad\n");
}
