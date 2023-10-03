//============================================================================
// Name        : CCC '21 S3 - Lunch Concert
// Author      : Dan Shan
//============================================================================
// Goal: given n objects find minimum distance between each object and a point
// Approach: - create a class for each object and a vector for them
//           - sort them by distance
//           - binary search each middle point and the point above it
//			   until only one optimal point remains
//			 - using the formula find which point uses less time
// Formula: for each friend return the absolute value of their position from
// 			the new position minus hearing distance multiplied by walk speed
//			if negative return 0 and sum those numbers
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
class f{
public: int p,w,d;
};
int main() {
	int n,dmin=0,dmax=0;
	ll m= LLONG_MAX;
	scanf("%d",&n);
	if(n==1) {printf("0\n"); return 0;}
	vector<f> friends;
	for(int i=0;i<n;i++){
		f fr;
		int pos,ws,dis;
		scanf("%d %d %d",&pos,&ws,&dis);
		fr.p = pos;
		fr.w = ws;
		fr.d = dis;
		dmax = max(pos,dmax);
		friends.push_back(fr);
	}
	sort(friends.begin(),friends.end(),[&](f x, f y){return x.p<y.p;});

	while(dmax-dmin>1){
		ll c1=0,c2=0; int mid=(dmax+dmin)/2;
		for(int i=0;i<n;i++){
			// compares the two middlemost points to binary search
			c1+=max(0,friends[i].w*(abs(friends[i].p-mid)-friends[i].d));
			c2+=max(0,friends[i].w*(abs(friends[i].p-mid+1)-friends[i].d));
		}
		if(c1 >=	 c2) dmax = mid;
		else dmin = mid+1;
		m = min(c1,m); m = min(c2,m);
	}
	cout<<m<<"\n";
}
