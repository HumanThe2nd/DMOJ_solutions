// CCC '20 S3 - Searching for Strings
// Author: Dan Shan
// Date: 2024-09-06
// Store pattern letters in array, keep track of letters in substring of text
// if frequency array of subsrting doesn't matches pattern continue 
// Rabin Karp and count each valid subsrting hash
// store each counted hash in hash_set to avoid duplicates.
#include <bits/stdc++.h>
using namespace std;
int a[26],a2[26];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s,s2;
	cin >> s >> s2;
	unsigned long long l=s.length(),l2=s2.length();
	unordered_set<long long> v;
    long long d=256,q=100000000003; // 1e14+3
    long long i,j,c=0,t=0,h=1; // text hash
    for(i=0;i<l;i++){
        a[s[i]-'a']++; a2[s2[i]-'a']++;
    }
	for(i=0;i<l-1;i++){
        h=(h*d)%q;
    }
    for(i=0;i<l;i++){
        t=(t*d+s2[i])%q;
    }
    for(j=0;j<26;j++){
        if(a[j]!=a2[j]) break;
    } 
    if(j==26){
        c++;
        v.insert(t);
    } 
    for(i=l;i<l2;i++){
        t=(d*(t-s2[i-l]*h)+s2[i])%q; // shift hash right
        a2[s2[i-l]-'a']--; a2[s2[i]-'a']++; // shift character track right
        if(t<0) t+=q;
        for(j=0;j<26;j++) if(a[j]!=a2[j]) break;
        if(j==26&&v.find(t)==v.end()){ // frequency does not match or already counted
            c++;
            v.insert(t);
        }
    }
    printf("%lld\n",c);
}
