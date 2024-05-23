// ACM U of T Tryouts C3 A - A Research Project
// By: Dan Shan
// Min and Max
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
	int g=scan();
    while(g--){
        int n=scan(),m=scan(),m2; m2=m;
        while(n-->1){
            int a=scan();
            if(a<m)m=a;
            if(a>m2)m2=a;
        }
        printf("%d %d\n",m,m2);
    }
}
