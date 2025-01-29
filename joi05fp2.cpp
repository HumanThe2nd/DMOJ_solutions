/*
JOI '05 Final Round P2 - String
Author: Dan Shan
Date: 2025-01-28
Each operation: 
for every segment of consecutive digits, concatenate its frequency and digit to the new string
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    vector<string> s(21);
    cin >> n >> s[0];
    for(int i=0;i<n;i++){
        int c=1,l=s[i].size();
        for(int j=0;j<l;j++){
            if(j==l-1||s[i][j]!=s[i][j+1]){
                s[i+1]+=to_string(c);
                s[i+1]+=s[i][j];
                c=1;
            }
            else c++;
        }
    }
    cout << s[n] << "\n";
}
