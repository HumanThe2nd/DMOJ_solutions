//============================================================================
// Name        : USACO 2020 February Bronze P3 - Swapity Swap
// Author      : Dan Shan
//============================================================================
// Goal: predict array after reversing elements between indexes twice for k times
// Approach: find cycle count and simulate the modulus of k by the cycle count
#include <stdio.h>
int main() {
	int n, k, a1, a2, b1, b2,c=0;
	scanf("%d %d %d %d %d %d", &n, &k, &a1, &a2, &b1, &b2);
	int cows[n + 1]; // declares array to store cow at each index
	for (int i = 0; i <= n; i++)
		cows[i] = i; // initializing cows
	int s = 1,seg1[a2 - a1 + 1], seg2[b2 - b1 + 1];;
	do {
	      c++;
	      if (a1 != a2) {
	      			for (int j = a1; j <= a2; j++) {
	      				seg1[j - a1] = cows[j];
	      			}
	      			for (int j = a1; j <= a2; j++) {
	      				cows[a2 - j + a1] = seg1[j - a1];
	      			}
	      		}
	      		if (b1 != b2) {
	      			for (int j = b1; j <= b2; j++) {
	      				seg2[j - b1] = cows[j];
	      			}
	      			for (int j = b1; j <= b2; j++) {
	      				cows[b2 - j + b1] = seg2[j - b1];
	      			}
	      		}
	      s = 1;
	      for(int it=1;it<=n;it++)if(cows[it] != it)s=0;
	    }
	while(!s);
	    for (int i = 0; i <= n; i++)
	    		cows[i] = i; // reset cows
	for (int i = 0; i < k % c; i++) { // find remainder of cycle and after modding
		int seg1[a2 - a1 + 1], seg2[b2 - b1 + 1];
		if (a1 != a2) {
			for (int j = a1; j <= a2; j++) {
				seg1[j - a1] = cows[j];
			}
			for (int j = a1; j <= a2; j++) {
				cows[a2 - j + a1] = seg1[j - a1];
			}
		}
		if (b1 != b2) {
			for (int j = b1; j <= b2; j++) {
				seg2[j - b1] = cows[j];
			}
			for (int j = b1; j <= b2; j++) {
				cows[b2 - j + b1] = seg2[j - b1];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", cows[i]);
	}
}
