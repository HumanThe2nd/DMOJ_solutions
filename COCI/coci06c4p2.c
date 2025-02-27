// COCI '06 Contest 4 #2 Skener
// Author: Dan Shan
#include <stdio.h>
int main() {
    short r,c,zr,zc;
    scanf("%hd%hd%hd%hd",&r,&c,&zr,&zc);
    char s[c+1];
    for(short i=0;i<r;i++){
        scanf("%s",s);
        for(short l=0;l<zr;l++){
            for(short j=0;j<c;j++){
                for(short k=0;k<zc;k++) printf("%c",s[j]);
            }
            printf("\n");
        }
    }
}
