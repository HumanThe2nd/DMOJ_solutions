/*
WC '17 Contest 3 J3 - Uncrackable
Author: HumanThe2nd
Date: 2025-04-30
return invalid if any are true:
1. length < 8 or length > 12
2. lowercase characters < 3
3. uppercase characters < 2
4. digits < 1
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int main() {
    int l=0,u=0,d=0;
    char s[101];
    scanf("%s",s);
    for(int i=0;i<13;i++){
        if(s[i]=='\0') {
            if(i<8) return !puts("Invalid");
            break;
        }
        if(i>11) return !puts("Invalid");
        if(s[i]>='a'&&s[i]<='z') l++;
        else if(s[i]>='A'&&s[i]<='Z') u++;
        else d++;
    }
    puts((l>2&&u>1&&d)?"Valid":"Invalid");
}
