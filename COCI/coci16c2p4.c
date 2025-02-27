/*
COCI '16 Contest 2 #4 Prosječni
Author: Dan Shan
Date: 2024-12-26
fill the grid with consecutive numbers by rows and columns
example, n=3:
1 2 3
4 5 6
7 8 9
for even cases, adjust last term to create an average equal to the previous term
apply adjustment to both row and columns using the following formula:

average = sum/n
average = (si+tf)/n, where tf represents the final term and si represents the sum without tf
tf = average*n-si (we set average as the 2nd last term and plug in the variables)

example, n=4
01 02 03 06
07 08 09 12
13 14 15 18
31 32 33 36
special case: n=2 -> impossible
*/
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
    int n;
    scanf("%d",&n);
    if(n==2) return printf("-1\n")*0;
    if(n&1){ // odd
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++) printf("%d ",i*n+j);
            printf("%d\n",(i+1)*n);
        }
        return 0;
    } // even
    int a[n][n],si=0;
    a[0][0]=1;
    for(int i=0;i<n-1;i++){
        if(i) a[i][0]=a[i-1][n-1]+1;
        int si2=a[i][0]; // row sum
        si+=a[i][0]; // column sum
        printf("%d ",a[i][0]);
        for(int j=1;j<n-1;j++){
            a[i][j]=a[i][j-1]+1;
            si2+=a[i][j];
            printf("%d ",a[i][j]); 
        }
        a[i][n-1]=a[i][n-2]*n-si2;
        printf("%d\n",a[i][n-1]);
    }
    a[n-1][0]=a[n-2][0]*n-si;
    int si2=a[n-1][0]; // row sum
    printf("%d ",a[n-1][0]);
    for(int j=1;j<n-1;j++){
        a[n-1][j]=a[n-1][j-1]+1;
        si2+=a[n-1][j];
        printf("%d ",a[n-1][j]);
    }
    printf("%d\n",a[n-1][n-2]*n-si2);
}
