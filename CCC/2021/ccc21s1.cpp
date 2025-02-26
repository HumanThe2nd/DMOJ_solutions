//============================================================================
// Name        : CCC '21 S1 - Crazy Fencing
// Author      : HumanThe2nd
// Date        : 2023, Oct 1
//============================================================================
// Goal: find area of a chain of quadrilaterals
// Approach: input heights then sum the area between each 2 fences
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
int n;
double c;
scanf("%d",&n);
vector<int> heights;
for(int i=0;i<=n;i++){
	int in;
	scanf("%d",&in);
	heights.push_back(in);
}
for(int i=0;i<n;i++){
	int in;
	scanf("%d",&in);
	c+=in*((double)heights[i]+heights[i+1])/2;
}
printf("%lf\n",c);
return 0;
}
