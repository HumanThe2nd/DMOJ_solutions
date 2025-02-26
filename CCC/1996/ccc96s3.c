// CCC '96 S3 - Pattern Generator
// Author: Dan Shan
// Date: 2024-09-28
// start from back, flip first 10 to 01 and reverse the trailing digits
#include <stdio.h>
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        char s[n+1]; s[n]='\0';
        for(int i=0;i<k;i++) s[i]='1';
        for(int i=k;i<n;i++) s[i]='0';
        printf("The bit patterns are\n%s\n",s);
        while(1){
                int f=1;
                for(int i=n-1;i>0;i--){
                        if(s[i]=='0'&&s[i-1]=='1'){ // flip 
                                s[i]='1'; s[i-1]='0';
                                f=0;
                                for(int j=1;j<=(n-i-1)/2;j++){ // reverse 
                                        char temp=s[i+j];
                                        s[i+j]=s[n-j];
                                        s[n-j]=temp;
                                }
                                printf("%s\n",s);
                                break;
                        }
                }
                if(f) break;
        }
        if(t) printf("\n");
    }
}
