// Appleby Contest '19 P2 - The Love Letter
// Author: Dan Shan
// Caesar Cypher
#include<stdio.h>
int main() {
	int n,l;
    scanf("%d %d",&n,&l);
    getchar_unlocked(); l%=26;
    for(int i=0;i<n;i++){
        char c=getchar_unlocked();
        if(c==' ') putchar_unlocked(c);
        else{
            int s = c-'a'+l; s%=26;
            putchar_unlocked(s+'a');
        }
    }
    putchar_unlocked('\n');
}
