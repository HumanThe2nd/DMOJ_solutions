// Lexicographically Least Substring
// Author: Dan Shan
// Date: 2024-09-26
// Note: cpp allows easy lexicographic comparisons between strings
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s,m;
	for(int i=0;i<51;i++) m.push_back('z');
	int n;
	cin >> s >> n;
	for(int i=0;i<s.length()-n;i++){
		string si;
		for(int j=0;j<n;j++) si.push_back(s[i+j]);
		if(si<m) m=si;
	}
	cout << m << "\n";
}
