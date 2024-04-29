// Mock CCC '22 Contest 2 J1 - Opening Ceremony
// By: Dan Shan
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
    int a=scan(),b=scan(),c=scan();
    int d=scan(),e=scan(),f=scan();
    printf("%d %d\n",d+e+f,a*d+b*e+c*f);

}
