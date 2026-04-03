/*
CCC '26 S3 - Common Card Choice
Author: Dan Shan
Date: Apr 2, 2026

Approach:
Type 1:
1st value is known -> all values are known
Case 1: even, even
Case 2: even, odd + odd
Case 3: odd + odd, odd + odd
Case 4: odd/even, odd/even (must share common factor) 
Case 5: odd/even, odd/even + odd/even (must share common factor) 
Else: impossible

Type 2:
if 1st value is -1 implies all -1 (unknown)
Best chances:
- 100 guesses
- 2 pairs of distinct indexes
- I couldn't get it to work with non-random numbers 
no clue what the intended solution is

Comments:
Fun parity proof problem part 1
Implementation hell :P
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma GCC optimize("Ofast")
typedef long long ll;
#define BS (1 << 24)
char buf[BS];
char *ptr = buf;
inline void buff() {
    fread(buf, 1, BS, stdin);
    ptr = buf;
}
static inline ll scan() {
    ll x = 0, neg = 0;
    while (*ptr < '0') {neg = (*ptr == '-'); ++ptr;}
    while (*ptr >= '0' && *ptr <= '9') {
        x = x * 10 + (*ptr - '0');
        ++ptr;
    }
    if(neg) return -x;
    return x;
}
ll gcd(ll a, ll b){
	if(b>a){ // make a the larger
		ll temp = b;
		b = a; a = temp;
	}
	while(b){
		ll r = a % b;
		a = b; b = r;	
	}
	return a;
}
int main(){
    buff();
    ll n = scan(), a[n];
    for(int i = 0; i < n; ++i) a[i] = scan();
    if(a[0] > 0){ // Type 1
        int e[3], re = 0, o[5], ro = 0;
        for(int i = 0; i < n; ++i){
            if(re > 1 || ro > 4) break; // guranteed match found
            if(a[i] & 1){ // odd
                o[ro++] = i + 1;
            }
            else{ // even
                e[re++] = i + 1;
            }
        }
        if(re > 1){ // case 1
            puts("YES\n1 1");
            printf("%d\n%d\n", e[0], e[1]);
        }
        else if(re && ro > 1){ // case 2
            puts("YES\n1 2");
            printf("%d\n%d %d\n", e[0], o[0], o[1]);
        }
        else if(ro > 3){ // case 3
            puts("YES\n2 2");
            printf("%d %d\n%d %d\n", o[0], o[1], o[2], o[3]);
        }
        else{ // Could be proven that ro is capped at 3
            if(re) o[ro++] = e[0]; // may be up to 1 extra even
            if(ro < 2) return !puts("NO"); // insufficient
            for(int i = 0; i < ro; ++i){ // Case 4
                if(gcd(a[o[i] - 1], a[o[(i + 1) % ro] - 1]) > 1){
                    puts("YES\n1 1");
                    return !printf("%d\n%d\n", o[i], o[(i + 1) % ro]);
                }
            }
            if(ro > 2){ // Case 5
                if(gcd(a[0] + a[1], a[2]) > 1){
                    puts("YES\n2 1");
                    return !puts("1 2\n3");
                }
                else if(gcd(a[0], a[1] + a[2]) > 1){
                    puts("YES\n1 2");
                    return !puts("1\n2 3");
                }
                else if(gcd(a[1], a[0] + a[2]) > 1){
                    puts("YES\n1 2");
                    return !puts("2\n1 3");
                }
            }
            puts("NO");
        }
    }
    else{ // Type 2
        srand(time(NULL));
        puts("100");
        for(int i = 0; i < 100; ++i){ // guess...
            puts("2 2");
            int ai = rand() % 100001, bi = rand() % 100001, ci = rand() % 100001, di = rand() % 100001;
            printf("%d %d\n%d %d\n", ai, bi, ci, di);
        }
    }
}
