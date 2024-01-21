// Mock CCC '24 Contest 1 J4/S1 - Magical Magnetic Marbles
// By: Dan Shan
// count distance between rightmost marble of each group
// store in vector and sort then fill from lowest
#include<bits/stdc++.h>
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n,k,mcnt=0,d=0;
	std::vector<int> v;
	std::cin >> n >> k;
	std::string s;
	std::cin >> s;
	bool o=0,f=0;
	for(int i=n-1;i>=0;i--){
		if(s[i]=='1'){
			if(!o){
				if(!f) f=1;
				else v.emplace_back(d);
				d=0;
				mcnt++;
			}
			else d++;
			o=1;
		}
		else{
			o=0;
			d++;
		}
	}
	std::sort(v.begin(),v.end());
	for(int i=0;i<(int)v.size();i++){
		k-=v[i];
		if(k<0) break;
		else mcnt--;
	}
	if(k>0)mcnt = std::max(mcnt,1);
	std::cout << mcnt << "\n";
}
