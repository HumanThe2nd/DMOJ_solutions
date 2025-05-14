/*
OTHS Coding Competition 2 P4 - Magic Barrier
Author: Dan Shan
Date: 2024-07-20
Basic data structures
*/
#include <bits/stdc++.h>
using namespace std;
int scan() {
    int num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
int main() {
	int n=scan(),m=scan(),q=scan();
	unordered_map<int,int> x,y;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
            int ai=scan();
			x[ai]=i;
            y[ai]=j;
		}
	}
    for(int i=0;i<q;i++){
        int k=scan(),x1=scan(),y1=scan(),x2=scan(),y2=scan();
        if(x.find(k)==x.end()) {
            printf("no\n");
            continue;
        }
        x1--; y1--;
        if(x1<=x[k]&&x2>x[k]&&y1<=y[k]&&y2>y[k]) printf("yes\n");
        else printf("no\n");
    }
}
