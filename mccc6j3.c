// Mock CCC '24 Contest 1 J3 - RGB Words
// Author: Dan Shan
// Date: 2024-09-25
// count number of 'R's and 'G's so far
// 'R's can be split by a 'G' which can be dealt with using a second variable to count 'R's with and without a 'G' seperately
#include <stdio.h>
int main() {
    int n;
	scanf("%d ",&n);
	long long c=0,r=0,r2=0,b=0,g=0;
	while(n--){
		char s=getchar_unlocked();
		if(s=='R'){
			if(!g) r++;
			else r2++;
		}
		if(s=='B'&&g) c+=r;
		if(s=='G'){
			if(!g) g=1;
			else{
				g=1; r=r2; r2=0;
			}
		}
	}
	printf("%lld\n",c);
}
