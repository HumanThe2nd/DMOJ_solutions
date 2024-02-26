// WC '18 Contest 1 S2 - Essay Generator
// By: Dan Shan
#include <stdio.h>
int main() {
    int w;
    scanf("%d",&w);
    for(int i=0;i<26;i++){
        w--;
        printf("%c%s",'a'+i,w?" ":"\n");
        if(!w)break;
    }
    for(int i=0;i<26;i++){
        if(!w)break;
        for(int j=0;j<26;j++){
            if(!w)break;
            w--;
            printf("%c%c%s",'a'+i,'a'+j,w?" ":"\n");
            if(!w) break;
        }
        if(!w)break;
    }
    for(int i=0;i<26;i++){
        if(!w)break;
        for(int j=0;j<26;j++){
            for(int k=0;k<26;k++){
                w--;
                printf("%c%c%c%s",'a'+i,'a'+j,'a'+k,w?" ":"\n");
                if(!w)break;
            }
            if(!w)break;
        }
    }
}
