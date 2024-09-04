// CCC '09 J4 - Signage
// Author: Dan Shan
// Fit max words per row, space-seperated
// Fill spaces using modulus
#include <stdio.h>
int main() {
	int n,l=0,a[]={8,3,4,5,5,6};
    scanf("%d",&n);
    char s[6][100]={"WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"};
    while(l<6){
        int li=0,w=0;
        while(l+w<6&&(a[l+w]+li<=n+1)){
            li+=a[l+w]; w++;
        } li-=w;
        int f=1,d=n-li,c=0;
        while(d--){
            int vi;
            if(w<2) vi=l;
            else vi=l+(c%(w-1));
            s[vi][a[vi]-1]='.';
            s[vi][a[vi]]='\0';
            a[vi]++; c++;
        }
        while(w--){
            printf("%s",s[l]);
            l++;
        }
        putchar_unlocked('\n');
    }
}
