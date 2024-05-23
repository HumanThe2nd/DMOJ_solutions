// WC '01 P3 - Back to the Future
// By: Dan Shan
// Base Conversion + digit reversal
#include<stdio.h>
#include<math.h>
int main() {
	int t;
    scanf("%d",&t);
    while(t--){
        char s[50];
        int a,l=0;
        scanf("%d",&a);
        while(a){
            s[l]=(a&1)+'0';
            a>>=1; l++;
        }
        if(!l){
            s[l]='0'; l++;
        }
        s[l]='\0';
        int res=0,e=l; l--;
        while(e){
            e--;
            res+=(s[e]-'0')*pow(2,l-e);
        }
        printf("%d\n",res);
    }
}
