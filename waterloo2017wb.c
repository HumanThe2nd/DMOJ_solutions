// Waterloo 2017 Winter B - Vera and LCS
// Author: Dan Shan
// if k is less than the least occuring element or greater than n it is impossible
// find lowest occuring letter l
// find all indexes equal to l and indexes not equal to l
#include<stdio.h>
int alpha[26];
int main() {
    int n,k,m=2e9;
    scanf("%d %d",&n,&k);
    if(k>n) return printf("WRONGANSWER\n")*0;
    char a[n],l; getchar_unlocked();
    for(int i=0;i<n;i++){
        a[i]=getchar_unlocked();
        alpha[a[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(alpha[i]<m){
            m=alpha[i]; l=i+'a';
        }
    }
    if(m>k) return printf("WRONGANSWER\n")*0;
    int extra = k-m;
    for(int i=0;i<n;i++){
        if(a[i]==l)printf("%c",l);
        else if(extra) {
            printf("%c",a[i]);
            extra--;
        }
        else printf("%c",l);
    }
    printf("\n");
}
