// COCI '06 Contest 5 #1 Trik
// Author: Dan Shan
#include <stdio.h>
int main() {
    short b=1;
    char c=getchar_unlocked();
    while(c!='\n'){
        if(c=='A'){
            if(b==1) b=2;
            else if(b==2) b=1;
        }
        else if(c=='B'){
            if(b==2) b=3;
            else if(b==3) b=2;
        }
        else {
            if(b==1) b=3;
            else if(b==3) b=1;
        }
        c=getchar_unlocked();
    }
    printf("%hd\n",b);
}
