/*
OTHS Coding Competition 4 P4 - Mathemagical Experiment
Author: Dan Shan
Date: 2025-04-30
Problem summary:
given array of positive integers
3 Queries:
1. increment/decrement the value of an integer
2. multiply all elements by a small integer
3. return the value at an index

Observation: We can keep a offset for total multipliers & local offsets of each multiplier
Warning: Negative modulus -> this code adds the square of the mod pre-modulus

Worst Case Time Complexity: O(N+Q*log(Q))
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
#define bs 1<<24 // Templates
typedef long long ll;
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
ll scan(){ // Fast input
    ll num=0;
    int neg=0;
    while (*ptr!='-'&&(*ptr<'0'||*ptr>'9')) ++ptr; // Skip non-digit/non-negative characters
    if (*ptr=='-') {
        neg=1;
        ++ptr;
    }
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return neg?-num:num;
}
inline void print(ll n) { // fast output
    if(n<0){
        putchar('-');
        n=-n;
    }
    if(!n) putchar('0');
    char s[10];
    ll i=0;
    while(n>0){
        s[i++]=(n%10)+'0';
        n/=10;
    }
    while (--i >= 0) {
        putchar(s[i]);
    } putchar('\n');
}
inline ll md(ll ai,ll m){ // modulus with negatives
    return (ai+m*m)%m;
}
inline ll mod_pow(ll b,ll e,ll mod){ // fast exponent with modulus
    ll res=1;
    b=md(b,mod);
    while(e>0) {
        if(e&1)  // If exponent is odd
            res=md(res*b,mod);

        b=md(b*b,mod);
        e>>=1;
    }
    return res;
}
ll m[12],mi[200001][12]; // multipler, local multiplier
int main() {
    buff();
    ll n=scan(),q=scan(),mod=1e9+7;
    ll a[n+1];
    for(ll i=1;i<=n;i++) {
        a[i]=scan();
        if(a[i]<0) a[i]+=mod;
    }
    while(q--){
        ll ai=scan(),bi=scan();
        if(ai==2) { // increment global multipler
            m[bi+5]++;
            continue;
        }
        for(int i=0;i<11;i++){ // apply & reset local multipliers 
            ll di=m[i]-mi[bi][i];
            if(!di) continue; // no difference
            mi[bi][i]=m[i];
            a[bi]=md(a[bi]*mod_pow(i-5,di,mod),mod);
        }
        if(ai==1){
            ll ci=scan();
            a[bi]=(a[bi]+ci+mod)%mod; 
        }
        else print(a[bi]);
    }
}
