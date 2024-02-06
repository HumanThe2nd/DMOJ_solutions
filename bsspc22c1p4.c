// BSSPC '22 P4 - Exec Pieing
// By: Dan Shan
#include <stdio.h>
int main() {
    int n,t,m=0,c=0,i;
    scanf("%d %d",&n,&t);
    for(i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        if(a>m)m=a;
        c+=a;
        if(c-m>t){
            i--; break;
        }
    }
    printf("%d\n",n==i?i-1:i);
}
