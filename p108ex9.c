// BlueBook - Pay
// By: Dan Shan
#include <stdio.h>
int main() {
    short t;
    scanf("%hd",&t);
    while(t--){
        double a;
        int h;
        char tax[2],d[2];
        scanf("%lf %d %s %s",&a,&h,tax,d);
        if(h-40>0)h+=h-40;
        if(tax[0]=='B') a*=0.9;
        else if(tax[0]=='C') a*=0.8;
        else if(tax[0]=='D') a*=0.71;
        else if(tax[0]=='E') a*=0.65;
        printf("%0.2lf\n",a*h-10*(d[0]=='y'));
    }
}
