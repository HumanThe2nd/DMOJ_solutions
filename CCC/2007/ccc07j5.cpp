// CCC '07 J5 - Keep on Truckin'
// By: Dan Shan
// Note: DMOJ staff made extra test cases requiring long integers to pass
#include<iostream>
#include<map>
using ll = long long;
int main(){
int a,b,n;
scanf("%d %d %d",&a,&b,&n);
std::map<ll,ll> m;
m[0]=1; m[990]=0; m[1010]=0; m[1970]=0; m[2030]=0;
m[2940]=0; m[3060]=0; m[3930]=0; m[4060]=0; m[4970]=0;
m[5030]=0; m[5990]=0; m[6010]=0; m[7000]=0;
for(ll i=0;i<n;i++){
	ll in;
	scanf("%lld",&in);
	m[in]=0;
}
for(auto x:m){
	for(auto y:m){
		ll d = y.first-x.first;
		if(d>=a&&d<=b){
			m[y.first]+=m[x.first];
		}
	}
}
printf("%lld\n",m[7000]);
}
