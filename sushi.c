// Magical Sushi
// By: Dan Shan
// check ascii values and differences
#include <stdio.h>
#include <string.h>
int main() {
    char s[50001];
    scanf("%s",s);
    int l = strlen(s);
    for(int i=0;i<l;i++){
        if(i<l-2){
            if(s[i]==s[i+2]&&(s[i+1]-s[i]==1||s[i+2]-s[i+1]==1)){
                printf("Sushi is Here!\n");
                return 0;
            }
        }
        int c=0;
        for(int j=i+1;j<l;j++){
            if(s[i]==s[j]&&(c>1||s[j]-s[j-1]==1)) {
                printf("Sushi is Here!\n");
                return 0;
            }
            else if(s[j]-s[j-1]==1) c++;
        }
    }
    printf("Better Luck Next Time.\n");
}
