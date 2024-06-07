// Cat Lovers
// By: Dan Shan
#include <stdio.h>
int main() {
	int n,c=0,d=0;
    scanf("%d",&n); getchar_unlocked();
    for(int t=0;t<n;t++){
        char s=getchar_unlocked();
        if(s=='c') c++;
        else d++;
        for(int i=0;i<4;i++) getchar_unlocked();
    }
    if(c==d)printf("equal\n");
    else if(c>d) printf("cats\n");
    else printf("dogs\n");
}
