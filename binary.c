// Binary
// By Dan Shan
// binary using modulus
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int a, c = 0, arr[1000];

        for(int j = 0; j < 1000; j++) {
            arr[j] = 0;
        }

        scanf("%d", &a);

        if(!a) {
            printf("0000\n");
            continue;
        }

        while(a) {
            arr[c] = a % 2;
            c++;
            a /= 2;
        }

        int c2 = c;

        while(c2 % 4 != 0) {
            c2++;
        }

        for(int i = c2 - 1; i >= 0; i--) {
            if(i < c) {
                printf("%d", arr[i]);
            } else {
                printf("0");
            }

            if(i % 4 == 0 && i != 0) {
                printf(" ");
            }
        }

        printf("\n");
    }
}
