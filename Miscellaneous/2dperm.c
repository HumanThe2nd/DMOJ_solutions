/*
2-D Permutations
Author: Dan Shan
Date: 2025-01-08
Iterate every cell and update the range of queries they can be used for
The minimum query is the product of the x and y coordinates of the cell
i*j (1 indexed)
The maximum query is the sum of all cells with x or y coord less than the current
This max can be calculated by computing the product of previous columns and rows by their max length
and subtracting the overlaping area.
i*m+j*n-i*j (0 indexed)
(i-1)*m+(j-1)*n-(i-1)*(j-1) (1 indexed)
Precompute each query in O(N*M)
Process each query in O(1)
Time complexity: O(N*M+Q)
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
int scan() {
    int a=0;
    char c=getchar();
    while('0'<=c&&c<='9') a=a*10+c-'0',c = getchar();
    return a;
}
void print(int n) {
    if(!n) putchar_unlocked('0');
    char s[10];
    int i=0;
    while(n>0){
        s[i++]=(n%10)+'0';
        n/=10;
    }
    while (--i >= 0) {
        putchar_unlocked(s[i]);
    }
    putchar_unlocked('\n');
}
int a[25000001];
int main(){
    int n=scan(),m=scan(),q=scan();
    for(int i=1;i<=n;i++){ // iterate every cell and update its greatest and lowest query values
        for(int j=1;j<=m;j++){
            int l=i*j,r=(i-1)*m+(j-1)*n-(i-1)*(j-1);
            a[--l]++; a[r+1]--;
        }
    }
    for(int i=1;i<=n*m;i++) a[i]+=a[i-1]; // diff array -> normal array
    while(q--){ // O(1) Queries
        int qi=scan();
        print(a[--qi]);
    }
}
/*
Brute Force:
O(Q*N*M) check every cell each query
int main() {
    int n=scan(),m=scan(),q=scan();
    while(q--){
        int qi=scan(),c=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int l=(i-1)*m+(j-1)*n-(i-1)*(j-1),r=(n-i)*m+(m-j)*n-(n-i)*(m-j);
                if(l>=qi-1&&r>=n*m-qi) c++;
            }
        }
        printf("%d\n",c);
    }
}*/
*/
