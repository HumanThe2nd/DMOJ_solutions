// CCC '08 J4 - From Prefix to Postfix
// Author: Dan Shan
// Reference: https://www.geeksforgeeks.org/prefix-postfix-conversion/
include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while(1){
		string s;
		getline(cin,s);
		stack<string> stk;
		if(s=="0") break;
		for(int i=(int)s.length()-1;i>=0;i-=2){
			string si; si.push_back(s[i]);
			if(s[i]>47) stk.emplace(si);
			else{
				string si1=stk.top(),si2;
				stk.pop();
				si2=stk.top();
				stk.pop();
				si1+=" "+si2+" "+si;
				stk.emplace(si1);
			}
		}
		cout << stk.top() << "\n";
	}
}
