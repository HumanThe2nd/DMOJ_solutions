// Title: Divide and Mod
// Author: Dan Shan
// Beware of integer overflow
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
    int n=scan();
    while(n--){
        int a=scan(),b=scan(),c=scan(); c%=a;
        printf("%lld\n",(long long)a*b+c);
    }
}
