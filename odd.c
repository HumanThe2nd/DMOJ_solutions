// The Odd Number
// By: Dan Shan
// Xor trick
#include<stdio.h>
int scan() {
    int n = 0, a = 0;
    char c = getchar_unlocked();
    if (c == '-') n = 1, c = getchar_unlocked();
    while('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar_unlocked();
    return n ? -a : a;
}
int main() {
	int n=scan(),a=scan();
	while(--n){
		int b=scan();
        a^=b;
	}
    printf("%d\n",a);
}
