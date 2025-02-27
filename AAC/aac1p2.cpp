// An Animal Contest 1 P2 - Alpaca Racing
// By: Dan Shan
// note: although d is irrelevant inputting it wrong will break the code
// I original inputted it as an integer which broke the code.
#include <iostream>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,k,x;
    long long d;
    std::cin >> n >> d >> k >> x;
    long long c=0,s,a[n],xd = 100-x;
    for(int i=0;i<n;i++) std::cin >> a[i];
    std::cin >> s;
    for(int i=0;i<n;i++){
        if(a[i]<s)continue;
        while(a[i]>=s){
            c++;
            a[i]*=xd; a[i]/=100;
    }
    }
    printf("%s\n",c>k?"NO":"YES");
}
