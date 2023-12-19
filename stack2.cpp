// Weapon Stacks
// By: Dan Shan
#include<iostream>
#include<stack>
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n,c=0;
    std::cin >> n;
    std::stack<int> s1,s2;
    bool l[n+1]; // locatiob
    for (int i=0;i<n;i++) {
        int j;
        std::cin >> j;
        s1.push(j);
        l[j]=0;
    }
    for(int i=1;i<=n;i++){
        int cur = l[i];
        while(1){
            c++;
        if(cur){
            int ci = s2.top();
            s2.pop();
            if(ci==i) break;
            s1.push(ci);
            l[ci]=0;
        }
        else{
            int ci = s1.top();
            s1.pop();
            if(ci==i) break;
            s2.push(ci);
            l[ci]=1;
        }
        }
    }
    std::cout << c << "\n";
}
