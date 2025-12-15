/*
CCC '21 S5 - Math Homework
Author: Dan Shan
Date: 2025-12-15

Observation: Min valid Ai: LCM of all Zi that covers it
Part A: Create array
1. Difference array: mark intervals of each GCD value 
2. Build PSA to find GCD values at each index
   Set r[i] = LCM of values at psa[i]
Part B: Check Validity
1. Build sparse table for GCD between points
2. Validate all queries (if any fail, array is invalid)

Optional: Bitmask to avoid recomputations (theortically faster)
I also uploaded a C++ version without bitmask and small optimizations 
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
#define BS (1<<24)
char buf[BS];
char *ptr = buf;
void buff() {
    fread(buf, 1, BS, stdin);
}
int scan() {
    int x = 0;
    while (*ptr < '0') ++ptr;
    while (*ptr >= '0') {
        x = x * 10 + (*ptr - '0');
        ++ptr;
    }
    return x;
}
int gcd(int a, int b){
	if(b > a){ // make a the larger
		int temp = b;
		b = a; a = temp;
	}
	while(b){
		int r = a % b;
		a = b; b = r;
	}
	return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
int lg2(int x) {
    return 31 - __builtin_clz(x);
}
int s[150005][17], cnt[17], r[150005], sp[20][150005], q[150005][3];
int main() {
    buff();
    int n = scan(), m = scan();
    for (int i = 0; i < m; ++i) {
        int x = scan() - 1, y = scan() - 1, z = scan();
        s[x][z]++;
        if (y + 1 < n) s[y + 1][z]--;
        q[i][0] = x; q[i][1] = y; q[i][2] = z;
    }

    /* Precompute LCM for all masks */
    int lcm_mask[1 << 15];
    lcm_mask[0] = 1;
    for (int mask = 1; mask < (1 << 15); ++mask) {
        int b = __builtin_ctz(mask);
        lcm_mask[mask] = lcm(lcm_mask[mask ^ (1 << b)], b + 2);
    }
    int mask = 0;
    for (int i = 0; i < n; ++i) { // GPT's suggestion
        for (int z = 2; z <= 16; ++z) {
            if (s[i][z]) {
                cnt[z] += s[i][z];
                if (cnt[z] > 0)
                    mask |= (1 << (z - 2));
                else
                    mask &= ~(1 << (z - 2));
            }
        }
        r[i] = lcm_mask[mask];
        sp[0][i] = r[i];
    }
    int LOG = lg2(n) + 1;
    for (int k = 1; k < LOG; ++k) {
        int len = 1 << k;
        for (int i = 0; i + len <= n; ++i) {
            sp[k][i] = gcd(sp[k-1][i], sp[k-1][i + (len >> 1)]);
        }
    }
    for (int i = 0; i < m; ++i) {
        int l = q[i][0], r0 = q[i][1], z = q[i][2];
        int len = r0 - l + 1,  k = lg2(len), g = gcd(sp[k][l], sp[k][r0 - (1 << k) + 1]);
        if(g != z) {
            return !puts("Impossible");
        }
    }
    printf("%d", r[0]);
    for (int i = 1; i < n; ++i) printf(" %d", r[i]);
    putchar('\n');
}
