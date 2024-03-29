// EGOI '23 P1 - Inflation
// By: Dan Shan
// Theory: integer array to store number of items with each price 
// Switched to unordered maps for full solution as arrays exceeded memory on larger cases
// track inflation seperately and use it for calculating sums and setting
#include <unordered_map>
#include <cstdio>
long long scan() {
    long long num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
std::unordered_map<long long, int> m;
int main() {
    int n=scan(),q;
    long long c=0,inf=0;
    for(int i=0;i<n;i++){
        long long a=scan();
        m[a]++;
        c+=a;
    }
    q=scan();
    for(int i=0;i<q;i++){
        char s[10];
        scanf("%s",s);
        long long a=scan(),b;
        if(s[0]=='I') inf+=a;
        else {
            b=scan();
            if(a!=b&&m.find(a-inf)!=m.end()){
                c+=m[a-inf]*(b-a);
                if(m.find(b-inf)==m.end()) m[b-inf]=m[a-inf];
                else m[b-inf]+=m[a-inf]; 
                m[a-inf]=0;
            }
        }
        printf("%lld\n",c+inf*n);
    }
}
