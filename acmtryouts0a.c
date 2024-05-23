// ACM U of T Tryouts C0 A - Max Flow
// By: Dan Shan
// Maximum
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
	int t=scan();
	for(int ti=0;ti<t;ti++){
		int n=scan(), m=scan();
		for(int i=1;i<n;i++){
			int a=scan();
			if(a>m)m=a;
		}
		printf("%d\n",m);
	}
}
