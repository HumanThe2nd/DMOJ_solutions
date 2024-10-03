// CCC '00 S3 - Surfing
// Author: Dan Shan
// String BFS
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	unordered_map<string, vector<string>> m;
	for(int i=0;i<n;i++){
		string name,s;
		cin >> name >> s;
		while(s!="</HTML>"){
			if(s.length()>6&&s[0]=='H'&&s[1]=='R'&&s[2]=='E'&&s[3]=='F'&&s[4]=='='&&s[5]=='\"') {
				s=s.substr(6);
				while(s[s.length()-1]!='\"') s.pop_back();
				s.pop_back();
				m[name].emplace_back(s);
				cout << "Link from " << name << " to " << s << "\n";
			}
			cin >> s;
		}
	}
	string s,s2;
	cin >> s >> s2;
	while(s!="The"){ // bfs
		queue<string> q;
		q.emplace(s);
		int f=0;
		unordered_set<string> v;
		while(!q.empty()){
			string si=q.front(); q.pop();
			v.insert(si);
			if(si==s2) {
				f=1; break;
			}
			for(auto x:m[si]) if(v.find(x)==v.end()) q.emplace(x);
		}
		if(f) cout << "Can surf from " << s << " to " << s2 << ".\n";
		else cout << "Can't surf from " << s << " to " << s2 << ".\n";;
		cin >> s >> s2;
	}
}
