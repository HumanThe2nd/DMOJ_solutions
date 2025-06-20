// DMOPC '21 Contest 8 P1 - Peanut Planning
// By: Dan Shan
// Note: duplicate elements may occu so a map or multiset should be used instead of set
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    multiset<int> s;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        s.insert(a);
    }
    int b=*s.begin(),a[n],l=1;
    s.erase(s.find(b));; a[0]=b;
    while(!s.empty()){
        if(s.lower_bound(m-b)==s.end()) return printf("-1\n")*0;
        b=*s.lower_bound(m-b);
        s.erase(s.find(b));
        a[l]=b; l++;
    }
    for(int i=0;i<n-1;i++) printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
}
