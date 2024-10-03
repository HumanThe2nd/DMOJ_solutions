// CCC '00 S5 - Sheep and Coyotes
// Author: Dan Shan
// Date: 2024-09-25
// Perpendicular bisectors, reference material: mmhs.ca/ccc/2000/S5SheepandCoyotesPBMethod.txt
// note: if 2 points intersect x axis togetehr they are both valid
// long double overflows but shifting digits 3 left fixes it.
#include <stdio.h>
int main() {
	int n;
	scanf("%d",&n);
	long double x[n],y[n];
	int v[n];
	for(int i=0;i<n;i++) v[i]=0; // Initialize v array
	for(int i=0;i<n;i++) {
		scanf("%Lf %Lf",&x[i],&y[i]);
		x[i]*=1e3; y[i]*=1e3;
	}
	for(int i=0;i<n;i++){
		long double l=0,r=1e6;
		for(int j=0;j<n;j++){
			if(i==j||v[i]||v[j]) continue; // skip
			long double xm=(x[i]+x[j])/2,ym=(y[i]+y[j])/2;
			if(x[i]==x[j]){
				if(y[i]<y[j]) v[j]=1;
				else v[i]=1;
				continue;
			}
			long double s=(x[i]-x[j])/(y[j]-y[i]);
			long double p=-ym/s+xm;
			if(x[i]>x[j]){
				if(p>l) l=p;
			}
			else if(p<r) r=p;
		}
		if(l>r) v[i]=1;
	}
	for(int i=0;i<n;i++){
		if(!v[i]) {
			x[i]/=1e3; y[i]/=1e3;
			printf("The sheep at (%0.2Lf, %0.2Lf) might be eaten.\n",x[i],y[i]);
		}
	}
}
