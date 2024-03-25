// Valentine's Day '19 J3 - Love!
// By: Dan Shan
// subsequence counter
#include <stdio.h>
int main(){
    long long e=0,v=0,o=0,l=0;
    while(1){
        char s = getchar_unlocked();
        if(s==EOF) break;
        if(s=='l') l++;
        else if(s=='o') o+=l;
        else if(s=='v') v+=o;
        else if(s=='e') e+=v;
    }
    printf("%lld\n",e);
}
