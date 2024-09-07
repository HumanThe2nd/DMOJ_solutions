// CCCHK '08 J4 - Tic-tac-toe
// Author: Dan Shan
// Problem contains a lot of special cases
// 2 wins can be stacked if same symbol (specifically X)
// can't have over 1 horizontal or vertical win
// if one wins the other player must be exactly 1 move behind
#include <stdio.h>
int main() {
	int t;
    scanf("%d",&t);
    while(t--){ getchar_unlocked();
        char s[10],c1='.',c2='.';
        int c=0,n=0,f=1;
        for(int i=0;i<9;i++){
            s[i]=getchar_unlocked();
            if(s[i]=='.') continue;
            if(s[i]=='O') n++;
            else c++;
            if(i%3==2&&s[i]!='.'&&s[i]==s[i-1]&&s[i]==s[i-2]) {
                f--; // horizontal wins
                if(c1=='.') c1=s[i];
                else if(c2=='.') c2=s[i];
                else f=-1; // over 2 wins occured
            }
        }
        int f2=1;
        if(s[0]!='.'&&s[0]==s[3]&&s[3]==s[6]) {
            f2--;
            if(c1=='.') c1=s[0];
            else if(c2=='.') c2=s[0];
            else f=-1; // over 2 wins occured
        }
        if(s[1]!='.'&&s[1]==s[4]&&s[4]==s[7]){
            f2--;
            if(c1=='.') c1=s[1];
            else if(c2=='.') c2=s[1];
            else f=-1; // over 2 wins occured
        }
        if(s[2]!='.'&&s[2]==s[5]&&s[5]==s[8]){
            f2--;
            if(c1=='.') c1=s[2];
            else if(c2=='.') c2=s[2];
            else f=-1; // over 2 wins occured
        }
        if(s[0]!='.'&&s[0]==s[4]&&s[4]==s[8]){
            if(c1=='.') c1=s[0];
            else if(c2=='.') c2=s[0];
            else f=-1; // over 2 wins occured
        }
        if(s[2]!='.'&&s[2]==s[4]&&s[4]==s[6]){
            if(c1=='.') c1=s[2];
            else if(c2=='.') c2=s[2];
            else f=-1; // over 2 wins occured
        }
        if(f<0||f2<0||n>c||n<c-1) printf("no\n");
        else if(c2!='.'&&c1!=c2) printf("no\n"); // the 2 wins were not the same person
        else if((c1=='O'&&c>n)||(c1=='X'&&n>=c)) printf("no\n"); // x moves after o won
        else printf("yes\n",c,n,c1);
    }
}
