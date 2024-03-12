// Purple Lemon
// By: Dan Shan
#include <stdio.h>
long long max(long long a, long long b) { return (a > b)? a : b; }

int main() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    long long t[m], w[n], v[n], l = 0;
    for(long long i = 0; i < m; i++) {
        scanf("%lld", &t[i]);
        if(t[i] > l) l = t[i];
    }
    for(long long i = 0; i < n; i++) scanf("%lld %lld", &w[i], &v[i]);

    long long dp[l+1];
    dp[0] = 0;
    for(long long i = 1; i <= l; i++) dp[i] = 0;

    for(long long i = 0; i < n; i++) {
        for(long long j = w[i]; j <= l; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    long long c = 0;
    for(long long i = 0; i < m; i++) if(dp[t[i]] > 0) c += dp[t[i]];
    printf("%lld\n", c);
}
