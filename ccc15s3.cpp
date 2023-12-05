//============================================================================
// Name        : CCC '15 S3 - Gates
// Author      : Dan Shan
//============================================================================
// Approach: store negative numbers and input gates as negative to use built in binary search
#include<bits/stdc++.h>
int g,p;
std::set<int> s;
int main(){
	scanf("%d %d",&g,&p);
	for(int i=1;i<=g;i++){
	s.insert(-i);
	}
	for(int i=0;i<p;i++){
		int pi;
		scanf("%d",&pi);
		auto it = s.lower_bound(-pi);
		if(it != s.end()){
			s.erase(it);
		}
		else break;
	}
	printf("%d\n",g-(int)s.size());
}
