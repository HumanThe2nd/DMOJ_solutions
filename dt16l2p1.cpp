/*
Diagnostic Test '16 Level 2 P1 - Polan cannot into space
Author: Dan Shan
Date: 2025-08-05
Burte Force all numbers
*/
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int c=0;
    while(1){
        string s;
        cin >> s;
        if(s=="No") break;
        if(s=="one") ++c;
        else if(s=="two") c+=2;
        else if(s=="three") c+=3;
        else if(s=="four") c+=4;
        else if(s=="five") c+=5;
        else if(s=="six") c+=6;
        else if(s=="seven") c+=7;
        else if(s=="eight") c+=8;
        else if(s=="nine") c+=9;
    }
    printf("%d\n",c);
}
