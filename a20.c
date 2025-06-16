// A20 Gate
// Author: Dan Shan
#include <stdio.h>
#include <string.h>
int main() {
    char t[] = "0123456789ABCDEF";
    int c;
    scanf("%d",&c);
    for(int i=0;i<c;i++) {
        char n[9];
        scanf("%s", n);
        int ind = strchr(t, n[2]) - t;
        if(ind % 2 == 0) {
            printf("%s\n", n);
        } else {
            char n2[100];
            strcpy(n2, n);
            n2[2] = t[ind - 1];
            printf("%s %s\n", n2, n);
        }
    }
}
