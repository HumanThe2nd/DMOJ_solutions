/*
Max's Anger Contest Series 2 P2 - Password Anger
Author: Dan Shan
Date: 2025-05-06
Brute force every string combination of length n
*/
#include <bits/stdc++.h>
using namespace std;
int gethash(string s) {
    int hash = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        hash = hash * 13 + s[i] - 'a' + 1;
    }
    return hash;
}

int main() {
    int n,m,c=0;
    cin >> n >> m;
    string s;
    for(int i=0;i<n;i++) s.push_back('a');
	for(int i=0;i<26;i++){
        s[0]='a'+i;
        if(n>1){
             for(int j=0;j<26;j++){
                s[1]=j+'a';
                if(n>2){
                    for(int k=0;k<26;k++){
                        s[2]=k+'a';
                        if(n>3){
                            for(int l=0;l<26;l++){
                                s[3]=l+'a';
                                c+=gethash(s)==m; // length 4
                            }
                        }
                        else c+=gethash(s)==m; // length 3
                    }
                }
                else c+=gethash(s)==m; // length 2
            }
        }
        else c+=gethash(s)==m; // length 1
    }
    cout << c << "\n";
}
