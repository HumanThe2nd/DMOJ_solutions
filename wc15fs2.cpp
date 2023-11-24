//============================================================================
// Name        : WC '15 Finals S2 - Hydration
// Author      : Dan Shan
//============================================================================
// Note: used editoral
// Goal: test if all int c fit within a range if not -1 else print the minimum time
//       it takes for all to finish
// Approach: Binary search minimum return -1 if larger than there are cows
#include<iostream>
#include<algorithm>
int n,m,k; // # cows, # troughs, max range cow can go down, counter
int main(){
scanf("%d %d %d",&n,&m,&k);
int c[n+1],t[m+1];

for(int i=1;i<=n;i++){
	scanf("%d",&c[i]);
}
for(int i=1;i<=m;i++){
	scanf("%d",&t[i]);
}
std::sort(c+1,c+n+1);
std::sort(t+1,t+m+1);
int min=1, max=n, res=n+1;
while(min<=max){
	int mid = (min+max)/2,cnt=0,j=1;
	bool r = 0;
	for(int i=1;i<=m;i++){ //
		while(j<=n && t[i]<=c[j] && t[i] >= c[j] - k && cnt<mid){
			j++; cnt++;
		}
		cnt = 0;
		if(j>n) {r=1; break;}
	}
	if(r){
		res = mid; max = mid-1;
	}
	else min = mid+1;
}
printf("%d\n",res>n?-1:res);
}
