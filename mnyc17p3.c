// MNYC '17: Hurontario
// Author: Dan Shan
// Date: 2024-10-06
// theory: hash both strings from middle to edges and compare
#include <stdio.h>
int main() {
    int l,l2,m=0,o=0;
    long long d=256,p=1e9+7,h=1;
	char s[1000001],s2[1000001];
    for(l=0;l<1000001;l++){
        s[l]=getchar_unlocked();
        if(s[l]==' ') {
            s[l]='\0'; break;
        }
    }
    for(l2=0;l2<1000001;l2++){
        s2[l2]=getchar_unlocked();
        if(s2[l2]=='\n') break;
    }
    if(l2<l) m=l2; // min length
    else m=l;
    long long t1=s[l-1],t2=s2[0];
    for(int i=1;i<m;i++){
        h=(h*d)%p;
        t1=(t1+(s[l-1-i])*h)%p;
        t2=(t2*d+(s2[i]))%p;
        if(t1==t2) o=i+1;
    }
    printf("%s",s);
    for(int i=o;i<l2;i++) putchar(s2[i]);
    putchar('\n');
}
