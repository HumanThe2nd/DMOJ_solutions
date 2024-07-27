// Back To School '17: 🅱aram🅱e
// Author: Dan Shan
#include <stdio.h>
int main() {
    char s[5000];
    scanf("%[^\n]%*c", s);
    for(int i=0;i<5000;i++){
        if(s[i]=='\0') {
            printf(".");
            break;
        }
        if(s[i+1]>64&&s[i+1]<91) printf(".");
        printf("%c",s[i]);
    }
    putchar('\n');
}
