// ECOO '21 P2 - DNA Derren
// Author: Dan Shan
// check eqaulity between each 2 characters 
#include <stdio.h>
int main(int argc, char *argv[]) {
    char c=getchar_unlocked(),cl='S';
    while(c!='\n'){
        if(cl=='A'&&c=='A') putchar_unlocked(' ');
        else if(cl!='A'&&c!='A'&&c!='S')  putchar_unlocked(' ');
        putchar_unlocked(c); cl=c;
        c=getchar_unlocked();
    }
}
