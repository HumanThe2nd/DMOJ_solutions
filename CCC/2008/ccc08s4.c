/*
CCC '08 S4 - Twenty-four
Author: Dan Shan
Date: 2025-05-17
Non-Recursive approach

Observation: We can brute force every possible outcome
1. Permutations of arrays: 4! -> 24 
2. Operation Choices: 4^3 (+, -, x, /) 
3. Parenthesis combinations C3 -> 5 (hard coded)
Cases: 24 * 4^3 * 5 = 7680 possible combinations
for each permutations try every combination of operations
Time Complexity : O(1) with constant factor of around 7680
*/
#include <stdio.h>
#pragma GCC optimize ("Ofast")
const int inf=3e4;
inline int d(int a, int b){ // divide (or return 2e6 if not possible)
    if(b&&a%b==0) return a/b;
    return inf;
}
inline int op(int a, int b, int o){ // return a and b with operation o
if(!o) return a+b;
if(o==1) return a*b;
if(o==2) return a-b;
return d(a,b);
}
inline int solve(){
    int a[4],ai[4],mx=0;
        for(int i=0;i<4;i++) scanf("%d",&a[i]);
        for(int i=0;i<4;i++){ // 1st digit
            ai[0]=a[i];
            for(int j=0;j<4;j++){ // 2nd digit
                if(j==i) continue;
                ai[1]=a[j];
                for(int k=0;k<4;k++){ // 3rd digit
                    if(i==k||j==k) continue;
                    ai[2]=a[k];
                    for(int l=0;l<4;l++){ // 4th digit
                        if(i==l||j==l||k==l) continue;
                        ai[3]=a[l]; 
                        for(int i2=0;i2<4;++i2){// op choice
                            for(int j2=0;j2<4;++j2){ // 2nd op choice
                                for(int k2=0;k2<4;++k2){ // 3rd op choice
                                    int ab=op(ai[0],ai[1],i2); 
                                    if(ab==inf) continue;
                                    int abc=op(ab,ai[2],j2);
                                    if(abc==inf) continue;
                                    int abcd=op(abc,ai[3],k2);
                                    if(abcd>0&&abcd<25&&abcd>mx) mx=abcd; // ((a op b) op c) op d

                                    int cd=op(ai[2],ai[3],k2);
                                    if(cd==inf) continue;
                                    int bcd=op(ai[1],cd,j2);
                                    if(bcd==inf) continue;
                                    abcd=op(ai[0],bcd,i2);
                                    if(abcd>0&&abcd<25&&abcd>mx) mx=abcd; // a op (b op (c op d))

                                    int bc=op(ai[1],ai[2],j2);
                                    if(bc==inf) continue;
                                    abc=op(ai[0],bc,i2);
                                    if(abc==inf) continue;
                                    abcd=op(ai[3],abc,k2);
                                    if(abcd>0&&abcd<25&&abcd>mx) mx=abcd; // (a op (b op c)) op d

                                    ab=op(ai[0],ai[1],i2); 
                                    if(ab==inf) continue;
                                    cd=op(ai[2],ai[3],k2);
                                    if(cd==inf) continue;
                                    abcd=op(ab,cd,j2);
                                    if(abcd>0&&abcd<25&&abcd>mx) mx=abcd; // (a op b) op (c op d)

                                    bc=op(ai[1],ai[2],j2); 
                                    if(bc==inf) continue;
                                    bcd=op(bc,ai[3],k2);
                                    if(bcd==inf) continue;
                                    abcd=op(ai[0],bcd,i2);
                                    if(abcd>0&&abcd<25&&abcd>mx) mx=abcd; // a op ((b op c) op d)
                                    
                                    if(mx==24) return 24;
                                }
                            }
                        }
                    }
                }
            }
        }
    return mx;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        printf("%d\n",solve());
    }
}
