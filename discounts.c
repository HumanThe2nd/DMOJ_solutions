// Discerning Discounts
// Author: Dan Shan
#include<stdio.h>
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
int main(int argc, char *argv[]) {
    int n=scan(),t=scan(),c=0;
    while(n--){
        int ci=scan(),di=scan();
        c+=(double)ci*(100-di)/100<=t;
    }
    printf("%d\n",c);
}
