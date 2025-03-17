/*
CCC '25 J3 - Product Codes
Author: HumanThe2nd
Date: 2025-03-17
Iterate over string and hard code each possibility:

digit -> update current number, otherwise add current number to total sum
if negative sign, set the negative flag to one
if an uppercase letter, output it
print the total sum at the end of each string
*/
#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char s[10001];
        int res=0,n=0,c=0;
        scanf("%s",s);
        for(int i=0;i<10001;i++){
            if(s[i]=='\0') break; // end reached
            if(s[i]>='0'&&s[i]<='9') c=c*10+s[i]-'0';
            else{
                if(n) res-=c;
                else res+=c;
                c=0; n=0;
            }
            if(s[i]=='-') n=1;
            if(s[i]>='A'&&s[i]<='Z') putchar(s[i]);
        }
        if(n) res-=c;
        else res+=c;
        printf("%d\n",res);
    }
}
