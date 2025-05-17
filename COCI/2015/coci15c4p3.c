// COCI '15 Contest 4 #3 Deathstar
// By: Dan Shan
// bitwise or each row or col (rows in this code)
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
int main(){
    int n = scan();
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=scan();
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            a[i][0]|=a[i][j];
        }
        printf("%d%s",a[i][0],i==n-1?"\n":" ");
    }
}
