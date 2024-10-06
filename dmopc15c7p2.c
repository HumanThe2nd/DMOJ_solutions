// DMOPC '15 Contest 7 P2 - Not a Wall of Text
// Author: Dan Shan
// Date: 2024-10-05
// whitespaces+1
#include <stdio.h>
int main() {
int c=1;
while(1){
    char s=getchar_unlocked();
    if(s=='\n') break;
    if(s==' ')c++;
}
printf("%d\n",c);
}
