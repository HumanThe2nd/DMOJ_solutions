/*
CCC '26 J3 - Creative Candy Consumption
Author: Dan Shan
Date: Mar 27, 2026
Approach:
hard code each combination and repeat
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    int p = 0, p2 = 0, c = 0, c2 = 0;
    while(p < a.size() && p2 < b.size()){
        if(a[p] == b[p2]) ++c, ++c2, ++p, ++p2;
        else if(a[p] == 'R' && b[p2] == 'G') ++c, ++p2;
        else if(a[p] == 'G' && b[p2] == 'R') ++c2, ++p;
        else if(a[p] == 'G' && b[p2] == 'B') ++c, ++p2;
        else if(a[p] == 'B' && b[p2] == 'G') ++c2, ++p;
        else if(a[p] == 'B' && b[p2] == 'R') ++c, ++p2;
        else ++c2, ++p;
    }
    c += a.size() - p;
    c2 += b.size() - p2;
    cout << c << "\n" << c2 << "\n";
}
