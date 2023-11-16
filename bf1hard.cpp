// List Minimum (Hard)
// By: Dan Shan
// Sort array and ouput
#include<iostream>
#include<vector>
#include<algorithm>
int main(){
int n;
scanf("%d",&n);
std::vector<int> v;
for(int i=0;i<n;i++){
int in;
scanf("%d",&in);
v.emplace_back(in);
}
std::sort(v.begin(),v.end());
for(auto x:v){
	printf("%d\n",x);
}
}
