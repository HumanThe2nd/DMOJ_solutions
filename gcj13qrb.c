// Google Code Jam '13 Qualification Round Problem B - Lawnmower
// Author: Dan Shan
// for every cell check if it forms a line with its row or column
// each number must form at least one line with numbers equal to or less than itself
// if any number fails the test the data is invalid
#include <stdio.h>
int main() {
    int t;
    scanf("%d",&t);
    for(int ti=1;ti<=t;ti++){
        int n,m,y=1;
        scanf("%d %d",&n,&m);
        int a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int f=0;
                for(int k=0;k<n;k++){
                    if(a[k][j]>a[i][j]) break;
                    if(k==n-1) f=1;
                }
                if(f) continue;
                for(int k=0;k<m;k++){
                    if(a[i][k]>a[i][j])break;
                    if(k==m-1) f=1;
                }
                if(!f){
                    y=0; break;
                }
            }
            if(!y) break;
        }
        printf("Case #%d: %s\n",ti,y?"YES":"NO");
    }
}
