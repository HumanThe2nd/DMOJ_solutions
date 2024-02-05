// CCC '12 S2 - Aromatic Numbers
// By: Dan Shan
/* Test Case 2:
 * if the number is > or = to the next its subtracted:
 * I = I < X  >  V < X
 * 2 - 3 + 20 - 45 + 10 = -16
*/
#include <stdio.h>
int main() {
    int c=0;
    char s[21],ord[]={'I','V','X','L','C','D','M'};
    scanf("%s",s);
    for(int i=0;i<20;i+=2){
        if(s[i]=='\0') break;
        int m = s[i]-'0';
        if(s[i+1]=='V')m*=5;
        else if(s[i+1]=='X')m*=10;
        else if(s[i+1]=='L')m*=50;
        else if(s[i+1]=='C')m*=100;
        else if(s[i+1]=='D')m*=500;
        else if(s[i+1]=='M')m*=1000;
        if(s[i+3]=='\0'){
            c+=m;
            break;
        }
        int oi=0,of=0;
        for(int j=0;j<7;j++){
            if(ord[j]==s[i+1]) oi=j;
            if(ord[j]==s[i+3]) of=j;
        }
        if(of>oi)c-=m;
        else c+=m;
    }
    printf("%d\n",c);
}
