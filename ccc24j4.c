// CCC '24 J4 - Troublesome Keys
// By: Dan Shan
#include <stdio.h>
#include <string.h>
int main() {
    char s1[500001],s2[500001],q='-';
    scanf("%s %s",s1,s2);
    int l1 = strlen(s1), l2 = strlen(s2);
    int i,j=0;
    char s[]={'-','-'}; // Initialize s[0] and s[1] to '-'
    for(i=0;i<=l1;i++){
        if(j>l2) break;
        if(s1[i]==s2[j]){
            j++;
            continue;
        }
        if(s1[i]==q){
            continue;
        }
        else if(s1[i+1]==s2[j]) q=s1[i];
        else{
            s[0]=s1[i]; s[1]=s2[j]; j++;
        }
    }
    printf("%c %c\n%c\n",s[0],s[1],q);
}
