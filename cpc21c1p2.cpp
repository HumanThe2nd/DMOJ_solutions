// CPC '21 Contest 1 P2 - AQT and Multiset
// By: Dan Shan
#include <iostream>
#include <set>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	long long c,a[2*n+1];
	multiset<long long> ms,res;
	cin >> c; a[0]=c;
	for(int i=1;i<=n*2;i++){
		cin >> a[i];
		c^=a[i];
	}
	for(int i=0;i<=n*2;i++){
		long long b;
		cin >> b;
		c^=b;
		ms.insert(b);
	}
	for(long long x: a) res.insert(x^c);
	printf("%lld\n",ms==res?c:-1);
}
