//============================================================================
// Name        : CCC '20 J4 - Cyclic Shifts
// Author      : Dan Shan
//============================================================================
// Goal: check if a shifted version of a string is contained within the other
// Approach: store all shifted variations and compare them which each substring of the other
#include<bits/stdc++.h>
int main(){
    std::unordered_set<std::string> s;
    std::string s1,s2;
    std::cin>>s1>>s2;
    for(int i=0;i<(int)s2.length();i++){
        s.insert(s2);
        s2 = s2.substr(1)+s2[0];
    }
    bool f=0;
    for(int i=0;i<=(int)(s1.length()-s2.length());i++){
        if(s.find(s1.substr(i,s2.length())) != s.end()) {
            f=1;
            break;
        }
    }
    if(f) printf("yes\n");
    else printf("no\n");
}
