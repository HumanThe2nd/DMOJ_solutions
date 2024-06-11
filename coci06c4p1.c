// COCI '06 Contest 4 #1 Sibice
// Author: Dan Shan
// pythagorean's theorem
#include<stdio.h>
#include<math.h>
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
    int n=scan(),w=scan(),h=scan();
    int m=sqrt(w*w+h*h);
    while(n--){
        int ai=scan();
        printf("%s\n",ai>m?"NE":"DA");
    }
}
