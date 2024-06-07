// Back To School '16: Harambe
// Author: Dan Shan
// count lower and uppercase occruence
// note: ascii for lower case letters are 32 greater than upper case
// using that fact we can convert the least occuring case to the other
#include <stdio.h>
int main() {
	char s[1025];
    s[0]=getchar_unlocked();
    int c=0,l=0,u=0;
    while(s[c]!='\n'){
        if(s[c]>='a'&&s[c]<='z') l++;
        if(s[c]>='A'&&s[c]<='Z') u++;
        c++;
        s[c]=getchar_unlocked();
    }
    if(l==u){
        for(int i=0;i<=c;i++) putchar_unlocked(s[i]);
    }
    else if(l<u){
        for(int i=0;i<c;i++) {
            if(s[i]>='A'&&s[i]<='Z') putchar_unlocked(s[i]);
            else if(s[i]>='a'&&s[i]<='z') putchar_unlocked(s[i]-32);
            else putchar_unlocked(s[i]);
        }
        putchar_unlocked('\n');
    }
    else{
        for(int i=0;i<c;i++) {
            if(s[i]>='A'&&s[i]<='Z') putchar_unlocked(s[i]+32);
            else if(s[i]>='a'&&s[i]<='z') putchar_unlocked(s[i]);
            else putchar_unlocked(s[i]);
        }
        putchar_unlocked('\n');
    }
}
