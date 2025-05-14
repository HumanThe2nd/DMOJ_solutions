// DMOPC '19 Contest 4 P1 - Valid Strings
// By: Dan Shan
// count open and close brackets
// if close brackets ever greater or ends inequal to opens print no otherwise yes
#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    getchar_unlocked();
    for(int i=0;i<n;i++){
        int b=0;
        while(1){
            char c = getchar_unlocked();
            if(c=='\n') break;
            if(c==')'){
                b--;
                if(b<0) b=1001;
            }
            if(c=='(') b++;
        }
        printf("%s\n",!b?"YES":"NO");
    }
}
