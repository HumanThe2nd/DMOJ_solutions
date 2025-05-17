// DWITE '11 R4 #1 - Crossword Count
// Author: Dan Shan
// for each row check number of lines longer than 1 and # seperated
// repeat for each column
#include <stdio.h>
int main() {
    int t=5;
    while(t--){
        int n,m,r=0,c=0;
        scanf("%d %d",&n,&m);
        char s[n][m];
        for(int i=0;i<n;i++){
            int sd=0; // sd for second .
            getchar_unlocked();
            for(int j=0;j<m;j++){
                s[i][j]=getchar_unlocked();
                if(s[i][j]=='.') {
                    if(sd==1) r++;
                    sd++;
                }
                else{
                    sd=0;
                }
            }
        }
        for(int i=0;i<m;i++){ // 0 for #
            int sd=0; // sd for second .
            for(int j=0;j<n;j++){
                if(s[j][i]=='.') {
                    if(sd==1) c++;
                    sd++;
                }
                else{
                    sd=0;
                }
            }
        }
        printf("%d %d\n",r,c);
    }
}
