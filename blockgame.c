// A Block Game
// By: Dan Shan
#include <stdio.h>
int main() {
    int n,k,d;
    double kd;
    scanf("%d %d %d %lf",&n,&k,&d,&kd);
    for(int i=0;i<n;i++){
        int ki,di;
        scanf("%d %d",&ki,&di);
        k+=ki; d+=di;
    }
    if(d==0)printf("stop hacking!\n");
    else printf("%s\n",(double)k/d<kd?"N":"Y");
}
