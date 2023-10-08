//============================================================================
// Name        : Unique Elements
// Author      : Dan Shan
//============================================================================
// Goal: count unique integers
// Approach: store each input in a set to remove duplicates and print size
#include <iostream>
#include <unordered_set>
int main() {
int n;
scanf("%d",&n);
std::unordered_set<int> s;
for(int i=0;i<n;i++){
	int in;
	scanf("%d",&in);
	s.insert(in);
}
printf("%d\n",(int)s.size());
}
