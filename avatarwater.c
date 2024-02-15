// PEG Test '14 - Water
// By: Dan Shan
#include <stdio.h>
int main() {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b&&a>c)printf("%d\n",a-b);
    else if(b>a&&b>c)printf("%d\n",b-a);
    else printf("%d\n",c-a);
}
