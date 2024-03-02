// CCC '24 S2 - Heavy-Light Composition
// By: Dan Shan
#include<stdio.h>
int main() {
    int t,n;
    scanf("%d %d",&t,&n);
    for(int i=0;i<t;i++){
        char s[n+1];int v[150];
        for(int j=0;j<150;j++) v[j]=0;
        scanf("%s",s);
        for(int j=0;j<n;j++) v[(int)s[j]]++;
        int f=0;
        for(int j=1;j<n;j++){
            if(v[s[j]]==1&&v[(int)s[j-1]]==1){
                    f = 1;
                    break;
            }
            else if(v[(int)s[j]]>1&&v[(int)s[j-1]]>1){
                    f = 1;
                    break;
            }
        }
        printf("%s\n",f?"F":"T");
    }
}
