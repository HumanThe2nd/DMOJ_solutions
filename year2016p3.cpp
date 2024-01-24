// New Year's '16 P3 - Arithmetic Snowman
// By: Dan Shan
#include<iostream>
#include<vector>
#include<algorithm>
int main() {
int n;
std::ios_base::sync_with_stdio(0);
std::cin.tie(0);
std::cin >> n;
std::vector<int> v(n);
for(int i=0;i<n;i++) std::cin >> v[i];
std::sort(v.begin(),v.end());
int m=1;
for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){ // second element
	int c =v[i],di=v[j]-v[i],l=i,d=0;
	for(int k=j;k<n;k++){
		if(v[k]-v[l]==di){
			c+=v[k];
			l=k;
			d++;
			if(d==2)break;
		}
		else if(v[k]-v[l]>di) break;
	}
	if(d==2) m = std::max(m,c);
	}
}
printf("%d\n",m);
}
