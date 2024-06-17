// DWITE '12 R2 #2 - Word Arithmetic
// Author: Dan Shan
#include <stdio.h>
int main() {
    for(int t=0;t<5;t++){
        int w[255],w2[255],l=0,r=0,e=0,o=0;
        char s[256];
        char c=getchar_unlocked();
        while(c!=' '){
            w[l]=c-'A'; l++;
            c=getchar_unlocked();
        } c=getchar_unlocked(); // skip space
        while(c!='\n'){
            w2[r]=c-'A'; r++;
            c=getchar_unlocked();
        }
        while(l){ l--; r--;
            if(r<0){ // second word is finished
                s[o]=(w[l]+e)%26+'A'; o++;
                e=(w[l]+e)/26; // remainder
            }
            else {
                s[o]=(w[l]+w2[r]+e)%26+'A'; o++;
                e=(w[l]+w2[r]+e)/26; // remainder
            }
        }
        while(r>0){ r--; // first word finished
            s[o]=(w2[r]+e)%26+'A'; o++;
            e=(w2[r]+e)/26; // remainder
        } int tr=1;
        while(o--) {
            if(s[o]=='A'&&tr) continue;
            printf("%c",s[o]);
            tr=0;
        }
        printf("\n");
    }
}
