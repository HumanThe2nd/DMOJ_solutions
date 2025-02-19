//============================================================================
// Name        : CCC '17 S3 - Nailed It!
// Author      : Dan Shan
//============================================================================
// Goal: find most common sum of any two numbers from a list and its # of combinations
#include <stdio.h>
int l[2001],s[4001],length,c; // s for sums
int main(){
	int n; // length for most common number of sums, c to count most common
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d",&in);
		l[in]++; // count number of boards of length i
	}
	for(int i=1;i<2000;i++){
		for(int j=i+1;j<=2000;j++){
		    if(l[i]>l[j])s[i+j]+=l[j];
			else s[i+j]+=l[i];// add the number of each combination to the value
		}
		s[i*2]+=l[i]/2;
	}
	for(int i=1;i<=4000;i++){
		if(s[i]>length) {
			length=s[i];
			c=1;
		}
		else if(s[i]==length) c++;

	}

	printf("%d %d\n",length,c);
}
