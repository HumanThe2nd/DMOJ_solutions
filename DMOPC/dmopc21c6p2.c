/* 2-D Permutations
 * By: Dan Shan
 * Theory: never need to consider 1s as it's always optimal to take the longest trailing zeros
 * Proof: for any 2 lengths of zeros split by a 1 if the latter is larger,
 * then it's optimal to exclude the first, similarly if the latter is smaller it's not worth including
 * if both segments are equal then it would be the same as taking one of the 2
 */
#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
    return (*(int*)b-*(int*)a);
}
int main() {
    int n,k,l[1000],r=0,c=0;
    scanf("%d %d",&n,&k);
    char s[n+1];
    scanf("%s",s);
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            l[r]=c;
            r++; c=0;
        }
        else c++;
    }
    if(c){
        l[r]=c;
        r++; c=0;
    } if(r<k)k=r;
    qsort(l,r,sizeof(int),cmp);
    for(int i=0;i<k;i++){
        c+=l[i];
    }
    printf("%d\n",c);
}
