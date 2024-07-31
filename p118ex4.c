// BlueBook - Times Tables
// Author: Dan Shan
#include <stdio.h>
int main() {
    short n;
    scanf("%hd",&n);
    for(int i=1;i<=n;i++){
        printf("%hd X %hd = %hd\n",n,i,n*i);
    }
}
