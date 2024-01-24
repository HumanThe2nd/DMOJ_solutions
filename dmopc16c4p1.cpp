// DMOPC '16 Contest 4 P1 - Fast Exponents
// By: Dan Shan
#include<iostream>
#include<unordered_set>
int main() {
std::unordered_set<long long> s;
long long t=1; s.insert(1);
for(int i=0;i<64;i++){
	t*=2;
	s.insert(t);
}
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
	long long int d;
	scanf("%lld",&d);
	if(s.find(d)==s.end())printf("F\n");
	else printf("T\n");
}
}
