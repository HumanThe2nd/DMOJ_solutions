// COCI '12 Contest 6 #3 Dobri
// By: Dan Shan
#include <iostream>
#include<unordered_map>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::unordered_map<int,int> m;
    int n,c=0;
    std::cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        std::cin >> a[i];
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i;j>=0;j--){
            m[a[i]+a[j]]=i; // minimum index to get a sum of i+j
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            int index = a[i]-a[j];
            if(m.find(index)==m.end()||m[index]>=i) continue;
            c++; break;
        }
    }
    printf("%d\n",c);
}
