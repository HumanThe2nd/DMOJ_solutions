/*
DMOPC '14 Exam Time P1 - French Homework
Author: HumanThe2nd
Date: 2025-03-08
check last letter of second word and print respectively
*/
#include <bits/stdc++.h>
using namespace std;
int main() { // brute force
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s,s2;
    cin >> s >> s2;
    cout << s;
    if(s2.back()=='s') cout << "-tu les "  << s2 << " ?\n";
    else if(s2.back()=='e') cout << "-tu la "  << s2 << " ?\n";
    else cout << "-tu le "  << s2 << " ?\n";
}
