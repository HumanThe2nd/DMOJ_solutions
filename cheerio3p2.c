/*
Cheerio Contest 3 P2 - Double-O-Seven
Author: Dan Shan
Date: 2025-09-15
TC: O(N)

Repeat for every move:
1.
reload: add 1 ammo
fire with ammo: we block (skip 2.) 

2.
if no ammo or opponent blocks: reload
else fire (gain 1 point)

it can be proven this playstyle results in max points
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int n, c = 0, a1 = 0, a2 = 0;
    char s[1000001];
    scanf("%d %s", &n, s);
    for(int i = 0; i < n; ++i){
        if(s[i] == 'R') ++a1;
        else if(s[i] == 'F' && a1) { // we block
            --a1;
            continue;
        }

        if(a2 && s[i] != 'B') ++c, --a2; // fire
        else ++a2; // reload
    }
    printf("%d\n", c);
}
