/*
DMOPC '21 Contest 10 P1 - Japaneasy
Author: Dan Shan
Date: 2025-03-07
start with checking 2 special cases: 'hu' and 'fu'
if current character is a vowel continue
if its a valid consonant followed by a valid vowel, skip next letter
otherwise its invlaid
Time Complexity: O(n)
*/
#include <stdio.h>
#include <string.h>
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        char s[1000001],f=1; // valid
        scanf("%s",s);
        int l=strlen(s);
        for(int i=0;i<l;i++){
            if(s[i]=='f'&&s[i+1]=='u'){ // special case 'fu'
                i++; continue;
            }
            if(s[i]=='h'&&s[i+1]=='u'){ // special case: 'hu'
                f=0; break;
            }
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='u'||s[i]=='o') continue;
            if(s[i]=='k'||s[i]=='n'||s[i]=='h'||s[i]=='m'||s[i]=='r'){
                if(s[i+1]=='a'||s[i+1]=='e'||s[i+1]=='i'||s[i+1]=='u'||s[i+1]=='o') {
                    i++; continue;
                }
            }
            f=0;
        }
        puts(f?"YES":"NO");
    }
}
