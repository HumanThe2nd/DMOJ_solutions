// COCI '07 Contest 3 #1 Cetiri
// Author: Dan Shan
// sort and casework
#include <stdio.h>
int main(int argc, char *argv[]) {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b){
        int t=a; a=b;
        b=t;
    }
    if(a>c){
        int t=a; a=c;
        c=t;
    }
    if(b>c){
        int t=c; c=b;
        b=t;
    }
    if(c-b==b-a) printf("%d\n",2*c-b);
    else if(c-b==2*(b-a)) printf("%d\n",2*b-a);
    else printf("%d\n",2*b-c);
}
