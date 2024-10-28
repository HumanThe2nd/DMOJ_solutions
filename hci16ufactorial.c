/*
HCI '16 - Unexpected Factorial
Author: Dan Shan
Date: 2024-10-28
for every '!' check previous 2 digits if its a valid number store it
take factorial of that number and output
*/
#include <stdio.h>
int main() {
    char s[100001];
    unsigned long long l=0,f=1,e=1;
    scanf("%[^\n]",s);
    for(int i=1;i<100001;i++){
        if(s[i]=='!'){
            if(s[i-1]>='0'&&s[i-1]<='9') {
                l+=s[i-1]-'0'; e=0; // special case 0!
                if(i>1&&s[i-2]>='0'&&s[i-2]<='9') l+=(s[i-2]-'0')*10;
            }
        }
        if(s[i]=='\0') break;
    }
    if(e) return printf("-1\n")*0;
    while(l>0){
        f*=l;
        l--;
    }
    printf("%lld\n",f)*0;
}
