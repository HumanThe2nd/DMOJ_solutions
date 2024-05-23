// ACM U of T Tryouts C3 B - A Careful Reply
// By: Dan Shan
// note: hearts must be spaced out
#include <stdio.h>
int main() {
	int t;
    scanf("%d",&t); getchar_unlocked();
    while(t--){
        char c=getchar_unlocked();
        int s=0,h=1;
        while(c!='\n'){
            if(c=='<') s++;
            else if(c=='3'&&s){
                s=0; h++;
            }
            else s=0;
            c=getchar_unlocked();
        }
        while(h--)printf("<3 ");
        putchar('\n');
    }
}
