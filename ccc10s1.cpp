// CCC '10 S1 - Computer Purchase
// Author: Dan Shan
// Date: 2024-09-16
// sort names in lexicographically ascending order
// stable sort values in descending order
#include<bits/stdc++.h>
using namespace std;
class node{
public: 
string s;
int v;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
	cin >> n;
	vector<node> arr(n);
	while(n--){
		node ni;
		int a,b,c;
		cin >> ni.s >> a >> b >> c;
		ni.v=2*a+3*b+c;
		arr[n]=ni;
	}
	sort(arr.begin(),arr.end(),[&](node a, node b){return a.s<b.s;});
	stable_sort(arr.begin(),arr.end(),[&](node a, node b){return a.v>b.v;});
	if(!arr.empty()) cout << arr[0].s << "\n";
	if(arr.size()>1) cout << arr[1].s << "\n";
}
