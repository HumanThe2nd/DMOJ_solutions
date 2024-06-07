// Triway Cup '18 Summer B - Beautiful Water Pearl
// Author: Dan Shan
// observation: answer is always even as each pair is used twice
// theory: convert to a binary array
// if the and is larger than the or then none are possible -> return 0
// for each digit in the larger number (must be or) if the or does not equal the and
// and the xor is 1 then you can double the number of combinations
// 110: 1101110
// 44:  0101100
// 66:  1000010
#include <stdio.h>
int main() {
	int c,d,e,l=0,l2=0,l3=0,res=1;
    scanf("%d %d %d",&c,&d,&e);
    int s[33],s2[33],s3[33];
    if((c^d)!=e) return printf("0\n")*0;
    while(c){
        s[l]=(c&1);
        c>>=1; l++;
    }
    while(d){
        s2[l2]=(d&1);
        d>>=1; l2++;
    }
    while(e){
        s3[l3]=(e&1);
        e>>=1; l3++;
    }
    while(l2<l){
        s2[l2]=0; l2++;
    }
    while(l3<l){
        s3[l3]=0; l3++;
    }
    for(int i=l-1;i>=0;i--){
        if(s[i]>s2[i]&&s3[i]){
            res<<=1;
        }
    }
    printf("%d\n",res);
}
