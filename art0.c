// Art Academy 0: Prologue
// Author: Dan Shan
#include <stdio.h>
int main() {
	int n;
    scanf("%d",&n); getchar_unlocked();
    for(int t=0;t<n;t++){
        char c=getchar_unlocked();
        while(c!='\n') {
            if(c=='a'||c=='A') printf("Hi! ");
            else if(c=='e'||c=='E') printf("Bye! ");
            else if(c=='i'||c=='I') printf("How are you? ");
            else if(c=='o'||c=='O') printf("Follow me! ");
            else if(c=='u'||c=='U') printf("Help! ");
            else if(c<='9'&&c>='0') printf("Yes! ");
            c=getchar_unlocked();
        }
        putchar_unlocked('\n');
    }
}
