// MNYC '17: Hurontario
// Author: Dan Shan
// Date: 2024-10-06
// theory: hash both strings from middle to edges and compare
/* Original Hashing Solution
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
*/
// New Z algorithm solution
// Author: HumanThe2nd
// Date: 2025-04-27
#include <stdio.h>
#include <string.h>
#pragma GCC optimize ("Ofast")
int z[20000002];
int main() {
    char s[10000001],p[30000002];
    scanf("%s %s",s,p);
    int n=strlen(s),m=strlen(p),l=0,r=0;
    p[m++]='?'; // seperator
    for(int i=0;i<n;++i){
        p[m+i]=s[i];
    }
    n+=m; // length of combined str
    for(int i=1;i<n;++i){
        if(i>r){
            l=r=i;
            while(r<n&&p[r-l]==p[r]) r++;
            z[i]=r-l; r--;
            continue;
        }
        int k=i-l;
        if(z[k]<r-i+1) z[i]=z[k];
        else{
            l=i;
            while(r<n&&p[r-l]==p[r]) r++;
            z[i]=r-l; r--;
        }
    } p[m-1]='\0';
    for(int i=m;i<n;++i){
        if(z[i]==n-i) {
            for(int j=0;j<i-m;j++) putchar(s[j]);
            puts(p);
            return 0;
        }
    }
    printf("%s",s);
    puts(p);
}
