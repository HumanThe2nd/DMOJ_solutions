// CCC '16 S2 - Tandem Bicycle
// By: Dan Shan
// Goal: find min or max for pairs from 2 lists
// Approach: sort one ascending and for min we sort the other ascending as well 
//           for max we sort the second descending
#include<bits/stdc++.h>
using namespace std;
int main(){
int q,n,s=0;
scanf("%d %d",&q,&n);
vector<int> v1,v2;
for(int i=0;i<n;i++){
	int in;
	scanf("%d",&in);
	v1.emplace_back(in);
}
for(int i=0;i<n;i++){
	int in;
	scanf("%d",&in);
	v2.emplace_back(in);
}
sort(v1.begin(),v1.end());
if(q==2){
sort(v2.begin(),v2.end(),greater<int>());
	for(int i=0;i<n;i++){
		s+=max(v1[i],v2[i]);
	}
}
else{
	sort(v2.begin(),v2.end());
	for(int i=0;i<n;i++){
			s+=max(v1[i],v2[i]);
		}
}
printf("%d\n",s);
}
