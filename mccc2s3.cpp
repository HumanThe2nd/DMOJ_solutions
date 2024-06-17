// Mock CCC '20 Contest 2 S3 - Tree Programming
// Author: Dan Shan
// theory: 128 disjoint sets
// for each connection join the 2 nodes the set that their bitwise or equals
#include <bits/stdc++.h>
using namespace std;
class ds {
    vector<int> p; // parent
    vector<int> size; // size of each set
public:
    ds() = default;
    explicit ds(int n) {
        p.resize(n);
        size.resize(n, 1); // initialize size to 1
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
    int f(int i) {
        if (i != p[i]) {
            p[i] = f(p[i]); // find parent using DFS
        }
        return p[i];
    }
    void us(int x, int y) { // union by size
        x = f(x);
        y = f(y);
        if (x != y) {
            if (size[x] < size[y]) {
                swap(x, y); // merge smaller set into larger set
            }
            p[y] = x;
            size[x] += size[y];
        }
    }
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ds> a(129);
	int n,m,q;
	cin >> n >> m >> q;
	for(int i=0;i<129;i++) a[i]=ds(n+1);
	while(m--){
		int u,v,k;
		cin >> u >> v >> k;
		for(int i=0;i<129;i++){
			if((i|k)==i){
				a[i].us(u,v);
			}
		}
	}
	while(q--){
		int ai,bi;
		cin >> ai >> bi;
		for(int i=0;i<129;i++){
			if(a[i].f(ai)==a[i].f(bi)){
				printf("%d\n",i);
				break;
			}
		}
	}
}
