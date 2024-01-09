// Next Prime (Hard)
// By: Dan Shan
// Miller-Rabin + Russian Peasant
// assisted by gpt
#include<stdio.h>
#include<stdlib.h>
#define ll unsigned long long int

ll multiply(ll a, ll b, ll mod) {
    ll result = 0;
    a %= mod;
    while (b) {
        if (b & 1)
            result = (result + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return result;
}

ll power(ll x, ll y, ll p) {
    ll res = 1;
    x %= p;
    while (y > 0) {
        if (y & 1)
            res = multiply(res, x, p);
        y = y >> 1;
        x = multiply(x, x, p);
    }
    return res;
}

int millerRabin(ll d, ll n) {
    ll a = 2 + rand() % (n - 4);
    ll x = power(a, d, n);
    if (x == 1 || x == n - 1)
        return 1;
    while (d != n - 1) {
        x = multiply(x, x, n);
        d *= 2;
        if (x == 1)
            return 0;
        if (x == n - 1)
            return 1;
    }
    return 0;
}

int prime(ll n) {
    if (n <= 1 || n == 4) return 0;
    if (n <= 3) return 1;
    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (int i = 0; i < 2; i++)
        if (!millerRabin(d, n))
            return 0;
    return 1;
}

int main() {
    ll n;
    scanf("%llu", &n);
    while (!prime(n)) {
        n++;
    }
    printf("%llu\n", n);
    return 0;
}
