// Yet Another Contest 3 P1 - Shell Swap Scam
// Author: Dan Shan
// Theory: Fill in all empty for a random execpt the last one
//         find where a ends and b begins and use the unknown to connect the path
//         to waste the extra if a==b find 2 elements that are not a
#include<stdio.h>
int scan() {
    int n=0,a=0;
    char c=getchar_unlocked();
    while (c == ' ' || c == '\n') c = getchar_unlocked();  // ignore whitespaces
    if(c=='-')n=1,c=getchar_unlocked();
    while('0'<=c&&c<='9')a=a*10+c-'0',c=getchar_unlocked();
    return n?-a:a;
}

int main() {
	int n=scan(),m=scan(),a=scan(),b=scan(),f=0,e=0;
    int s[2][m];
    for(int i=0;i<m;i++){ // swap a until the first -1 found
        s[0][i]=scan();
        if(s[0][i]>0)s[1][i]=scan();
        else {
            if(f){
                s[0][e]=1; s[1][e]=2;
            }
            e=i; f=1;
        }
    }
    for(int i=0;i<e;i++){
        if(s[0][i]==a)a=s[1][i]; // swap
        else if(s[1][i]==a)a=s[0][i];
    }
    for(int i=m-1;i>=e;i--){
        if(s[0][i]==b) b=s[1][i];
        else if(s[1][i]==b) b=s[0][i];
    }
    for(int i=0;i<m;i++){
        if(s[0][i]>0) printf("%d %d\n",s[0][i],s[1][i]);
        else{
            if(i==e&&a!=b) printf("%d %d\n",a,b);
            else if(a>2)printf("1 2\n");
            else if(a==2)printf("1 3\n");
            else printf("2 3\n");
        }
        if(i==e)a=b;
    }
}
