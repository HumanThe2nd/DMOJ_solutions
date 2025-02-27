// COCI '20 Contest 6 #1 Bold
// By: Dan Shan
// 2d Array manipulation
#include <stdio.h>
int main() {
	int n,m;
    scanf("%d %d",&n,&m);
    char s[n][m],s2[n][m];
    for(int i=0;i<n;i++){
        getchar();
        for(int j=0;j<m;j++){
            s[i][j]=getchar();
            s2[i][j]=s[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%c",s2[i][j]);
            if(s[i][j]=='.') continue;
            if(j<m-1){
                s2[i][j+1]='#';
                if(i<n-1) s2[i+1][j+1]='#';
            }
            if(i<n-1) s2[i+1][j]='#';
        }
        printf("\n");
    }
}
