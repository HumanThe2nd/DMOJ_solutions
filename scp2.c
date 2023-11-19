// Singularity Cup P2 - Reverse Substring Partitioning
// By: Dan Shan
// if start and end are different then partition not possible
// else length scales with adjacent elements that not equal and length 0 or less is always impossible
#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    char s[n];
    scanf("%s",s);
    if(s[0]!=s[n-1]){
        printf("%d\n",n);
    }
    else{
        int c=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])c++;
        }
        (n-c>1)?printf("%d\n",n-c):printf("1\n");
    }
}
