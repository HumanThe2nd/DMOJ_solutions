// CCC '06 S1 - Maternity
// Author: Dan Shan
// Date: 2024-09-14
// check first of each pair for dominant and last of each pair for recessive
#include <stdio.h>
int main() {
	char g[2][11];
    int n;
    scanf("%s %s %d",g[0],g[1],&n);
    while(n--){
        getchar_unlocked();
        char ci=getchar_unlocked();
        int f=1; // possible
        if(ci=='A'&&g[0][0]=='a'&&g[1][0]=='a') f=0;
        else if(ci=='a'&&(g[0][1]=='A'||g[1][1]=='A')) f=0;
        ci=getchar_unlocked();
        if(ci=='B'&&g[0][2]=='b'&&g[1][2]=='b') f=0;
        else if(ci=='b'&&(g[0][3]=='B'||g[1][3]=='B')) f=0;
        ci=getchar_unlocked();
        if(ci=='C'&&g[0][4]=='c'&&g[1][4]=='c') f=0;
        else if(ci=='c'&&(g[0][5]=='C'||g[1][5]=='C')) f=0;
        ci=getchar_unlocked();
        if(ci=='D'&&g[0][6]=='d'&&g[1][6]=='d') f=0;
        else if(ci=='d'&&(g[0][7]=='D'||g[1][7]=='D')) f=0;
        ci=getchar_unlocked();
        if(ci=='E'&&g[0][8]=='e'&&g[1][8]=='e') f=0;
        else if(ci=='e'&&(g[0][9]=='E'||g[1][9]=='E')) f=0;
        if(f) printf("Possible baby.\n");
        else printf("Not their baby!\n");
    }
}
