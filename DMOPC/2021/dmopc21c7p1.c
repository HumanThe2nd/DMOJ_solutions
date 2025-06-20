// DMOPC '21 Contest 7 P1 - Chika Grids
// Author: Dan Shan
#include <stdio.h>
int scan() {
    int num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
int main() {
    int n=scan(),m=scan();
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j]=scan();
            if(a[i][j]){ // check if failure
                if((i&&a[i-1][j]>=a[i][j])||(j&&a[i][j-1]>=a[i][j])) return printf("-1\n")*0;
                continue;
            }
            if(i&&j){
                if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j]+1;
                else a[i][j]=a[i][j-1]+1;
            }
            else if(i) a[i][j]=a[i-1][j]+1;
            else if(j) a[i][j]=a[i][j-1]+1;
            else a[i][j]=1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d%s",a[i][j],j==m-1?"\n":" ");
        }
    }
}
