// BPC 1 J3 - Group Project
// By: Dan Shan
#include <bits/stdc++.h>
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> v(2*n);
	for(int i=0;i<2*n;i++)
		std::cin >> v[i];
	std::sort(v.begin(),v.end());
	long long int c=0;
	for(int i=0;i<2*n;i+=2){
		c+=abs(v[i]-v[i+1]);
	}
	std::cout << c << "\n";
}
